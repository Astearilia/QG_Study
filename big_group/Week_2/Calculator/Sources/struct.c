#include "../Headers/struct.h"
#include "../Headers/calcu.h"
#include <stdio.h>
#include <stdlib.h>

void IntStack(PtrtoLinkstack *stack) /*��ʼ��ջ����*/
{
    *stack = (PtrtoLinkstack)malloc(sizeof(Linkstack)); /*�����½��*/
    (*stack)->top = NULL;                               /*ջ���ÿ�*/
    return;                                             /*����*/
}

void PushStack(PtrtoLinkstack stack, char e) /*��ջ���ܺ���*/
{
    if (stack == NULL) /*���ջ�Ƿ��ʼ�����*/
    {
        fputs("ջδ��ʼ��!!\n", stderr);
        system("pause");
        return; /*Ϊ�գ��˳�����*/
    }           /*������ջ���*/
    PtrtostackNode newNode = (PtrtostackNode)malloc(sizeof(stackNode));
    newNode->data = e;          /*����ջ�������ַ�e*/
    newNode->next = stack->top; /*��������һ������ջ*/
    stack->top = newNode;       /*����ջ��Ϊ�½��*/
    return;                     /*�������˳�����*/
}

void PopStack(PtrtoLinkstack stack, char *e) /*��ջ���ܺ���*/
{
    if (isEmpty(stack)) /*�ж�ջ�Ƿ�Ϊ��*/
    {
        fputs("ջΪ��!!\n", stderr);
        system("pause");
        return; /*Ϊ�գ��˳�*/
    }
    PtrtostackNode temp = stack->top; /*������ʱ�洢���*/
    stack->top = stack->top->next;    /*��ջ*/
    *e = temp->data;                  /*��ԭջ�����ݸ���e*/
    free(temp);                       /*�ͷ��ڴ�*/
    return;                           /*�˳�*/
}

void GetStackHead(PtrtoLinkstack stack, char *e) /*ȡ��ջ��Ԫ�غ������ܺ���*/
{
    if (isEmpty(stack)) /*�ж�ջ�Ƿ�Ϊ��*/
    {
        fputs("ջΪ��!!\n", stderr);
        system("pause");
        return; /*Ϊ�գ��˳�*/
    }
    *e = stack->top->data; /*��ջ��ֵ����e*/
    return;                /*�˳�*/
}

Status isEmpty(PtrtoLinkstack stack) /*�ж�ջ�Ƿ�Ϊ�չ��ܺ���*/
{
    if (stack == NULL) /*�ж�ջ�Ƿ��ʼ�����*/
    {
        fputs("ջδ��ʼ��!!\n", stderr);
        system("pause");
        return FALSE; /*δ��ʼ��������FALSE*/
    }
    if (stack->top != NULL) /*��Ϊ�ա�����FALSE*/
    {
        return FALSE;
    }
    else /*Ϊ�գ�����TRUE*/
    {
        return TRUE;
    }
}