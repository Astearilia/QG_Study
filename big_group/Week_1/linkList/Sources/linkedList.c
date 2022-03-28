#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"
#include"menu.h"

Status InitList(LinkedList* L)								/*初始化结点函数*/
{
	if (*L = (LinkedList)malloc(sizeof(LNode)))		/*新建头结点*/
	{
		(*L)->next = NULL;									/*L结点指向next为空*/
		printf("已初始化完成\n");
		system("pause");
		return SUCCESS;										/*创建成功就会返回SUCCESS*/
	}
	return ERROR;
}

void DestroyList(LinkedList* L)							/*删除链表函数*/
{
	LinkedList temp = *L;									/*用temp来保存当前结点*/
	while ((*L) != NULL)										/*用while循环和free结合temp来释放整个链表*/
	{
		(*L) = (*L)->next;
		free(temp);
		temp = *L;
	}
}

Status InsertList(LNode* p, LNode* q)				/*插入结点函数*/
{
	if(p==NULL||q==NULL)									/*判断两个接入的结点是否为空*/
	{
		fputs("错误,p结点或q结点为空", stderr);
		return ERROR;											/*结点为空返回ERROR*/
	}
	LinkedList temp = p->next;							/*用temp来储存p->next，之后再赋给q->next*/
	p->next = q;
	q->next = temp;
	return SUCCESS;											/*插入成功返回SUCCESS*/
}

Status DeleteList(LNode* p, ElemType* e)
{
	if (p == NULL||p->next==NULL)					/*判断待删除p和p->next是否为空*/
	{
		fputs("删除失败", stderr);
		return ERROR;											/*链表为空返回ERROR*/
	}	
	else
	{
		LinkedList temp = p->next;						/*用temp来临时储存待删除结点*/
		p->next =temp->next;
		*e = temp->data;										/*将temp的值赋给*e*/
		free(temp);												/*释放temp指向的结点*/
		return SUCCESS;										/*删除成功返回SUCCESS*/
	}
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))	/*遍历链表函数*/
{																					/*visit被指定为打印e的值的函数*/
	if (L == NULL || L->next == NULL)							/*判断链表是否为空*/
	{
		fputs("链表为空", stderr);
	}
	else
	{
		LinkedList temp = L->next;									/*用temp来临时遍历链表*/
		while (temp!= NULL)							
		{
			visit(temp->data);												/*调用visit指向的函数*/
			temp = temp->next;
		}
		system("pause");
	}
}

Status SearchList(LinkedList L, ElemType e)					/*查找功能函数*/
{
	if (L == NULL||L->next==NULL)								/*用来判断链表是否为空*/
	{
		fputs("链表为空", stderr);	
	}
	LinkedList temp = L->next;										/*用temp来遍历链表*/
	while (temp!=NULL)
	{
		if (temp->data == e)												/*查找到数据就返回SUCCESS*/
		{
			return SUCCESS;			
		}
		temp = temp->next;
	}
	return ERROR;															/*未找到就会返回ERROR*/
}

Status ReverseList(LinkedList* L)										/*反转链表函数（非递归）*/
{
	if ((*L) == NULL)														/*判断链表是否为空*/
	{
		fputs("链表为空", stderr);
		return ERROR;														/*链表为空，返回ERROR*/
	}
	LinkedList pre = NULL;												/*用pre指向上一个结点*/
	LinkedList cur = (*L)->next;										/*cur指向当前结点*/
	while(cur!=NULL)														/*while循环来修改链表*/
	{
		LinkedList temp = cur->next;									/*用temp存放cur->next*/
		cur->next = pre;													/*cur指向pre*/
		pre = cur;																/*pre前进一个结点*/
		cur = temp;															/*cur也前进一个结点*/
	}
	(*L)->next = pre;														/*L指向新链表结点*/
	printf("完成反转\n");
	return SUCCESS;														/*完成反转，返回SUCCESS*/
}

//LinkedListist* ReverseList(LinkedList* L)						/*这是用递归反转链表的函数*/
//{																					/*我不知道怎么做就上CSDN抄了下来*/
//		if ((*L)==NULL||(*L)->next == NULL)						/*头文件里反转链表的函数返回类型是Status*/
//		{
//			return L;
//		}
//		LinkedList *newHead = ReverseList(L->next));
//		L->next->next = L;
//		L->next = NULL;
//		return newHead;
//}

Status IsLoopList(LinkedList L)										/*判断链表是否成环函数*/
{
	int flag = 0;																/*用flag来判断是否成环*/
	if(L==NULL||L->next==NULL)									/*判断是否成环*/
	{
		fputs("链表为空", stderr);
		return ERROR;
	}
	LinkedList head = L;													/*head是链表的头结点*/
	LinkedList tail = L->next;											/*tail是链表尾结点*/
	while(tail->next!=NULL)											/*while来找到链表尾*/
	{
		tail = tail->next;
		if (tail == head)														/*如果出现tail==head，即是链表成环*/
		{
			flag = 1;															/*成环则设flag为1*/
			break;
		}
	}
	if (flag == 0)																/*用flag来判断是否成环*/
	{
		printf("链表不成环\n");
	}
	else
	{
		printf("链表成环\n");
	}
}

LNode* ReverseEvenList(LinkedList* L)							/*单链表奇偶对换（递归）*/
{
	if ((*L) == NULL||(*L)->next==NULL|| (*L)->next->next == NULL)
	{																				/*判断是否需要返回*/
		return;
	}
	LinkedList pre = (*L)->next;										/*pre即使要交换链表结点组（两个一组）第一个*/
	LinkedList cur = (*L)->next->next;								/*cur是结点组的第二个*/
	LinkedList temp = cur->next;										/*用temp来协助对换*/
	(*L)->next = cur;
	cur->next = pre;
	pre->next = temp;
	ReverseEvenList(&pre);												/*之后再将pre（即是下个链表结点组的头结点）作为参数开始递归*/
	return;																
}

LNode* FindMidNode(LinkedList* L)								/*查找中间结点函数*/
{
	if ((*L) == NULL || (*L)->next == NULL)						/*判断链表是否为空*/
	{
		fputs("链表为空", stderr);
		return NULL;
	}
	LinkedList fast = (*L);													/*用快慢指针法找中点*/
	LinkedList slow = (*L);
	while (fast!= NULL&&fast->next!=NULL)					/*while循环来让fast走向链表尾*/
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("查找成功，其中点值为:%d\n", slow->data);		/*查找成功打印其值*/
	return slow;																/*返回中间结点*/
}