#ifndef BINARY_HEAP
#define BINARY_HEAP

#include <stdio.h>
#include <stdlib.h>

#define MAAX_SIZE 30

typedef int ElemType; /*数据类型*/

typedef struct BinaryHeap
{
    ElemType data[MAAX_SIZE];
    int count;
} Heap, *HeapPtr; /*堆的结构体定义*/

typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

Status inintHeap(HeapPtr H);                 /*初始化堆函数*/
Status insertMaxHeap(HeapPtr H, ElemType e); /*将元素插入堆函数*/
Status shiftUpHeap(HeapPtr H, int k);        /*上浮操作函数*/
Status shiftDownHeap(HeapPtr H, int k);      /*下沉操作函数*/
ElemType getHeapMax(HeapPtr H);              /*得到堆顶元素函数*/

#endif