#include "../Headers/heap.h"
#include <stdio.h>
#include <stdlib.h>

Status inintHeap(HeapPtr H) /*初始化堆函数*/
{
    H->count = 0;                       /*将堆的count值设为0*/
    for (int i = 0; i < MAAX_SIZE; i++) /*将堆中所有元素值设为0*/
    {
        H->data[i] = 0;
    }
    return SUCCESS; /*返回SUCCESS*/
}

void swapHeap(HeapPtr H, int a, int b) /*交换堆中数组下标a，b值函数*/
{
    ElemType tmp = H->data[a];
    H->data[a] = H->data[b];
    H->data[b] = tmp;
}

Status insertMaxHeap(HeapPtr H, ElemType e) /*插入功能函数*/
{
    if (H->count + 1 == MAAX_SIZE) /*判断此时堆是否已满*/
    {
        fputs("堆已满!!\n", stderr);
        return ERROR; /*已满，返回ERROR*/
    }
    H->data[H->count + 1] = e; /*将数据e添加到堆的尾部*/
    H->count++;                /*计数的count+1*/
    shiftUpHeap(H, H->count);  /*对插入的元素进行上浮操作*/
    return SUCCESS;            /*插入成功，返回SUCCESS*/
}

ElemType getHeapMax(HeapPtr H) /*得到对顶元素函数*/
{
    ElemType tmp = H->data[1]; /*tmp用于存储对顶元素值*/
    swapHeap(H, 1, H->count);  /*将对顶于堆尾互换*/
    H->count--;                /*计数的count-1*/
    shiftDownHeap(H, 1);       /*对临时的堆顶元素进行下沉操作*/
    return tmp;
}

Status shiftUpHeap(HeapPtr H, int k) /*上浮操作函数*/
{
    /*通过while循环让上浮的元素移动到对应位置*/
    /*此时上浮的结点的值均大于左右孩子的值*/
    while (k > 1 && H->data[k / 2] < H->data[k])
    {
        /*未达到堆顶且上浮结点值大于他现在的父结点，就交换值*/
        swapHeap(H, k, k / 2);
        k /= 2;
    }
}

Status shiftDownHeap(HeapPtr H, int k) /*下沉操作函数*/
{
    /*通过while循环让下沉的元素移动到对应位置*/
    /*此时下沉的结点的值小于父结点的值*/
    while (2 * k <= H->count)
    {
        /*未达到堆尾*/
        int j = 2 * k;
        if (j + 1 <= H->count && H->data[j + 1] > H->data[j]) /*判断要往j指向的左or右*/
        {
            j++;
        }
        if (H->data[k] >= H->data[j]) /*到达目标位置，退出循环*/
        {
            break;
        }
        /*未达到堆顶且下沉结点值小于左右孩子的值，就交换值*/
        swapHeap(H, k, j);
        k = j;
    }
}