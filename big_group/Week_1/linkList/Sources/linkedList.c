#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"
#include"menu.h"

Status InitList(LinkedList* L)								/*��ʼ����㺯��*/
{
	if (*L = (LinkedList)malloc(sizeof(LNode)))		/*�½�ͷ���*/
	{
		(*L)->next = NULL;									/*L���ָ��nextΪ��*/
		printf("�ѳ�ʼ�����\n");
		system("pause");
		return SUCCESS;										/*�����ɹ��ͻ᷵��SUCCESS*/
	}
	return ERROR;
}

void DestroyList(LinkedList* L)							/*ɾ��������*/
{
	LinkedList temp = *L;									/*��temp�����浱ǰ���*/
	while ((*L) != NULL)										/*��whileѭ����free���temp���ͷ���������*/
	{
		(*L) = (*L)->next;
		free(temp);
		temp = *L;
	}
}

Status InsertList(LNode* p, LNode* q)				/*�����㺯��*/
{
	if(p==NULL||q==NULL)									/*�ж���������Ľ���Ƿ�Ϊ��*/
	{
		fputs("����,p����q���Ϊ��", stderr);
		return ERROR;											/*���Ϊ�շ���ERROR*/
	}
	LinkedList temp = p->next;							/*��temp������p->next��֮���ٸ���q->next*/
	p->next = q;
	q->next = temp;
	return SUCCESS;											/*����ɹ�����SUCCESS*/
}

Status DeleteList(LNode* p, ElemType* e)
{
	if (p == NULL||p->next==NULL)					/*�жϴ�ɾ��p��p->next�Ƿ�Ϊ��*/
	{
		fputs("ɾ��ʧ��", stderr);
		return ERROR;											/*����Ϊ�շ���ERROR*/
	}	
	else
	{
		LinkedList temp = p->next;						/*��temp����ʱ�����ɾ�����*/
		p->next =temp->next;
		*e = temp->data;										/*��temp��ֵ����*e*/
		free(temp);												/*�ͷ�tempָ��Ľ��*/
		return SUCCESS;										/*ɾ���ɹ�����SUCCESS*/
	}
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))	/*����������*/
{																					/*visit��ָ��Ϊ��ӡe��ֵ�ĺ���*/
	if (L == NULL || L->next == NULL)							/*�ж������Ƿ�Ϊ��*/
	{
		fputs("����Ϊ��", stderr);
	}
	else
	{
		LinkedList temp = L->next;									/*��temp����ʱ��������*/
		while (temp!= NULL)							
		{
			visit(temp->data);												/*����visitָ��ĺ���*/
			temp = temp->next;
		}
		system("pause");
	}
}

Status SearchList(LinkedList L, ElemType e)					/*���ҹ��ܺ���*/
{
	if (L == NULL||L->next==NULL)								/*�����ж������Ƿ�Ϊ��*/
	{
		fputs("����Ϊ��", stderr);	
	}
	LinkedList temp = L->next;										/*��temp����������*/
	while (temp!=NULL)
	{
		if (temp->data == e)												/*���ҵ����ݾͷ���SUCCESS*/
		{
			return SUCCESS;			
		}
		temp = temp->next;
	}
	return ERROR;															/*δ�ҵ��ͻ᷵��ERROR*/
}

Status ReverseList(LinkedList* L)										/*��ת���������ǵݹ飩*/
{
	if ((*L) == NULL)														/*�ж������Ƿ�Ϊ��*/
	{
		fputs("����Ϊ��", stderr);
		return ERROR;														/*����Ϊ�գ�����ERROR*/
	}
	LinkedList pre = NULL;												/*��preָ����һ�����*/
	LinkedList cur = (*L)->next;										/*curָ��ǰ���*/
	while(cur!=NULL)														/*whileѭ�����޸�����*/
	{
		LinkedList temp = cur->next;									/*��temp���cur->next*/
		cur->next = pre;													/*curָ��pre*/
		pre = cur;																/*preǰ��һ�����*/
		cur = temp;															/*curҲǰ��һ�����*/
	}
	(*L)->next = pre;														/*Lָ����������*/
	printf("��ɷ�ת\n");
	return SUCCESS;														/*��ɷ�ת������SUCCESS*/
}

//LinkedListist* ReverseList(LinkedList* L)						/*�����õݹ鷴ת����ĺ���*/
//{																					/*�Ҳ�֪����ô������CSDN��������*/
//		if ((*L)==NULL||(*L)->next == NULL)						/*ͷ�ļ��ﷴת����ĺ�������������Status*/
//		{
//			return L;
//		}
//		LinkedList *newHead = ReverseList(L->next));
//		L->next->next = L;
//		L->next = NULL;
//		return newHead;
//}

Status IsLoopList(LinkedList L)										/*�ж������Ƿ�ɻ�����*/
{
	int flag = 0;																/*��flag���ж��Ƿ�ɻ�*/
	if(L==NULL||L->next==NULL)									/*�ж��Ƿ�ɻ�*/
	{
		fputs("����Ϊ��", stderr);
		return ERROR;
	}
	LinkedList head = L;													/*head�������ͷ���*/
	LinkedList tail = L->next;											/*tail������β���*/
	while(tail->next!=NULL)											/*while���ҵ�����β*/
	{
		tail = tail->next;
		if (tail == head)														/*�������tail==head����������ɻ�*/
		{
			flag = 1;															/*�ɻ�����flagΪ1*/
			break;
		}
	}
	if (flag == 0)																/*��flag���ж��Ƿ�ɻ�*/
	{
		printf("�����ɻ�\n");
	}
	else
	{
		printf("����ɻ�\n");
	}
}

LNode* ReverseEvenList(LinkedList* L)							/*��������ż�Ի����ݹ飩*/
{
	if ((*L) == NULL||(*L)->next==NULL|| (*L)->next->next == NULL)
	{																				/*�ж��Ƿ���Ҫ����*/
		return;
	}
	LinkedList pre = (*L)->next;										/*pre��ʹҪ�����������飨����һ�飩��һ��*/
	LinkedList cur = (*L)->next->next;								/*cur�ǽ����ĵڶ���*/
	LinkedList temp = cur->next;										/*��temp��Э���Ի�*/
	(*L)->next = cur;
	cur->next = pre;
	pre->next = temp;
	ReverseEvenList(&pre);												/*֮���ٽ�pre�������¸����������ͷ��㣩��Ϊ������ʼ�ݹ�*/
	return;																
}

LNode* FindMidNode(LinkedList* L)								/*�����м��㺯��*/
{
	if ((*L) == NULL || (*L)->next == NULL)						/*�ж������Ƿ�Ϊ��*/
	{
		fputs("����Ϊ��", stderr);
		return NULL;
	}
	LinkedList fast = (*L);													/*�ÿ���ָ�뷨���е�*/
	LinkedList slow = (*L);
	while (fast!= NULL&&fast->next!=NULL)					/*whileѭ������fast��������β*/
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("���ҳɹ������е�ֵΪ:%d\n", slow->data);		/*���ҳɹ���ӡ��ֵ*/
	return slow;																/*�����м���*/
}