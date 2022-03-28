#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include"menu.h"
#include"linkedList.h"

int main() 
{
	LinkedList List=NULL;		/*List���Ǵ˳��������*/
	int ord = 0;						/*ord��ʾָ��*/
	do									/*����do-whileѭ�������û����ʹ��*/
	{
		printmenu();					/*��ӡ���˵�*/
		scanNum(&ord);			/*��scanNum������ȷ������Ϸ�*/
		switch (ord)					/*switch������ָ�����ܺ���*/
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
				printf("���ת��\n");
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
				fputs("��������ȷָ��!\n", stderr);
				system("pause");
				break;
			}
		}
	} while (ord != 11);
}