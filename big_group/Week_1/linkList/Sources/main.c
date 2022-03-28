#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include"menu.h"
#include"linkedList.h"

int main() 
{
	LinkedList List=NULL;		/*List既是此程序的链表*/
	int ord = 0;						/*ord表示指令*/
	do									/*采用do-while循环来让用户多次使用*/
	{
		printmenu();					/*打印主菜单*/
		scanNum(&ord);			/*用scanNum函数来确保输入合法*/
		switch (ord)					/*switch来进入指定功能函数*/
		{
		    case 1:
			{
				InitList(&List);
				break;
			}
			case 2:
			{
				DestroyList(&List);
				break;
			}
			case 3:
			{
				InserListMenu(&List);
				break;
			}
			case 4:
			{
				DeleteListMenu(&List);
				break;
			}
			case 5:
			{
				TraverseList(List, printElem);
				break;
			}
			case 6:
			{
				SearchListMenu(&List);
				system("pause");
				break;
			}
			case 7:
			{
				ReverseList(&List);
				break;
			}
			case 8:
			{
				IsLoopList(List);
				break;
			}
			case 9:
			{
				ReverseEvenList(&List);
				printf("完成转换\n");
				break;
			}
			case 10:
			{
				FindMidNode(&List);
				break;
			}
			case 11:
				break;
			default:
			{
				fputs("请输入正确指令!\n", stderr);
				system("pause");
				break;
			}
		}
	} while (ord != 11);
}