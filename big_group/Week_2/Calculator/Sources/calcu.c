#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/calcu.h"
#include "../Headers/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scanNum(int *num) /*接收指令or数值函数*/
{
    int flag = 1; /*flag表示输入是否合法*/
    do
    {
        flag = 1;
        if ((scanf("%d", num)) != 1) /*使用if+scanf+do-while循环来确保输入合法*/
        {
            while (getchar() != '\n')
                ;
            flag = 0;
            fputs("输入不合法,重新输入数据\n", stderr);
        }
    } while (flag != 1);
}

Status isNum(char s) /*判断传入的字符是否为数字*/
{
    if (s >= '0' && s <= '9') /*是数字，返回TRUE*/
    {
        return TRUE;
    }
    else /*不是数字，返回FALSE*/
    {
        return FALSE;
    }
}

Status isSymbols(char s) /*判断传入字符是否为为计算符号*/
{
    if (s == '+' || s == '-' || s == '*' || s == '/')
    {
        return TRUE; /*是计算符号，返回TRUE*/
    }
    else
    {
        return FALSE; /*不是计算符号，返回FALSE*/
    }
}

Status isLeftBrackets(char s) /*判断传入的字符是否为左括号*/
{
    if (s == '(')
    {
        return TRUE; /*是左括号，返回TRUE*/
    }
    else
    {
        return FALSE; /*不是左括号，返回FALSE*/
    }
}

Status isRightBrackets(char s) /*判断传入的字符是否为右括号*/
{
    if (s == ')')
    {
        return TRUE; /*是右括号，返回TRUE*/
    }
    else
    {
        return FALSE; /*不是右括号，返回FALSE*/
    }
}

int PriorityLevel(char s) /*判断运算符优先级*/
{
    switch (s) /*用switch多分枝选择来判断*/
    {
    case '+': {
        return 1; /* '+' 设优先级为1*/
    }
    case '-': {
        return 1; /* '-' 设优先级为1*/
    }
    case '*': {
        return 2; /* '*' 设优先级为2*/
    }
    case '/': {
        return 4; /* '/' 设优先级为2*/
    }
    default: {
        return 0; /*其余优先级设为0*/
    }
    }
}

int CharToInt(char s) /*将char转化为int类型*/
{
    return s - '0'; /*转化其为s-‘0*/
}

int Calculate(int num01, int num02, char s) /*计算字符差值*/
{
    switch (s) /*switch多分支选择判断情况*/
    {
    case '+': {
        return num01 + num02;
    }
    case '-': {
        return num01 - num02;
    }
    case '*': {
        return num01 * num02;
    }
    case '/': {
        return num01 / num02;
    }
    }
}

Status CheckExp(char *exp)               /*检测表达式是否合法函数*/
{                                        /*合法返回TRUE，不合法返回FALSE*/
    int countLeftBrackets = 0;           /*countLeftBrackets用于统计运算式里的左括号数*/
    int countRightBrackets = 0;          /*countRightBrackets用于统计运算式里的右括号数*/
    for (int i = 0; exp[i] != '\0'; i++) /*首先先遍历所有字符，判断是否出现*/
    {                                    /*非数字和运算符*/
        if (!(isNum(exp[i]) || isLeftBrackets(exp[i]) || isRightBrackets(exp[i]) || isSymbols(exp[i])))
        {
            return FALSE;
        }
        if (isLeftBrackets(exp[i])) /*在统计出现的左右括号数*/
        {
            countLeftBrackets++;
        }
        if (isRightBrackets(exp[i]))
        {
            countRightBrackets++;
        }
    }
    if (countLeftBrackets != countRightBrackets)
    { /*如若左右括号数不相等，则必有错*/
        return FALSE;
    }
    if (isSymbols(exp[0])) /*判断首位是否为运算符，如若是则报错*/
    {
        return FALSE;
    }
    int j = 1;
    for (; exp[j] != '\0'; j++)
    {
        if (isNum(exp[j]) && isNum(exp[j - 1])) /*判断是否出现连续的二位数*/
        {
            return FALSE;
        }
        if (isSymbols(exp[j]) && isSymbols(exp[j - 1])) /*判断是否出现连续的运算符*/
        {
            return FALSE;
        }
        if (isSymbols(exp[j]) && isLeftBrackets(exp[j - 1])) /*判断在左括号后是否直接出现运算符*/
        {
            return FALSE;
        }
    }
    if (isSymbols(exp[j - 1])) /*查看表达式末尾是否为运算符*/
    {                          /*是则报错*/
        return FALSE;
    }
    return TRUE; /*经过检查合规，返回TRUE*/
}

void toRPN(char *s, char *RPNexp, PtrtoLinkstack stack) /*将输入的字符串转换为后缀表达式*/
{
    int i = 0;           /*i用于遍历s字符串*/
    int j = 0;           /*j用于指示RPNexp字符串*/
    while (s[i] != '\0') /*while循环遍历*/
    {
        if (isNum(s[i])) /*首先判断s[i]是否为数字*/
        {
            printf("%c ", s[i]); /*是的话，输出并计入RPNexp*/
            RPNexp[j++] = s[i];
            i++; /*i++，开始读取s下一个字符*/
            continue;
        }
        if (isLeftBrackets(s[i])) /*判断s[i]是否为左括号*/
        {
            PushStack(stack, s[i]); /*是的话就直接入栈*/
            i++;                    /*i++，开始读取s下一个字符*/
            continue;
        }
        if (isRightBrackets(s[i])) /*判断s[i]是否为右括号*/
        {
            char stackTopRB = 0; /*stackTopRB用于接收从栈顶读出的字符*/
            do
            {
                PopStack(stack, &stackTopRB); /*出栈*/
                if (stackTopRB != '(')        /*判断出栈符号是否为"(*/
                {
                    printf("%c ", stackTopRB); /*不是，则输出*/
                    RPNexp[j++] = stackTopRB;  /*写入RPNexp*/
                }
            } while (stackTopRB != '('); /*while循环读取全部*/
            i++;                         /*i++，开始读取s的下一个字符*/
            continue;
        }
        if (isSymbols(s[i])) /*判断s[i]是否为运算符*/
        {
            if (isEmpty(stack)) /*如若现在栈为空，则直接入栈*/
            {
                PushStack(stack, s[i]);
                i++; /*i++，开始读取s的下一个字符*/
                continue;
            }
            char stackTopSy = 0;                                 /*stackTopSy用于接收栈顶符号*/
            GetStackHead(stack, &stackTopSy);                    /*调用GetStackHead函数*/
            if (PriorityLevel(s[i]) > PriorityLevel(stackTopSy)) /*判断s[i]和栈顶运算符优先级大小*/
            {
                PushStack(stack, s[i]); /*s[i]优先级大于栈顶。则入栈*/
                i++;                    /*i++，开始读取s的下一个字符*/
                continue;
            }
            if (PriorityLevel(s[i]) <= PriorityLevel(stackTopSy)) /*判断s[i]和栈顶运算符优先级大小*/
            {
                do
                {                                 /*do-while循环操作*/
                    PopStack(stack, &stackTopSy); /*用stackTopSy接收栈顶元素*/
                    printf("%c ", stackTopSy);    /*打印栈顶元素值*/
                    RPNexp[j++] = stackTopSy;     /*写入RPNexp中*/
                    if (isEmpty(stack))           /*判断此时栈是否为空*/
                    {
                        break; /*为空则退出循环*/
                    }
                    GetStackHead(stack, &stackTopSy); /*再次读取栈的头结点*/
                } while (PriorityLevel(s[i]) <= PriorityLevel(stackTopSy));
                PushStack(stack, s[i]); /*结束循环，将s[i]入栈*/
                i++;                    /*i++，开始读取s的下一个字符*/
                continue;
            }
        }
    }
    while (!isEmpty(stack))              /*当读取完s的所有字符后，要输出栈中剩下的运算符*/
    {                                    /*采用while循环来读取全部*/
        char stackSysmbols = 0;          /*stackSysmbols用于接收出栈字符*/
        PopStack(stack, &stackSysmbols); /*调用PopStack出栈*/
        printf("%c ", stackSysmbols);    /*打印该字符*/
        RPNexp[j++] = stackSysmbols;     /*写入RPNexp*/
    }
    RPNexp[j] = '\0'; /*将RPNexp的末尾置零*/
    return;           /*结束，退出*/
}

int calRPN(char *RPNexp, PtrtoLinkstack stack) /*计算RPN表达式*/
{
    int i = 0;                /*i用于遍历字符串*/
    while (RPNexp[i] != '\0') /*while循环遍历*/
    {
        if (isNum(RPNexp[i])) /*若RPNexp[i]为数字,则进栈*/
        {
            PushStack(stack, RPNexp[i]);
            i++; /*i++，遍历sRPNexpi]下一个字符*/
            continue;
        }
        if (isSymbols(RPNexp[i])) /*若RPNexp[i]为运算符,则将出栈顶的*/
        {                         /*两个数字运算运算并入栈*/
            char stackNum01;      /*stackNum01用于接收栈顶第一个字符*/
            PopStack(stack, &stackNum01);
            int num01 = CharToInt(stackNum01); /*num01用于接收字符转化为整型的结果*/
            char stackNum02;                   /*stackNum01用于接收栈顶第二个字符*/
            PopStack(stack, &stackNum02);
            int num02 = CharToInt(stackNum02);               /*num02用于接收字符转化为整型的结果*/
            int result = Calculate(num02, num01, RPNexp[i]); /*运算num01和num02*/
            PushStack(stack, (char)(result + '0'));          /*将结果result转化为字符类型并入栈*/
            i++;                                             /*i++，读取RPNexp下一个字符*/
            continue;
        }
    }
    char result; /*结束循环，读取栈剩下的字符数值*/
    PopStack(stack, &result);
    return CharToInt(result); /*将字符数值转化为整型并返回*/
}