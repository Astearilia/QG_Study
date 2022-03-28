#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"duLinkedList.h"
#include"menu.h"

int main()
{
	int ord = 0;												/*用ord来接收指令*/
	DuLinkedList List=NULL;							/*双向链表*/
	do
	{
		printmenu();											/*打印主菜单*/
		scanNum(&ord);									/*确保输入合法*/
		switch (ord)											/*选择菜单*/
		{
			case 1:
			{
				InitList_DuL(&List);							/*初始化*/
				break;
			}
			case 2:
			{
				DestroyList_DuL(&List);					/*删除链表*/
				break;
			}
			case 3:
			{
				InsertListMenu(&List);					/*插入元素*/
				break;
			}
			case 4:
			{
				DeleteListMenu(&List);					/*删除元素*/
				break;
			}
			case 5:
			{
				TraverseListDuLMenu(&List);			/*遍历链表*/
				break;
			}
			case 6:
			{
				IsLoopList(List);								/*判断成环*/
				break;
			}
			case 7:
			{
				ReverseList(&List);							/*链表反转*/
				break;
			}
			case 8:
			{
				break;
			}
			default:
			{
				fputs("请输入正确序号", stderr);
				break;
			}
		}
	} while (ord != 8);
}