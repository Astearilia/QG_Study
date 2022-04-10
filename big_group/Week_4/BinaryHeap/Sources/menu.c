#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/menu.h"
#include "../Headers/heap.h"
#include <stdio.h>
#include <stdlib.h>

void ScanOrd(int *num) /*����ָ���*/
{
    if ((scanf("%d", num)) != 1) /*ʹ��if+scanf+do-whileѭ����ȷ������Ϸ�*/
    {
        while (getchar() != '\n')
            ;
        *num = -1;
    }
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

void MainMenu() /*���˵�����*/
{
    printf("\n\n");
    printf("                           ******************************�󶥶�********************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              **************************************************************\n");
    printf("                              ** 1.����Ԫ��		**	2.��ȡ�����ֵ		**\n");
    printf("                              **************************************************************\n");
    printf("                              ** 3.������	        **	4.�˳�		        **\n");
    printf("                              **************************************************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              ��ѡ��˵����:");
}

Status InsertMenu(HeapPtr H) /*����˵�����*/
{
    if (H->count + 1 >= 30)
    { /*ȷ��Ҫ��������ݸ����ں���Χ��*/
        fputs("������!!\n", stderr);
        return ERROR;
    }
    printf("��������Ҫ�����Ԫ�ظ���,���30��:");
    int flag = 0;
    int nums = 0;
    do
    {
        ScanInt(&nums);           /*����Ҫ�����Ԫ�ظ���*/
        if (nums + H->count > 29) /*���࣬��ʾ������Ϣ*/
        {
            fputs("����Ԫ���������࣬��������������!!\n", stderr);
            flag = 0;
            continue;
        }
        flag = 1;
    } while (flag != 1);
    for (int i = 0; i < nums; i++) /*��ʼѭ������*/
    {
        printf("������Ҫ����ĵ� %d ������:", i + 1);
        int tmp = 0;               /*tmp���ڽ���Ҫ���������*/
        ScanInt(&tmp);             /*ȷ������Ϸ�*/
        if (insertMaxHeap(H, tmp)) /*�÷���ֵ�жϲ����Ƿ�ɹ�*/
        {
            printf("����ɹ�!!\n");
        }
        else
        {
            fputs("����ʧ��!!\n", stderr);
        }
    }
}

void SortMenu(HeapPtr H) /*����˵�����*/
{
    if (H->count == 0) /*�ж϶����Ƿ���Ԫ��*/
    {
        printf("������Ԫ�أ����Ȳ���Ԫ��!!\n", stderr);
        return;
    }
    int tmpData[MAAX_SIZE] = {0}; /*tmpData���ڴ洢���ѵ�����*/
    int tmpNum = H->count;
    printf("�ö��е�Ԫ���ɴ�С��˳��Ϊ:\n");
    for (int i = 0; i < tmpNum; i++) /*��forѭ��ѭ���õ��Ѷ�Ԫ��*/
    {
        tmpData[i] = getHeapMax(H);
        printf("%d ", tmpData[i]);
    }
    putchar('\n');
    for (int j = 0; j < tmpNum; j++) /*�ٽ�tmpData��ֵ�����*/
    {
        insertMaxHeap(H, tmpData[j]);
    }
    return;
}