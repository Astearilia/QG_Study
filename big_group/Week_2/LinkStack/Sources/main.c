#include "../Headers/LinkStack.h"
#include "../Headers/menu.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ord = 0;  /*ord用于接收指令*/
    LinkStack s;  /*栈头*/
    s.top = NULL; /*置空，消除野指针*/
    s.count = 0;  /*设为0*/
    do
    {
        system("cls");
        MainMenu();    /*显示主菜单函数*/
        ScanOrd(&ord); /*确保输入合法*/
        system("cls");
        switch (ord) /*switch多分支选择*/
        {
        case 1: /*初始化链栈*/
        {
            if (initLStack(&s))
            {
                printf("初始化链栈成功!\n");
            }
            else
            {
                fputs("初始化链栈失败!\n", stderr);
            }
            break;
        }
        case 2: /*销毁链栈*/
        {
            if (destroyLStack(&s))
            {
                printf("销毁链栈成功!!\n");
            }
            else
            {
                fputs("销毁链栈失败!!\n", stderr);
            }
            break;
        }
        case 3: /*判断链栈是否为空*/
        {
            if (isEmptyLStack(&s))
            {
                printf("链栈为空!\n");
            }
            else
            {
                printf("链栈不为空!\n");
            }
            break;
        }
        case 4: /*获取栈顶元素*/
        {
            ElemType e; /*e用于存储栈顶元素*/
            if (getTopLStack(&s, &e))
            {
                printf("成功获取栈顶元素!\n");
                printf("其值为: %d", e);
            }
            else
            {
                fputs("获取栈顶元素失败!\n", stderr);
            }
            break;
        }
        case 5: /*获取栈长函数*/
        {
            int length = 0; /*length用于获取栈长*/
            if (LStackLength(&s, &length))
            {
                printf("取得链栈长度成功!\n");
                printf("其长度为: %d", length);
            }
            else
            {
                fputs("获取链栈长度失败!\n", stderr);
            }
            break;
        }
        case 6: /*入栈功能函数*/
        {
            ElemType e = 0; /*e用于存储入栈的元素*/
            printf("请输入想要入栈的元素值:");
            ScanInt(&e); /*确保输入合法*/
            if (pushLStack(&s, e))
            {
                printf("元素入栈成功!\n");
            }
            else
            {
                fputs("元素入栈失败!\n", stderr);
            }
            break;
        }
        case 7: {
            ElemType e = 0; /*e用于存储出栈的元素值*/
            if (popLStack(&s, &e))
            {
                printf("出栈成功，出栈元素值为: ");
                printf("%d", e);
            }
            else
            {
                fputs("出栈失败!!\n", stderr);
            }
            break;
        }
        case 8: /*清空链栈功能*/
        {
            if (clearLStack(&s))
            {
                printf("清空链栈成功!\n");
            }
            else
            {
                fputs("清空链栈失败!\n", stderr);
            }
            break;
        }
        case 9: {
            break;
        }
        default: {
            fputs("请输入正确指令\n", stderr);
            break;
        }
        }
        if (ord != 9)
        {
            system("pause");
        }
    } while (ord != 9);
}