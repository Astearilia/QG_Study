#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"menu.h"
#include"duLinkedList.h"

void scanNum(int* num)											/*接收指令or数值函数*/
{
	int flag = 1;															/*flag表示输入是否合法*/
	do {
		flag = 1;
		if ((scanf("%d", num)) != 1)									/*使用if+scanf+do-while循环来确保输入合法*/
		{
			while (getchar() != '\n');
			flag = 0;
			fputs("输入不合法,请重新输入数据\n", stderr);
		}
	} while (flag != 1);
}

void printmenu()														/*这是打印主菜单函数*/
{
	printf("=== 双向链表ADT ===\n");
	printf("====1-构建空表====\n");
	printf("====2-删除链表====\n");
	printf("====3-插入元素====\n");
	printf("====4-删除元素====\n");
	printf("====5-遍历链表====\n");
	printf("====6-判断成环====\n");
	printf("====7-反转链表====\n");
	printf("====8-  退出    ====\n");
}

void printElem(ElemType e)										/*遍历函数里的指针即指向这*/
{
	printf("%d->", e);													/*打印单元素值*/
}

void InitList_DuL_Menu(DuLinkedList *List)					/*初始化链表菜单*/
{
	if (InitList_DuL(List))												/*用返回值判断是否成功*/
	{
		printf("创建链表成功!\n");
		system("pause");
		return;
	}
	else
	{
		fputs("创建链表失败!\n",stderr);
		return;
	}
}

void InsertListMenu(DuLinkedList* L)							/*插入链表结点函数*/
{
	int flag = 0;															/*flag来记录是否插入成功*/
	printf("请输入要插入的结点序号(空表强制为0):");		
	int ord0;																/*ord来记录插入结点在链表中的序号*/
	scanNum(&ord0);													
	printf("请输入想要插入的数据:");								/*newHead是待插入新结点*/
	DuLinkedList newHead = (DuLinkedList)malloc(sizeof(DuLNode));
	scanNum(&(newHead->data));
	newHead->prior = newHead->next = NULL;
	DuLinkedList temp = (*L);										/*temp来找到指定插入位置*/
	for(int i=0;i<ord0&&temp->next!=NULL;i++)       /*循环找到指定位置*/
	{
		temp = temp->next;
	}
	if ((*L)->next == NULL)											/*确保头结点插入*/
	{
		InsertAfterList_DuL((*L), newHead);
		return;
	}
	printf("请输入想要前插还是后插\n");
	printf("0表示前插，1表示后插\n");
	printf("表头表尾强制后插\n");
	int ord1;																/*ord用于指示使用前插or后插*/
	scanNum(&ord1);	
	if (ord1 == 1)
	{
		InsertAfterList_DuL(temp, newHead);					/*后插函数*/
	}
	else
	{
		InsertBeforeList_DuL(temp, newHead);				/*前插函数*/
	}
}

void DeleteListMenu(DuLinkedList *L)						/*删除元素菜单*/
{
	TraverseList_DuL(*L, printElem);								/*打印整个链表*/
	printf("请输入想要删除的结点元素序号\n");
	int ord = 0;															/*ord来记录想要删除的结点序号*/
	scanNum(&ord);
	DuLinkedList temp = (*L);
	for(int i = 1;i< ord&& temp != NULL; i++)				/*for循环来找到待删除序号*/
	{
		temp = temp->next;
	}
	if (temp == NULL)													/*判断是否可以进行删除*/
	{
		fputs("结点序号过大\n", stderr);
		return;
	}
	ElemType e;															/*e来储存删除后的元素值*/
	if (DeleteList_DuL(temp, &e))									/*用删除函数返回值来判断是否删除成功*/
	{
		printf("删除成功，删除元素的值为:%d", e);			/*成功则打印删除的元素值*/
		system("pause");
		return;
	}
	else
	{
		fputs("删除失败\n", stderr);
		return;
	}
}

void TraverseListDuLMenu(DuLinkedList* List)			/*遍历链表函数*/
{
	TraverseList_DuL((*List), printElem);						/*调用TraverseList_DuL来遍历链表*/
	putchar('\n');															/*且指定TraverseList_DuL参数列表中的*/
	system("pause");													/*函数指针为printElem，打印单个数据*/
	return;
}

void IsLoopList(DuLinkedList List)								/*判断链表是否成环*/
{
	int flag = 0;															/*flag用来记录是否成环*/
	DuLinkedList slow = List;										/*快慢指针法来判断*/
	DuLinkedList fast = List;
	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)													/*通过判断fast是否会和slow指向同一个*/
		{																		/*数据来判断是否成环*/
			flag = 1;														/*成环则设flag为1*/
			break;
		}
	}
	if (flag == 0)															/*flag来判断是否成环*/
	{
		printf("链表不成环\n");
		system("pause");
		return;
	}
	else
	{
		printf("链表成环\n");
		return;
	}
}

void ReverseList(DuLinkedList* L)								/*反转链表函数*/
{
	DuLinkedList pre = NULL;										/*pre是当前结点的上一个结点*/
	DuLinkedList cur = (*L)->next;								/*cur是当前结点*/
	while(cur!=NULL)													/*遍历整个链表*/
	{
		DuLinkedList temp = cur->next;						/*temp来记录下一个结点的地址*/
		cur->next = pre;												/*逐渐反转整个链表*/
		cur->prior = temp;
		pre = cur;
		cur = temp;
	}
	(*L)->next = pre;													/*头结点指向新链表的表头*/
}