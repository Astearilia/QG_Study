#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

Status InitList_DuL(DuLinkedList* L)							/*��ʼ��������*/
{
	if (*L = (DuLinkedList)malloc(sizeof(DuLNode)))		/*�����½��*/
	{
		(*L)->data = -1;													/*��ֵ*/
		(*L)->prior = NULL;											/*�޸�ָ����*/
		(*L)->next = NULL;
		return SUCCESS;												/*�ɹ�������SUCCSESS*/
	}
	else
	{
		return ERROR;													/*ʧ�ܣ�����ERROR*/
	}
}

void DestroyList_DuL(DuLinkedList* L)						/*ɾ��������*/
{
	DuLinkedList temp = *L;										/*tempЭ����������*/
	while (temp != NULL)											/*ѭ����������*/
	{																			
		(*L) = (*L)->next;
		free(temp);														/*free�����ͷŽ��*/
		temp = (*L);
	}
}

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)			/*ǰ�����㺯��*/
{
	if(p==NULL||q==NULL)														/*�ж��Ƿ�Ϊ��*/
	{
		return ERROR;																/*��������ERROR*/
	}
	DuLinkedList temp = p->prior;											/*temp���ڴ������λ���ǰһ��*/
	p->prior = q;																	/*����ַ*/
	q->next = p;
	q->prior = temp;
	temp->next = q;
	return SUCCESS;																/*�ɹ�������SUCCESS*/
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)			/*������㺯��*/
{
	if (p == NULL || q == NULL)												/*�жϽ���Ƿ�Ϊ��*/
	{
		return ERROR;																/*Ϊ���򷵻�ERROR*/
	}
	DuLinkedList temp = p->next;											/*temp���ڴ������λ�����һ��*/
	if (temp == NULL)																/*�������*/
	{																		
		p->next = q;																	/*���if��Ϊ�˽��������Ϊ*/
		q->prior = p;																/*����β���Ŀ���*/
		return SUCCESS;															/*����ɹ�����SUCCESS*/
	}
	p->next = q;																		/*�������λ�㲻������β��*/
	q->prior = p;
	q->next = temp;
	temp->prior = q;
	return SUCCESS;																/*����ɹ�����SUCCESS*/
}

Status DeleteList_DuL(DuLNode* p, ElemType* e)					/*ɾ����㺯��*/
{
	if (p == NULL || p->next == NULL)									/*�ж��Ƿ�Ϊ��*/
	{
		return ERROR;																/*Ϊ�շ��ش���*/
	}
	DuLinkedList temp = p->next;											/*temp������ʱ����ɾ�����*/
	*e = temp->data;																/*��temp��ֵ���ظ�e*/
	p->next = p->next->next;
	free(temp);
	if (p->next != NULL)															/*���ɾ����p->nextΪNULL�����*/
	{
		p->next->prior = p;											
	}
	return SUCCESS;																/*�ɹ�ɾ������SUCCESS*/
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{																							/*����������*/
	if (L == NULL || L->next == NULL)									/*����������ĺ���ָ���ڱ�����ʱ*/
	{																						/*��ָ��Ϊ��ӡe��ֵ*/
		fputs("����Ϊ��", stderr);
		return;																			/*����Ϊ�գ�����*/
	}
	DuLinkedList temp = L->next;											/*tempЭ����������*/
	while (temp != NULL)														
	{
		visit(temp->data);
		temp = temp->next;
	}
	return;																				/*��ɱ���������*/
}