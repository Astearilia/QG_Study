#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "menu.h"
#include"linkedList.h"

void printmenu()														/*���Ǵ�ӡ���˵�����*/
{
	printf("====������ADT====\n");
	printf("====1-�����ձ�====\n");
	printf("====2-ɾ������====\n");
	printf("====3-����Ԫ��====\n");
	printf("====4-ɾ��Ԫ��====\n");
	printf("====5-��������====\n");
	printf("====6-����Ԫ��====\n");
	printf("====7-��ת����====\n");
	printf("====8-�жϳɻ�====\n");
	printf("====9-��ת��ż====\n");
	printf("====10-���е�  ====\n");
	printf("====11- �˳�     ====\n");
}

void printElem(ElemType e)										/*��ӡ�����ElemType��ֵ*/
{																				/*��TraverseList��ĺ���ָ��������*/
	printf("%d->", e);
}

void scanNum(int* num)											/*����ָ��or��ֵ����*/
{
	int flag = 1;															/*flag��ʾ�����Ƿ�Ϸ�*/
	do {
		flag = 1;
		if ((scanf("%d", num)) != 1)									/*ʹ��if+scanf+do-whileѭ����ȷ������Ϸ�*/
		{
			while (getchar() != '\n');										
			flag = 0;
			fputs("���벻�Ϸ�,������������\n", stderr);
		}
	} while (flag!=1);
}

void InserListMenu(LinkedList *List)							/*��ӡ�����㹦�ܲ˵�*/
{
	printf("��������Ҫ�������ݵĽ�����(��Ϊ�ձ�������1)\n");		
	int ord = 0;															/*ord����ָ������������е����*/
	scanNum(&ord);													/*ͨ��ord����ȷ��������λ������λ��*/
	printf("��������Ҫ����������:");							/*�½����*/
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
	if (temp == NULL&&ord!=1) /*����&&ord=1��Ϊ���������ڽ���ͷ���ʱҲ���Բ�������*/
	{
		fputs("�����Ź���\n", stderr);
		return;
	}
	else
	{
		InsertList(temp,newNode);									/*����InsertList����*/
		printf("����ɹ�\n");
		return;
	}
}

void DeleteListMenu(LinkedList* List)							/*ɾ�����ܲ˵�*/
{
	if ((*List) == NULL)												/*�ж������Ƿ�Ϊ��*/
	{
		fputs("��Ϊ��", stderr);
		return;
	}
	TraverseList(*List, printElem);									/*��ʾ�������ݣ����û�ѡ��ɾ��������*/
	printf("��������Ҫɾ���Ľ��Ԫ�����:");
	int ord;																	/*��ord��ʾ��ɾ������������е����*/
	scanNum(&ord);
	ElemType e;
	LinkedList temp = *List;
	for (int i =1; i < ord; i++)										/*ʹ��ѭ���ҵ�ָ��λ��*/
	{
		temp = temp->next;
		if (temp == NULL)												/*if���ж�temp�Ƿ����*/
		{
			fputs("�����Ź���\n", stderr);
			return;
		}
	}
	if (DeleteList(temp, &e))											/*����DeleteList���÷���ֵ�ж��Ƿ�ɾ���ɹ�*/
	{
		printf("ɾ���ɹ���ɾ����Ԫ����%d\n", e);
		system("pause");
		return;
	}
}

void SearchListMenu(LinkedList *List)							/*�����������ݵĲ˵�����*/
{
	printf("��������Ҫ���ҵ�����:");
	ElemType target;													/*target���ǲ��ҵ�����ֵ*/
	scanNum(&target);
	if (SearchList(*List, target))										/*��SearchList��������ֵ���ж��Ƿ���ҳɹ�*/
	{
		printf("���ҵ����� %d\n", target);
	}
	else
	{
		printf("δ���ҵ����� %d\n", target);
	}
}