#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/calcu.h"
#include "../Headers/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scanNum(int *num) /*����ָ��or��ֵ����*/
{
    int flag = 1; /*flag��ʾ�����Ƿ�Ϸ�*/
    do
    {
        flag = 1;
        if ((scanf("%d", num)) != 1) /*ʹ��if+scanf+do-whileѭ����ȷ������Ϸ�*/
        {
            while (getchar() != '\n')
                ;
            flag = 0;
            fputs("���벻�Ϸ�,������������\n", stderr);
        }
    } while (flag != 1);
}

Status isNum(char s) /*�жϴ�����ַ��Ƿ�Ϊ����*/
{
    if (s >= '0' && s <= '9') /*�����֣�����TRUE*/
    {
        return TRUE;
    }
    else /*�������֣�����FALSE*/
    {
        return FALSE;
    }
}

Status isSymbols(char s) /*�жϴ����ַ��Ƿ�ΪΪ�������*/
{
    if (s == '+' || s == '-' || s == '*' || s == '/')
    {
        return TRUE; /*�Ǽ�����ţ�����TRUE*/
    }
    else
    {
        return FALSE; /*���Ǽ�����ţ�����FALSE*/
    }
}

Status isLeftBrackets(char s) /*�жϴ�����ַ��Ƿ�Ϊ������*/
{
    if (s == '(')
    {
        return TRUE; /*�������ţ�����TRUE*/
    }
    else
    {
        return FALSE; /*���������ţ�����FALSE*/
    }
}

Status isRightBrackets(char s) /*�жϴ�����ַ��Ƿ�Ϊ������*/
{
    if (s == ')')
    {
        return TRUE; /*�������ţ�����TRUE*/
    }
    else
    {
        return FALSE; /*���������ţ�����FALSE*/
    }
}

int PriorityLevel(char s) /*�ж���������ȼ�*/
{
    switch (s) /*��switch���֦ѡ�����ж�*/
    {
    case '+': {
        return 1; /* '+' �����ȼ�Ϊ1*/
    }
    case '-': {
        return 1; /* '-' �����ȼ�Ϊ1*/
    }
    case '*': {
        return 2; /* '*' �����ȼ�Ϊ2*/
    }
    case '/': {
        return 4; /* '/' �����ȼ�Ϊ2*/
    }
    default: {
        return 0; /*�������ȼ���Ϊ0*/
    }
    }
}

int CharToInt(char s) /*��charת��Ϊint����*/
{
    return s - '0'; /*ת����Ϊs-��0*/
}

int Calculate(int num01, int num02, char s) /*�����ַ���ֵ*/
{
    switch (s) /*switch���֧ѡ���ж����*/
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

Status CheckExp(char *exp)               /*�����ʽ�Ƿ�Ϸ�����*/
{                                        /*�Ϸ�����TRUE�����Ϸ�����FALSE*/
    int countLeftBrackets = 0;           /*countLeftBrackets����ͳ������ʽ�����������*/
    int countRightBrackets = 0;          /*countRightBrackets����ͳ������ʽ�����������*/
    for (int i = 0; exp[i] != '\0'; i++) /*�����ȱ��������ַ����ж��Ƿ����*/
    {                                    /*�����ֺ������*/
        if (!(isNum(exp[i]) || isLeftBrackets(exp[i]) || isRightBrackets(exp[i]) || isSymbols(exp[i])))
        {
            return FALSE;
        }
        if (isLeftBrackets(exp[i])) /*��ͳ�Ƴ��ֵ�����������*/
        {
            countLeftBrackets++;
        }
        if (isRightBrackets(exp[i]))
        {
            countRightBrackets++;
        }
    }
    if (countLeftBrackets != countRightBrackets)
    { /*������������������ȣ�����д�*/
        return FALSE;
    }
    if (isSymbols(exp[0])) /*�ж���λ�Ƿ�Ϊ��������������򱨴�*/
    {
        return FALSE;
    }
    int j = 1;
    for (; exp[j] != '\0'; j++)
    {
        if (isNum(exp[j]) && isNum(exp[j - 1])) /*�ж��Ƿ���������Ķ�λ��*/
        {
            return FALSE;
        }
        if (isSymbols(exp[j]) && isSymbols(exp[j - 1])) /*�ж��Ƿ���������������*/
        {
            return FALSE;
        }
        if (isSymbols(exp[j]) && isLeftBrackets(exp[j - 1])) /*�ж��������ź��Ƿ�ֱ�ӳ��������*/
        {
            return FALSE;
        }
    }
    if (isSymbols(exp[j - 1])) /*�鿴���ʽĩβ�Ƿ�Ϊ�����*/
    {                          /*���򱨴�*/
        return FALSE;
    }
    return TRUE; /*�������Ϲ棬����TRUE*/
}

void toRPN(char *s, char *RPNexp, PtrtoLinkstack stack) /*��������ַ���ת��Ϊ��׺���ʽ*/
{
    int i = 0;           /*i���ڱ���s�ַ���*/
    int j = 0;           /*j����ָʾRPNexp�ַ���*/
    while (s[i] != '\0') /*whileѭ������*/
    {
        if (isNum(s[i])) /*�����ж�s[i]�Ƿ�Ϊ����*/
        {
            printf("%c ", s[i]); /*�ǵĻ������������RPNexp*/
            RPNexp[j++] = s[i];
            i++; /*i++����ʼ��ȡs��һ���ַ�*/
            continue;
        }
        if (isLeftBrackets(s[i])) /*�ж�s[i]�Ƿ�Ϊ������*/
        {
            PushStack(stack, s[i]); /*�ǵĻ���ֱ����ջ*/
            i++;                    /*i++����ʼ��ȡs��һ���ַ�*/
            continue;
        }
        if (isRightBrackets(s[i])) /*�ж�s[i]�Ƿ�Ϊ������*/
        {
            char stackTopRB = 0; /*stackTopRB���ڽ��մ�ջ���������ַ�*/
            do
            {
                PopStack(stack, &stackTopRB); /*��ջ*/
                if (stackTopRB != '(')        /*�жϳ�ջ�����Ƿ�Ϊ"(*/
                {
                    printf("%c ", stackTopRB); /*���ǣ������*/
                    RPNexp[j++] = stackTopRB;  /*д��RPNexp*/
                }
            } while (stackTopRB != '('); /*whileѭ����ȡȫ��*/
            i++;                         /*i++����ʼ��ȡs����һ���ַ�*/
            continue;
        }
        if (isSymbols(s[i])) /*�ж�s[i]�Ƿ�Ϊ�����*/
        {
            if (isEmpty(stack)) /*��������ջΪ�գ���ֱ����ջ*/
            {
                PushStack(stack, s[i]);
                i++; /*i++����ʼ��ȡs����һ���ַ�*/
                continue;
            }
            char stackTopSy = 0;                                 /*stackTopSy���ڽ���ջ������*/
            GetStackHead(stack, &stackTopSy);                    /*����GetStackHead����*/
            if (PriorityLevel(s[i]) > PriorityLevel(stackTopSy)) /*�ж�s[i]��ջ����������ȼ���С*/
            {
                PushStack(stack, s[i]); /*s[i]���ȼ�����ջ��������ջ*/
                i++;                    /*i++����ʼ��ȡs����һ���ַ�*/
                continue;
            }
            if (PriorityLevel(s[i]) <= PriorityLevel(stackTopSy)) /*�ж�s[i]��ջ����������ȼ���С*/
            {
                do
                {                                 /*do-whileѭ������*/
                    PopStack(stack, &stackTopSy); /*��stackTopSy����ջ��Ԫ��*/
                    printf("%c ", stackTopSy);    /*��ӡջ��Ԫ��ֵ*/
                    RPNexp[j++] = stackTopSy;     /*д��RPNexp��*/
                    if (isEmpty(stack))           /*�жϴ�ʱջ�Ƿ�Ϊ��*/
                    {
                        break; /*Ϊ�����˳�ѭ��*/
                    }
                    GetStackHead(stack, &stackTopSy); /*�ٴζ�ȡջ��ͷ���*/
                } while (PriorityLevel(s[i]) <= PriorityLevel(stackTopSy));
                PushStack(stack, s[i]); /*����ѭ������s[i]��ջ*/
                i++;                    /*i++����ʼ��ȡs����һ���ַ�*/
                continue;
            }
        }
    }
    while (!isEmpty(stack))              /*����ȡ��s�������ַ���Ҫ���ջ��ʣ�µ������*/
    {                                    /*����whileѭ������ȡȫ��*/
        char stackSysmbols = 0;          /*stackSysmbols���ڽ��ճ�ջ�ַ�*/
        PopStack(stack, &stackSysmbols); /*����PopStack��ջ*/
        printf("%c ", stackSysmbols);    /*��ӡ���ַ�*/
        RPNexp[j++] = stackSysmbols;     /*д��RPNexp*/
    }
    RPNexp[j] = '\0'; /*��RPNexp��ĩβ����*/
    return;           /*�������˳�*/
}

int calRPN(char *RPNexp, PtrtoLinkstack stack) /*����RPN���ʽ*/
{
    int i = 0;                /*i���ڱ����ַ���*/
    while (RPNexp[i] != '\0') /*whileѭ������*/
    {
        if (isNum(RPNexp[i])) /*��RPNexp[i]Ϊ����,���ջ*/
        {
            PushStack(stack, RPNexp[i]);
            i++; /*i++������sRPNexpi]��һ���ַ�*/
            continue;
        }
        if (isSymbols(RPNexp[i])) /*��RPNexp[i]Ϊ�����,�򽫳�ջ����*/
        {                         /*���������������㲢��ջ*/
            char stackNum01;      /*stackNum01���ڽ���ջ����һ���ַ�*/
            PopStack(stack, &stackNum01);
            int num01 = CharToInt(stackNum01); /*num01���ڽ����ַ�ת��Ϊ���͵Ľ��*/
            char stackNum02;                   /*stackNum01���ڽ���ջ���ڶ����ַ�*/
            PopStack(stack, &stackNum02);
            int num02 = CharToInt(stackNum02);               /*num02���ڽ����ַ�ת��Ϊ���͵Ľ��*/
            int result = Calculate(num02, num01, RPNexp[i]); /*����num01��num02*/
            PushStack(stack, (char)(result + '0'));          /*�����resultת��Ϊ�ַ����Ͳ���ջ*/
            i++;                                             /*i++����ȡRPNexp��һ���ַ�*/
            continue;
        }
    }
    char result; /*����ѭ������ȡջʣ�µ��ַ���ֵ*/
    PopStack(stack, &result);
    return CharToInt(result); /*���ַ���ֵת��Ϊ���Ͳ�����*/
}