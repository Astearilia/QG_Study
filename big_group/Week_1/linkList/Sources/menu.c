#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "menu.h"
#include"linkedList.h"

void printmenu()														/*这是打印主菜单函数*/
{
	printf("====单链表ADT====\n");
	printf("====1-构建空表====\n");
	printf("====2-删除链表====\n");
	printf("====3-插入元素====\n");
	printf("====4-删除元素====\n");
	printf("====5-遍历链表====\n");
	printf("====6-查找元素====\n");
	printf("====7-反转链表====\n");
	printf("====8-判断成环====\n");
	printf("====9-反转奇偶====\n");
	printf("====10-找中点  ====\n");
	printf("====11- 退出     ====\n");
}

void printElem(ElemType e)										/*打印传入的ElemType数值*/
{																				/*在TraverseList里的函数指针就是这个*/
	printf("%d->", e);
}

void scanNum(int* num)											/*接收指令or数值函数*/
{
	int flag = 1;															/*flag表示输入是否合法*/
	do {
		flag = 1;
		if ((scanf("%d", num)) != 1)									/*使用if+scanf+do-while循环来确保输入合法*/
		{
			while (getchar() != '\n');										
			flag = 0;
			fputs("输入不合法,重新输入数据\n", stderr);
		}
	} while (flag!=1);
}

void InserListMenu(LinkedList *List)							/*打印插入结点功能菜单*/
{
	printf("请输入想要插入数据的结点序号(若为空表请输入1)\n");		
	int ord = 0;															/*ord既是指定结点在链表中的序号*/
	scanNum(&ord);													/*通过ord‘来确定插入结点位于链表位置*/
	printf("请输入想要插入结点数据:");							/*新建结点*/
	int num =0 ;
	scanNum(&num);
	LinkedList newNode = (LinkedList)malloc(sizeof(LNode));
	newNode->data = num;
	newNode->next = NULL;
	LinkedList temp = (*List);
	for(int i = 1; i < ord&&temp!=NULL; i++) 
	{
		temp = temp->next;
	}
	if (temp == NULL&&ord!=1) /*这里&&ord=1是为了让链表在仅有头结点时也可以插入数据*/
	{
		fputs("结点序号过大\n", stderr);
		return;
	}
	else
	{
		InsertList(temp,newNode);									/*调用InsertList函数*/
		printf("插入成功\n");
		return;
	}
}

void DeleteListMenu(LinkedList* List)							/*删除功能菜单*/
{
	if ((*List) == NULL)												/*判断链表是否为空*/
	{
		fputs("表为空", stderr);
		return;
	}
	TraverseList(*List, printElem);									/*显示所有数据，让用户选择删除结点序号*/
	printf("请输入想要删除的结点元素序号:");
	int ord;																	/*用ord表示待删除结点在链表中的序号*/
	scanNum(&ord);
	ElemType e;
	LinkedList temp = *List;
	for (int i =1; i < ord; i++)										/*使用循环找到指定位点*/
	{
		temp = temp->next;
		if (temp == NULL)												/*if来判断temp是否过大*/
		{
			fputs("结点序号过大\n", stderr);
			return;
		}
	}
	if (DeleteList(temp, &e))											/*调用DeleteList，用返回值判断是否删除成功*/
	{
		printf("删除成功，删除的元素是%d\n", e);
		system("pause");
		return;
	}
}

void SearchListMenu(LinkedList *List)							/*查找链表数据的菜单函数*/
{
	printf("请输入想要查找的数据:");
	ElemType target;													/*target即是查找的数据值*/
	scanNum(&target);
	if (SearchList(*List, target))										/*用SearchList函数返回值来判断是否查找成功*/
	{
		printf("已找到数据 %d\n", target);
	}
	else
	{
		printf("未查找到数据 %d\n", target);
	}
}