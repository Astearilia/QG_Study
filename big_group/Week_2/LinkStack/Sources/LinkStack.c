#include "../Headers/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
//链栈

//初始化栈
Status initLStack(LinkStack *s)
{
    s = (LinkStack *)malloc(sizeof(LinkStack)); /*为链栈创建新的结点*/
    if (s == NULL)                              /*判断是否创建成功*/
    {
        return ERROR; /*初始化失败，返回ERROR*/
    }
    s->count = 0;   /*s的count值设为0*/
    s->top = NULL;  /*s->top设为空*/
    return SUCCESS; /*初始化成功，返回SUCCESS*/
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s)
{
    if (s == NULL || s->top == NULL) /*用s==NULL和s->top==NULL来判断是否为空*/
    {
        return SUCCESS; /*为空返回SUCCESS*/
    }
    else
    {
        return ERROR; /*不为空返回ERROR*/
    }
}

//得到栈顶元素
Status getTopLStack(LinkStack *s, ElemType *e)
{
    if (isEmptyLStack(s)) /*判断链栈是否为空*/
    {
        fputs("栈为空!!\n", stderr);
        system("pause");
        return ERROR; /*为空返回ERROR*/
    }
    *e = s->top->data; /*e用于接收栈顶数据*/
    return SUCCESS;    /*不为空返回SUCCESS*/
}

//清空栈
Status clearLStack(LinkStack *s)
{
    if (isEmptyLStack(s)) /*先判断栈在清空前是否已为空*/
    {
        fputs("栈为空!!\n", stderr); /*栈已为空就返回*/
        system("pause");
        return ERROR; /*为空返回ERROR*/
    }
    while (s->top != NULL) /*用while循环和temp结合来释放内存*/
    {
        LinkStackPtr *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->count = 0;   /*s->count设为0*/
    return SUCCESS; /*操作成功，返回SUCCESS*/
}

//销毁栈
Status destroyLStack(LinkStack *s)
{
    while (s->top != NULL) /*用while循环释放内存*/
    {
        LinkStackPtr *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->count = 0;   /*将count设为0*/
    return SUCCESS; /*成功，返回SUCCESS*/
}

//检测栈长度
Status LStackLength(LinkStack *s, int *length)
{
    if (s == NULL) /*判断链栈是否为空*/
    {
        fputs("栈未初始化!!\n", stderr);
        system("pause");
        return ERROR; /*为空，返回ERROR*/
    }
    *length = s->count; /*length赋予s->coun的值*/
    return SUCCESS;     /*成功，返回SUCCESS*/
}

//入栈
Status pushLStack(LinkStack *s, ElemType data)
{
    if (s == NULL) /*先判断结点是否为NULL*/
    {
        fputs("栈未初始化!!\n", stderr);
        system("pause");
        return ERROR; /*失败，返回ERROR*/
    }                 /*创建新结点用于存储数据*/
    LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = s->top; /*结点进栈*/
    s->top = newNode;
    s->count++;     /*进栈后count++*/
    return SUCCESS; /*成功，返回SUCCESS*/
}

//出栈
Status popLStack(LinkStack *s, ElemType *data)
{
    if (isEmptyLStack(s)) /*判断栈是否为空*/
    {
        fputs("栈为空!!\n", stderr);
        system("pause");
        return ERROR; /*为空，返回ERROR*/
    }
    StackNode *temp = s->top; /*不为空，用temp临时存储出栈结点地址*/
    *data = temp->data;       /*传输出栈元素的值*/
    s->top = s->top->next;    /*从栈中移除栈顶元素*/
    s->count--;               /*count-1*/
    free(temp);               /*释放出栈的结点*/
    return SUCCESS;           /*成功，返回SUCCESS*/
}
