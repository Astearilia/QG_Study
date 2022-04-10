#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/menu.h"
#include "../Headers/heap.h"
#include <stdio.h>
#include <stdlib.h>

void ScanOrd(int *num) /*接收指令函数*/
{
    if ((scanf("%d", num)) != 1) /*使用if+scanf+do-while循环来确保输入合法*/
    {
        while (getchar() != '\n')
            ;
        *num = -1;
    }
}

void ScanInt(int *num) /*接收int数据类型函数*/
{
    int flag = 1; /*flag表示输入是否合法*/
    do
    {
        flag = 1;
        if ((scanf("%d", num)) != 1) /*使用if+scanf+do-while循环来确保输入合法*/
        {
            while (getchar() != '\n')
                ;
            flag = 0;
            fputs("输入不合法,请重新输入数据\n", stderr);
        }
    } while (flag != 1);
}

void MainMenu() /*主菜单函数*/
{
    printf("\n\n");
    printf("                           ******************************大顶堆********************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              **************************************************************\n");
    printf("                              ** 1.插入元素		**	2.获取堆最大值		**\n");
    printf("                              **************************************************************\n");
    printf("                              ** 3.堆排序	        **	4.退出		        **\n");
    printf("                              **************************************************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              请选择菜单编号:");
}

Status InsertMenu(HeapPtr H) /*插入菜单函数*/
{
    if (H->count + 1 >= 30)
    { /*确保要插入的数据个数在合理范围内*/
        fputs("堆已满!!\n", stderr);
        return ERROR;
    }
    printf("请输入想要插入的元素个数,最多30个:");
    int flag = 0;
    int nums = 0;
    do
    {
        ScanInt(&nums);           /*接收要插入的元素个数*/
        if (nums + H->count > 29) /*过多，显示错误信息*/
        {
            fputs("插入元素数量过多，请重新输入数字!!\n", stderr);
            flag = 0;
            continue;
        }
        flag = 1;
    } while (flag != 1);
    for (int i = 0; i < nums; i++) /*开始循环插入*/
    {
        printf("请输入要插入的第 %d 个数字:", i + 1);
        int tmp = 0;               /*tmp用于接收要插入的数字*/
        ScanInt(&tmp);             /*确保输入合法*/
        if (insertMaxHeap(H, tmp)) /*用返回值判断插入是否成功*/
        {
            printf("插入成功!!\n");
        }
        else
        {
            fputs("插入失败!!\n", stderr);
        }
    }
}

void SortMenu(HeapPtr H) /*排序菜单函数*/
{
    if (H->count == 0) /*判断堆中是否有元素*/
    {
        printf("堆中无元素，请先插入元素!!\n", stderr);
        return;
    }
    int tmpData[MAAX_SIZE] = {0}; /*tmpData用于存储出堆的数据*/
    int tmpNum = H->count;
    printf("该堆中的元素由大到小的顺序为:\n");
    for (int i = 0; i < tmpNum; i++) /*用for循环循环得到堆顶元素*/
    {
        tmpData[i] = getHeapMax(H);
        printf("%d ", tmpData[i]);
    }
    putchar('\n');
    for (int j = 0; j < tmpNum; j++) /*再将tmpData的值赋予堆*/
    {
        insertMaxHeap(H, tmpData[j]);
    }
    return;
}