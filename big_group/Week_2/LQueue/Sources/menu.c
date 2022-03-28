#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/menu.h"
#include "../Headers/LQueue.h"
#include <stdio.h>
#include <stdlib.h>

extern int head = 0; /*headΪdatatypeͷ��*/
extern int tail = 0; /*tailΪdatatypeβ��*/

void ScanOrd(int *num) /*����ָ���*/
{
    if ((scanf("%d", num)) != 1) /*ʹ��if+scanf+do-whileѭ����ȷ������Ϸ�*/
    {
        while (getchar() != '\n')
            ;
        *num = -1;
    }
}

void ScanShort(short *num) /*����short�������ͺ���*/
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
            fputs("���벻�Ϸ�,��������������\n", stderr);
        }
    } while (flag != 1);
}

void ScanInt(int *num) /*����int�������ͺ���*/
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
            fputs("���벻�Ϸ�,��������������\n", stderr);
        }
    } while (flag != 1);
}

void ScanLong(long *num) /*����long�������ͺ���*/
{
    int flag = 1; /*flag��ʾ�����Ƿ�Ϸ�*/
    do
    {
        flag = 1;
        if ((scanf("%ld", num)) != 1) /*ʹ��if+scanf+do-whileѭ����ȷ������Ϸ�*/
        {
            while (getchar() != '\n')
                ;
            flag = 0;
            fputs("���벻�Ϸ�,��������������\n", stderr);
        }
    } while (flag != 1);
}

void ScanFloat(float *d) /*����float������ֵ����*/
{
    int flag = 1; /*flag��ʾ�����Ƿ�Ϸ�*/
    do
    {
        flag = 1;
        if ((scanf("%f", d)) != 1) /*ʹ��if+scanf+do-whileѭ����ȷ������Ϸ�*/
        {
            while (getchar() != '\n')
                ;
            flag = 0;
            fputs("���벻�Ϸ�,��������������\n", stderr);
        }
    } while (flag != 1);
}

void ScanDouble(double *d) /*����double������ֵ����*/
{
    int flag = 1; /*flag��ʾ�����Ƿ�Ϸ�*/
    do
    {
        flag = 1;
        if ((scanf("%lf", d)) != 1) /*ʹ��if+scanf+do-whileѭ����ȷ������Ϸ�*/
        {
            while (getchar() != '\n')
                ;
            flag = 0;
            fputs("���벻�Ϸ�,��������������\n", stderr);
        }
    } while (flag != 1);
}

void MainMenu() /*���˵�����*/
{
    printf("\n\n");
    printf("                         ******************************���Ͷ���ADT******************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              **************************************************************\n");
    printf("                              * 1.��ʼ������		**	2.��������		*\n");
    printf("                              **************************************************************\n");
    printf("                              * 3.�������Ƿ�Ϊ��	**	4.�鿴��ͷԪ��		*\n");
    printf("                              **************************************************************\n");
    printf("                              * 5.ȷ�����г���		**	6.��Ӳ���		*\n");
    printf("                              **************************************************************\n");
    printf("                              * 7.���Ӳ���		**	8.��ն���		*\n");
    printf("                              **************************************************************\n");
    printf("                              * 9.		���ٶ��в��˳�ϵͳ			*\n");
    printf("                              **************************************************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              ��ѡ��˵����:");
}

void EnLQueueMenu(LQueue *Q) /*��ӹ��ܺ���*/
{
    if (Q == NULL || Q->front == NULL)
    {
        fputs("����δ��ʼ��!!\n", stderr);
        return;
    }
    int ord; /*ord���ڽ���ָ��*/
    do
    {
        printf("1-����short���ͣ�2-����int���ͣ�3-����long���ͣ�4-����char���� \n");
        printf("5-����float���ͣ�6-����double���ͣ�7-�����ַ�����8-�������˵�\n");
        printf("��������Ҫ�������������:");
        ScanOrd(&ord);             /*����ScanOrd��ȷ������Ϸ�*/
        void *target = malloc(50); /*target���ڴ洢���յ�data*/
        switch (ord)               /*switch����ѡ��*/
        {
        case 1: {
            target = (short *)target; /*ת��target����*/
            printf("��������Ҫ��ӵ�short��������:");
            ScanShort(target);
            datatype[tail] = 'h'; /*��datatype��ֵ*/
            break;
        }
        case 2: {
            target = (int *)target; /*ת��target����*/
            printf("��������Ҫ��ӵ�int��������:");
            ScanInt(target);
            datatype[tail] = 'i'; /*��datatype��ֵ*/
            break;
        }
        case 3: {
            target = (long *)target; /*ת��target����*/
            printf("��������Ҫ��ӵ�long��������:");
            ScanInt(target);
            datatype[tail] = 'l'; /*��datatype��ֵ*/
            break;
        }
        case 4: {
            target = (char *)target; /*ת��target����*/
            printf("��������Ҫ�����char��������:");
            getchar(); /*getchar��Ϊ�������س���*/
            scanf("%c", target);
            datatype[tail] = 'c'; /*��datatype��ֵ*/
            break;
        }
        case 5: {
            target = (float *)target; /*ת��target����*/
            printf("��������Ҫ�����float��������:");
            ScanFloat(target);
            datatype[tail] = 'f'; /*��datatype��ֵ*/
            break;
        }
        case 6: {
            target = (double *)target; /*ת��target����*/
            printf("��������Ҫ�����double��������:");
            ScanDouble(target);
            datatype[tail] = 'd'; /*��datatype��ֵ*/
            break;
        }
        case 7: {
            target = (char *)target; /*ת��target����*/
            printf("��������Ҫ��ӵ��ַ�����������50���ַ���Ŷ:");
            scanf("%s", target);
            datatype[tail] = 's'; /*��datatype��ֵ*/
            break;
        }
        case 8: {
            break;
        }
        default: {
            fputs("ָ���������������!!\n", stderr); /*�������ָ��*/
            system("pause");
            break;
        }
        }
        if (ord >= 1 && ord <= 7) /*��ʼ���*/
        {
            if (EnLQueue(Q, target)) /*��EnLQueue����ֵ�ж��Ƿ���ӳɹ�*/
            {
                printf("��ӳɹ�!\n");
            }
            else
            {
                printf("���ʧ��!\n");
            }
        }
        if (ord != 8)
        {
            system("pause");
            system("cls");
        }
    } while (ord != 8);
}