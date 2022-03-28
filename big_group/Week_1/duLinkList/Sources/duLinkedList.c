#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

Status InitList_DuL(DuLinkedList* L)							/*初始化链表函数*/
{
	if (*L = (DuLinkedList)malloc(sizeof(DuLNode)))		/*创建新结点*/
	{
		(*L)->data = -1;													/*赋值*/
		(*L)->prior = NULL;											/*修改指针域*/
		(*L)->next = NULL;
		return SUCCESS;												/*成功，返回SUCCSESS*/
	}
	else
	{
		return ERROR;													/*失败，返回ERROR*/
	}
}

void DestroyList_DuL(DuLinkedList* L)						/*删除链表函数*/
{
	DuLinkedList temp = *L;										/*temp协助遍历链表*/
	while (temp != NULL)											/*循环遍历链表*/
	{																			
		(*L) = (*L)->next;
		free(temp);														/*free依次释放结点*/
		temp = (*L);
	}
}

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)			/*前插入结点函数*/
{
	if(p==NULL||q==NULL)														/*判断是否为空*/
	{
		return ERROR;																/*出错，返回ERROR*/
	}
	DuLinkedList temp = p->prior;											/*temp用于储存插入位点的前一个*/
	p->prior = q;																	/*结点地址*/
	q->next = p;
	q->prior = temp;
	temp->next = q;
	return SUCCESS;																/*成功，返回SUCCESS*/
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)			/*后插入结点函数*/
{
	if (p == NULL || q == NULL)												/*判断结点是否为空*/
	{
		return ERROR;																/*为空则返回ERROR*/
	}
	DuLinkedList temp = p->next;											/*temp用于储存插入位点的下一个*/
	if (temp == NULL)																/*结点数据*/
	{																		
		p->next = q;																	/*这个if是为了解决插入结点为*/
		q->prior = p;																/*链表尾部的可能*/
		return SUCCESS;															/*插入成功返回SUCCESS*/
	}
	p->next = q;																		/*这里插入位点不是链表尾部*/
	q->prior = p;
	q->next = temp;
	temp->prior = q;
	return SUCCESS;																/*插入成功返回SUCCESS*/
}

Status DeleteList_DuL(DuLNode* p, ElemType* e)					/*删除结点函数*/
{
	if (p == NULL || p->next == NULL)									/*判断是否为空*/
	{
		return ERROR;																/*为空返回错误*/
	}
	DuLinkedList temp = p->next;											/*temp用于临时储存删除结点*/
	*e = temp->data;																/*将temp的值返回给e*/
	p->next = p->next->next;
	free(temp);
	if (p->next != NULL)															/*解决删除后p->next为NULL的情况*/
	{
		p->next->prior = p;											
	}
	return SUCCESS;																/*成功删除返回SUCCESS*/
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{																							/*遍历链表函数*/
	if (L == NULL || L->next == NULL)									/*函数参数里的函数指针在被调用时*/
	{																						/*被指定为打印e的值*/
		fputs("链表为空", stderr);
		return;																			/*链表为空，返回*/
	}
	DuLinkedList temp = L->next;											/*temp协助遍历链表*/
	while (temp != NULL)														
	{
		visit(temp->data);
		temp = temp->next;
	}
	return;																				/*完成遍历，返回*/
}