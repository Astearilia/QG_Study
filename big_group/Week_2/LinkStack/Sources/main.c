#include "../Headers/LinkStack.h"
#include "../Headers/menu.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ord = 0;  /*ord���ڽ���ָ��*/
    LinkStack s;  /*ջͷ*/
    s.top = NULL; /*�ÿգ�����Ұָ��*/
    s.count = 0;  /*��Ϊ0*/
    do
    {
        system("cls");
        MainMenu();    /*��ʾ���˵�����*/
        ScanOrd(&ord); /*ȷ������Ϸ�*/
        system("cls");
        switch (ord) /*switch���֧ѡ��*/
        {
        case 1: /*��ʼ����ջ*/
        {
            if (initLStack(&s))
            {
                printf("��ʼ����ջ�ɹ�!\n");
            }
            else
            {
                fputs("��ʼ����ջʧ��!\n", stderr);
            }
            break;
        }
        case 2: /*������ջ*/
        {
            if (destroyLStack(&s))
            {
                printf("������ջ�ɹ�!!\n");
            }
            else
            {
                fputs("������ջʧ��!!\n", stderr);
            }
            break;
        }
        case 3: /*�ж���ջ�Ƿ�Ϊ��*/
        {
            if (isEmptyLStack(&s))
            {
                printf("��ջΪ��!\n");
            }
            else
            {
                printf("��ջ��Ϊ��!\n");
            }
            break;
        }
        case 4: /*��ȡջ��Ԫ��*/
        {
            ElemType e; /*e���ڴ洢ջ��Ԫ��*/
            if (getTopLStack(&s, &e))
            {
                printf("�ɹ���ȡջ��Ԫ��!\n");
                printf("��ֵΪ: %d", e);
            }
            else
            {
                fputs("��ȡջ��Ԫ��ʧ��!\n", stderr);
            }
            break;
        }
        case 5: /*��ȡջ������*/
        {
            int length = 0; /*length���ڻ�ȡջ��*/
            if (LStackLength(&s, &length))
            {
                printf("ȡ����ջ���ȳɹ�!\n");
                printf("�䳤��Ϊ: %d", length);
            }
            else
            {
                fputs("��ȡ��ջ����ʧ��!\n", stderr);
            }
            break;
        }
        case 6: /*��ջ���ܺ���*/
        {
            ElemType e = 0; /*e���ڴ洢��ջ��Ԫ��*/
            printf("��������Ҫ��ջ��Ԫ��ֵ:");
            ScanInt(&e); /*ȷ������Ϸ�*/
            if (pushLStack(&s, e))
            {
                printf("Ԫ����ջ�ɹ�!\n");
            }
            else
            {
                fputs("Ԫ����ջʧ��!\n", stderr);
            }
            break;
        }
        case 7: {
            ElemType e = 0; /*e���ڴ洢��ջ��Ԫ��ֵ*/
            if (popLStack(&s, &e))
            {
                printf("��ջ�ɹ�����ջԪ��ֵΪ: ");
                printf("%d", e);
            }
            else
            {
                fputs("��ջʧ��!!\n", stderr);
            }
            break;
        }
        case 8: /*�����ջ����*/
        {
            if (clearLStack(&s))
            {
                printf("�����ջ�ɹ�!\n");
            }
            else
            {
                fputs("�����ջʧ��!\n", stderr);
            }
            break;
        }
        case 9: {
            break;
        }
        default: {
            fputs("��������ȷָ��\n", stderr);
            break;
        }
        }
        if (ord != 9)
        {
            system("pause");
        }
    } while (ord != 9);
}