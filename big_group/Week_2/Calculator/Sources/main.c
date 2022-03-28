#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/calcu.h"
#include "../Headers/struct.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ord = 1;
    do
    {
        PtrtoLinkstack calculateStack; /*处理用的栈*/
        IntStack(&calculateStack);     /*初始化栈*/
        printf("请输入所有数字皆为个位正数的中缀表达式（例如：6+(4-2)*3+9/3 ）\n");
        char exp[50]; /*exp用于存储用户输入的中缀表达式*/
        scanf("%s", exp);
        if (!CheckExp(exp)) /*调用CheckExp来检测输入是否合法*/
        {                   /*输入不合法则执行以下代码*/
            fputs("输入的表达式不合规范，请重新输入!!\n", stderr);
            system("pause");
            system("cls");
            continue;
        }
        printf("其后缀表达式为:");
        char RPNexp[50];                    /*RPNexp用于存储由exp得到的后缀表达式*/
        toRPN(exp, RPNexp, calculateStack); /*将exp的字符串转化为后缀表达式并存储在RPNexp中*/
        putchar('\n');                      /*调用calculate函数来计算后缀表达式结果并打印*/
        printf("其结果（结果取整）为:%d\n", calRPN(RPNexp, calculateStack));
        system("pause");
        printf("请问是否要继续进行计算？（0表示退出程序，其余数字表示继续计算）\n");
        scanNum(&ord);
        system("cls");
    } while (ord != 0);
    return; /*结束*/
}