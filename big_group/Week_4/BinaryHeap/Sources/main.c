#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/heap.h"
#include "../Headers/menu.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    HeapPtr H = (HeapPtr)malloc(sizeof(Heap)); /*��ʼ����*/
    inintHeap(H);
    int ord = 0; /*ord���ڽ���ָ��*/
    do
    {
        system("cls");
        MainMenu();
        ScanOrd(&ord); /*��ScanOrdȷ������Ϸ�*/
        system("cls");
        switch (ord)
        {
        case 1: {
            InsertMenu(H); /*����˵�����*/
            break;
        }
        case 2: /*��ʾ�����ֵ*/
        {
            if (H->count == 0)
            {
                fputs("������Ԫ�أ����Ȳ���Ԫ��!!\n", stderr);
            }
            else
            {
                printf("�������Ԫ��Ϊ��%d\n", H->data[1]);
            }
            break;
        }
        case 3: /*��������*/
        {
            SortMenu(H);
            break;
        }
        case 4: {
            break;
        }
        default: /*ȷ������Ϸ�*/
        {
            fputs("��������ȷָ��!!\n", stderr);
            break;
        }
        }
        system("pause");
    } while (ord != 4);
}