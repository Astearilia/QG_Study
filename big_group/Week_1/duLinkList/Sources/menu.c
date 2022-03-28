#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"menu.h"
#include"duLinkedList.h"

void scanNum(int* num)											/*����ָ��or��ֵ����*/
{
	int flag = 1;															/*flag��ʾ�����Ƿ�Ϸ�*/
	do {
		flag = 1;
		if ((scanf("%d", num)) != 1)									/*ʹ��if+scanf+do-whileѭ����ȷ������Ϸ�*/
		{
			while (getchar() != '\n');
			flag = 0;
			fputs("���벻�Ϸ�,��������������\n", stderr);
		}
	} while (flag != 1);
}

void printmenu()														/*���Ǵ�ӡ���˵�����*/
{
	printf("=== ˫������ADT ===\n");
	printf("====1-�����ձ�====\n");
	printf("====2-ɾ������====\n");
	printf("====3-����Ԫ��====\n");
	printf("====4-ɾ��Ԫ��====\n");
	printf("====5-��������====\n");
	printf("====6-�жϳɻ�====\n");
	printf("====7-��ת����====\n");
	printf("====8-  �˳�    ====\n");
}

void printElem(ElemType e)										/*�����������ָ�뼴ָ����*/
{
	printf("%d->", e);													/*��ӡ��Ԫ��ֵ*/
}

void InitList_DuL_Menu(DuLinkedList *List)					/*��ʼ������˵�*/
{
	if (InitList_DuL(List))												/*�÷���ֵ�ж��Ƿ�ɹ�*/
	{
		printf("��������ɹ�!\n");
		system("pause");
		return;
	}
	else
	{
		fputs("��������ʧ��!\n",stderr);
		return;
	}
}

void InsertListMenu(DuLinkedList* L)							/*���������㺯��*/
{
	int flag = 0;															/*flag����¼�Ƿ����ɹ�*/
	printf("������Ҫ����Ľ�����(�ձ�ǿ��Ϊ0):");		
	int ord0;																/*ord����¼�������������е����*/
	scanNum(&ord0);													
	printf("��������Ҫ���������:");								/*newHead�Ǵ������½��*/
	DuLinkedList newHead = (DuLinkedList)malloc(sizeof(DuLNode));
	scanNum(&(newHead->data));
	newHead->prior = newHead->next = NULL;
	DuLinkedList temp = (*L);										/*temp���ҵ�ָ������λ��*/
	for(int i=0;i<ord0&&temp->next!=NULL;i++)       /*ѭ���ҵ�ָ��λ��*/
	{
		temp = temp->next;
	}
	if ((*L)->next == NULL)											/*ȷ��ͷ������*/
	{
		InsertAfterList_DuL((*L), newHead);
		return;
	}
	printf("��������Ҫǰ�廹�Ǻ��\n");
	printf("0��ʾǰ�壬1��ʾ���\n");
	printf("��ͷ��βǿ�ƺ��\n");
	int ord1;																/*ord����ָʾʹ��ǰ��or���*/
	scanNum(&ord1);	
	if (ord1 == 1)
	{
		InsertAfterList_DuL(temp, newHead);					/*��庯��*/
	}
	else
	{
		InsertBeforeList_DuL(temp, newHead);				/*ǰ�庯��*/
	}
}

void DeleteListMenu(DuLinkedList *L)						/*ɾ��Ԫ�ز˵�*/
{
	TraverseList_DuL(*L, printElem);								/*��ӡ��������*/
	printf("��������Ҫɾ���Ľ��Ԫ�����\n");
	int ord = 0;															/*ord����¼��Ҫɾ���Ľ�����*/
	scanNum(&ord);
	DuLinkedList temp = (*L);
	for(int i = 1;i< ord&& temp != NULL; i++)				/*forѭ�����ҵ���ɾ�����*/
	{
		temp = temp->next;
	}
	if (temp == NULL)													/*�ж��Ƿ���Խ���ɾ��*/
	{
		fputs("�����Ź���\n", stderr);
		return;
	}
	ElemType e;															/*e������ɾ�����Ԫ��ֵ*/
	if (DeleteList_DuL(temp, &e))									/*��ɾ����������ֵ���ж��Ƿ�ɾ���ɹ�*/
	{
		printf("ɾ���ɹ���ɾ��Ԫ�ص�ֵΪ:%d", e);			/*�ɹ����ӡɾ����Ԫ��ֵ*/
		system("pause");
		return;
	}
	else
	{
		fputs("ɾ��ʧ��\n", stderr);
		return;
	}
}

void TraverseListDuLMenu(DuLinkedList* List)			/*����������*/
{
	TraverseList_DuL((*List), printElem);						/*����TraverseList_DuL����������*/
	putchar('\n');															/*��ָ��TraverseList_DuL�����б��е�*/
	system("pause");													/*����ָ��ΪprintElem����ӡ��������*/
	return;
}

void IsLoopList(DuLinkedList List)								/*�ж������Ƿ�ɻ�*/
{
	int flag = 0;															/*flag������¼�Ƿ�ɻ�*/
	DuLinkedList slow = List;										/*����ָ�뷨���ж�*/
	DuLinkedList fast = List;
	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)													/*ͨ���ж�fast�Ƿ���slowָ��ͬһ��*/
		{																		/*�������ж��Ƿ�ɻ�*/
			flag = 1;														/*�ɻ�����flagΪ1*/
			break;
		}
	}
	if (flag == 0)															/*flag���ж��Ƿ�ɻ�*/
	{
		printf("�����ɻ�\n");
		system("pause");
		return;
	}
	else
	{
		printf("����ɻ�\n");
		return;
	}
}

void ReverseList(DuLinkedList* L)								/*��ת������*/
{
	DuLinkedList pre = NULL;										/*pre�ǵ�ǰ������һ�����*/
	DuLinkedList cur = (*L)->next;								/*cur�ǵ�ǰ���*/
	while(cur!=NULL)													/*������������*/
	{
		DuLinkedList temp = cur->next;						/*temp����¼��һ�����ĵ�ַ*/
		cur->next = pre;												/*�𽥷�ת��������*/
		cur->prior = temp;
		pre = cur;
		cur = temp;
	}
	(*L)->next = pre;													/*ͷ���ָ��������ı�ͷ*/
}