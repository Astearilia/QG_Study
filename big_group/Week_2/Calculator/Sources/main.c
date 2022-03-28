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
        PtrtoLinkstack calculateStack; /*�����õ�ջ*/
        IntStack(&calculateStack);     /*��ʼ��ջ*/
        printf("�������������ֽ�Ϊ��λ��������׺���ʽ�����磺6+(4-2)*3+9/3 ��\n");
        char exp[50]; /*exp���ڴ洢�û��������׺���ʽ*/
        scanf("%s", exp);
        if (!CheckExp(exp)) /*����CheckExp����������Ƿ�Ϸ�*/
        {                   /*���벻�Ϸ���ִ�����´���*/
            fputs("����ı��ʽ���Ϲ淶������������!!\n", stderr);
            system("pause");
            system("cls");
            continue;
        }
        printf("���׺���ʽΪ:");
        char RPNexp[50];                    /*RPNexp���ڴ洢��exp�õ��ĺ�׺���ʽ*/
        toRPN(exp, RPNexp, calculateStack); /*��exp���ַ���ת��Ϊ��׺���ʽ���洢��RPNexp��*/
        putchar('\n');                      /*����calculate�����������׺���ʽ�������ӡ*/
        printf("���������ȡ����Ϊ:%d\n", calRPN(RPNexp, calculateStack));
        system("pause");
        printf("�����Ƿ�Ҫ�������м��㣿��0��ʾ�˳������������ֱ�ʾ�������㣩\n");
        scanNum(&ord);
        system("cls");
    } while (ord != 0);
    return; /*����*/
}