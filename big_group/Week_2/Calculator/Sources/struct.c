#include "../Headers/struct.h"
#include "../Headers/calcu.h"
#include <stdio.h>
#include <stdlib.h>

void IntStack(PtrtoLinkstack *stack) /*初始化栈函数*/
{
    *stack = (PtrtoLinkstack)malloc(sizeof(Linkstack)); /*分配新结点*/
    (*stack)->top = NULL;                               /*栈顶置空*/
    return;                                             /*返回*/
}

void PushStack(PtrtoLinkstack stack, char e) /*入栈功能函数*/
{
    if (stack == NULL) /*检测栈是否初始化完成*/
    {
        fputs("栈未初始化!!\n", stderr);
        system("pause");
        return; /*为空，退出函数*/
    }           /*创建新栈结点*/
    PtrtostackNode newNode = (PtrtostackNode)malloc(sizeof(stackNode));
    newNode->data = e;          /*赋予栈的数据字符e*/
    newNode->next = stack->top; /*将结点的下一个连入栈*/
    stack->top = newNode;       /*设置栈顶为新结点*/
    return;                     /*结束，退出函数*/
}

void PopStack(PtrtoLinkstack stack, char *e) /*出栈功能函数*/
{
    if (isEmpty(stack)) /*判断栈是否为空*/
    {
        fputs("栈为空!!\n", stderr);
        system("pause");
        return; /*为空，退出*/
    }
    PtrtostackNode temp = stack->top; /*用于临时存储结点*/
    stack->top = stack->top->next;    /*出栈*/
    *e = temp->data;                  /*将原栈顶数据赋予e*/
    free(temp);                       /*释放内存*/
    return;                           /*退出*/
}

void GetStackHead(PtrtoLinkstack stack, char *e) /*取得栈顶元素函数功能函数*/
{
    if (isEmpty(stack)) /*判断栈是否为空*/
    {
        fputs("栈为空!!\n", stderr);
        system("pause");
        return; /*为空，退出*/
    }
    *e = stack->top->data; /*将栈顶值赋予e*/
    return;                /*退出*/
}

Status isEmpty(PtrtoLinkstack stack) /*判断栈是否为空功能函数*/
{
    if (stack == NULL) /*判断栈是否初始化完成*/
    {
        fputs("栈未初始化!!\n", stderr);
        system("pause");
        return FALSE; /*未初始化，返回FALSE*/
    }
    if (stack->top != NULL) /*不为空。返回FALSE*/
    {
        return FALSE;
    }
    else /*为空，返回TRUE*/
    {
        return TRUE;
    }
}