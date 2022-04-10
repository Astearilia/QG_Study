#ifndef BINARY_HEAP
#define BINARY_HEAP

#include <stdio.h>
#include <stdlib.h>

#define MAAX_SIZE 30

typedef int ElemType; /*��������*/

typedef struct BinaryHeap
{
    ElemType data[MAAX_SIZE];
    int count;
} Heap, *HeapPtr; /*�ѵĽṹ�嶨��*/

typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

Status inintHeap(HeapPtr H);                 /*��ʼ���Ѻ���*/
Status insertMaxHeap(HeapPtr H, ElemType e); /*��Ԫ�ز���Ѻ���*/
Status shiftUpHeap(HeapPtr H, int k);        /*�ϸ���������*/
Status shiftDownHeap(HeapPtr H, int k);      /*�³���������*/
ElemType getHeapMax(HeapPtr H);              /*�õ��Ѷ�Ԫ�غ���*/

#endif