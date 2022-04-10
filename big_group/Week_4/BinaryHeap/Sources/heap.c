#include "../Headers/heap.h"
#include <stdio.h>
#include <stdlib.h>

Status inintHeap(HeapPtr H) /*��ʼ���Ѻ���*/
{
    H->count = 0;                       /*���ѵ�countֵ��Ϊ0*/
    for (int i = 0; i < MAAX_SIZE; i++) /*����������Ԫ��ֵ��Ϊ0*/
    {
        H->data[i] = 0;
    }
    return SUCCESS; /*����SUCCESS*/
}

void swapHeap(HeapPtr H, int a, int b) /*�������������±�a��bֵ����*/
{
    ElemType tmp = H->data[a];
    H->data[a] = H->data[b];
    H->data[b] = tmp;
}

Status insertMaxHeap(HeapPtr H, ElemType e) /*���빦�ܺ���*/
{
    if (H->count + 1 == MAAX_SIZE) /*�жϴ�ʱ���Ƿ�����*/
    {
        fputs("������!!\n", stderr);
        return ERROR; /*����������ERROR*/
    }
    H->data[H->count + 1] = e; /*������e��ӵ��ѵ�β��*/
    H->count++;                /*������count+1*/
    shiftUpHeap(H, H->count);  /*�Բ����Ԫ�ؽ����ϸ�����*/
    return SUCCESS;            /*����ɹ�������SUCCESS*/
}

ElemType getHeapMax(HeapPtr H) /*�õ��Զ�Ԫ�غ���*/
{
    ElemType tmp = H->data[1]; /*tmp���ڴ洢�Զ�Ԫ��ֵ*/
    swapHeap(H, 1, H->count);  /*���Զ��ڶ�β����*/
    H->count--;                /*������count-1*/
    shiftDownHeap(H, 1);       /*����ʱ�ĶѶ�Ԫ�ؽ����³�����*/
    return tmp;
}

Status shiftUpHeap(HeapPtr H, int k) /*�ϸ���������*/
{
    /*ͨ��whileѭ�����ϸ���Ԫ���ƶ�����Ӧλ��*/
    /*��ʱ�ϸ��Ľ���ֵ���������Һ��ӵ�ֵ*/
    while (k > 1 && H->data[k / 2] < H->data[k])
    {
        /*δ�ﵽ�Ѷ����ϸ����ֵ���������ڵĸ���㣬�ͽ���ֵ*/
        swapHeap(H, k, k / 2);
        k /= 2;
    }
}

Status shiftDownHeap(HeapPtr H, int k) /*�³���������*/
{
    /*ͨ��whileѭ�����³���Ԫ���ƶ�����Ӧλ��*/
    /*��ʱ�³��Ľ���ֵС�ڸ�����ֵ*/
    while (2 * k <= H->count)
    {
        /*δ�ﵽ��β*/
        int j = 2 * k;
        if (j + 1 <= H->count && H->data[j + 1] > H->data[j]) /*�ж�Ҫ��jָ�����or��*/
        {
            j++;
        }
        if (H->data[k] >= H->data[j]) /*����Ŀ��λ�ã��˳�ѭ��*/
        {
            break;
        }
        /*δ�ﵽ�Ѷ����³����ֵС�����Һ��ӵ�ֵ���ͽ���ֵ*/
        swapHeap(H, k, j);
        k = j;
    }
}