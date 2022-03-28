#include "../Headers/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s)
{
    s = (LinkStack *)malloc(sizeof(LinkStack)); /*Ϊ��ջ�����µĽ��*/
    if (s == NULL)                              /*�ж��Ƿ񴴽��ɹ�*/
    {
        return ERROR; /*��ʼ��ʧ�ܣ�����ERROR*/
    }
    s->count = 0;   /*s��countֵ��Ϊ0*/
    s->top = NULL;  /*s->top��Ϊ��*/
    return SUCCESS; /*��ʼ���ɹ�������SUCCESS*/
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
    if (s == NULL || s->top == NULL) /*��s==NULL��s->top==NULL���ж��Ƿ�Ϊ��*/
    {
        return SUCCESS; /*Ϊ�շ���SUCCESS*/
    }
    else
    {
        return ERROR; /*��Ϊ�շ���ERROR*/
    }
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s, ElemType *e)
{
    if (isEmptyLStack(s)) /*�ж���ջ�Ƿ�Ϊ��*/
    {
        fputs("ջΪ��!!\n", stderr);
        system("pause");
        return ERROR; /*Ϊ�շ���ERROR*/
    }
    *e = s->top->data; /*e���ڽ���ջ������*/
    return SUCCESS;    /*��Ϊ�շ���SUCCESS*/
}

//���ջ
Status clearLStack(LinkStack *s)
{
    if (isEmptyLStack(s)) /*���ж�ջ�����ǰ�Ƿ���Ϊ��*/
    {
        fputs("ջΪ��!!\n", stderr); /*ջ��Ϊ�վͷ���*/
        system("pause");
        return ERROR; /*Ϊ�շ���ERROR*/
    }
    while (s->top != NULL) /*��whileѭ����temp������ͷ��ڴ�*/
    {
        LinkStackPtr *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->count = 0;   /*s->count��Ϊ0*/
    return SUCCESS; /*�����ɹ�������SUCCESS*/
}

//����ջ
Status destroyLStack(LinkStack *s)
{
    while (s->top != NULL) /*��whileѭ���ͷ��ڴ�*/
    {
        LinkStackPtr *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->count = 0;   /*��count��Ϊ0*/
    return SUCCESS; /*�ɹ�������SUCCESS*/
}

//���ջ����
Status LStackLength(LinkStack *s, int *length)
{
    if (s == NULL) /*�ж���ջ�Ƿ�Ϊ��*/
    {
        fputs("ջδ��ʼ��!!\n", stderr);
        system("pause");
        return ERROR; /*Ϊ�գ�����ERROR*/
    }
    *length = s->count; /*length����s->coun��ֵ*/
    return SUCCESS;     /*�ɹ�������SUCCESS*/
}

//��ջ
Status pushLStack(LinkStack *s, ElemType data)
{
    if (s == NULL) /*���жϽ���Ƿ�ΪNULL*/
    {
        fputs("ջδ��ʼ��!!\n", stderr);
        system("pause");
        return ERROR; /*ʧ�ܣ�����ERROR*/
    }                 /*�����½�����ڴ洢����*/
    LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = s->top; /*����ջ*/
    s->top = newNode;
    s->count++;     /*��ջ��count++*/
    return SUCCESS; /*�ɹ�������SUCCESS*/
}

//��ջ
Status popLStack(LinkStack *s, ElemType *data)
{
    if (isEmptyLStack(s)) /*�ж�ջ�Ƿ�Ϊ��*/
    {
        fputs("ջΪ��!!\n", stderr);
        system("pause");
        return ERROR; /*Ϊ�գ�����ERROR*/
    }
    StackNode *temp = s->top; /*��Ϊ�գ���temp��ʱ�洢��ջ����ַ*/
    *data = temp->data;       /*�����ջԪ�ص�ֵ*/
    s->top = s->top->next;    /*��ջ���Ƴ�ջ��Ԫ��*/
    s->count--;               /*count-1*/
    free(temp);               /*�ͷų�ջ�Ľ��*/
    return SUCCESS;           /*�ɹ�������SUCCESS*/
}
