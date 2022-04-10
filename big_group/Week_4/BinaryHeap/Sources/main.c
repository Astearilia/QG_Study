#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/heap.h"
#include "../Headers/menu.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    HeapPtr H = (HeapPtr)malloc(sizeof(Heap)); /*初始化堆*/
    inintHeap(H);
    int ord = 0; /*ord用于接收指令*/
    do
    {
        system("cls");
        MainMenu();
        ScanOrd(&ord); /*用ScanOrd确保输入合法*/
        system("cls");
        switch (ord)
        {
        case 1: {
            InsertMenu(H); /*插入菜单函数*/
            break;
        }
        case 2: /*显示堆最大值*/
        {
            if (H->count == 0)
            {
                fputs("堆中无元素，请先插入元素!!\n", stderr);
            }
            else
            {
                printf("堆中最大元素为：%d\n", H->data[1]);
            }
            break;
        }
        case 3: /*堆排序函数*/
        {
            SortMenu(H);
            break;
        }
        case 4: {
            break;
        }
        default: /*确保输入合法*/
        {
            fputs("请输入正确指令!!\n", stderr);
            break;
        }
        }
        system("pause");
    } while (ord != 4);
}