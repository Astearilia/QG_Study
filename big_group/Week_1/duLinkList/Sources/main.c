#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"duLinkedList.h"
#include"menu.h"

int main()
{
	int ord = 0;												/*��ord������ָ��*/
	DuLinkedList List=NULL;							/*˫������*/
	do
	{
		printmenu();											/*��ӡ���˵�*/
		scanNum(&ord);									/*ȷ������Ϸ�*/
		switch (ord)											/*ѡ��˵�*/
		{
			case 1:
			{
				InitList_DuL(&List);							/*��ʼ��*/
				break;
			}
			case 2:
			{
				DestroyList_DuL(&List);					/*ɾ������*/
				break;
			}
			case 3:
			{
				InsertListMenu(&List);					/*����Ԫ��*/
				break;
			}
			case 4:
			{
				DeleteListMenu(&List);					/*ɾ��Ԫ��*/
				break;
			}
			case 5:
			{
				TraverseListDuLMenu(&List);			/*��������*/
				break;
			}
			case 6:
			{
				IsLoopList(List);								/*�жϳɻ�*/
				break;
			}
			case 7:
			{
				ReverseList(&List);							/*����ת*/
				break;
			}
			case 8:
			{
				break;
			}
			default:
			{
				fputs("��������ȷ���", stderr);
				break;
			}
		}
	} while (ord != 8);
}