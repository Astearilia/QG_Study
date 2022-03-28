#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/menu.h"
#include "../Headers/LQueue.h"
#include <stdio.h>
#include <stdlib.h>

extern int head = 0; /*head为datatype头部*/
extern int tail = 0; /*tail为datatype尾部*/

void ScanOrd(int *num) /*接收指令函数*/
{
    if ((scanf("%d", num)) != 1) /*使用if+scanf+do-while循环来确保输入合法*/
    {
        while (getchar() != '\n')
            ;
        *num = -1;
    }
}

void ScanShort(short *num) /*接收short数据类型函数*/
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

void ScanLong(long *num) /*接收long数据类型函数*/
{
    int flag = 1; /*flag表示输入是否合法*/
    do
    {
        flag = 1;
        if ((scanf("%ld", num)) != 1) /*使用if+scanf+do-while循环来确保输入合法*/
        {
            while (getchar() != '\n')
                ;
            flag = 0;
            fputs("输入不合法,请重新输入数据\n", stderr);
        }
    } while (flag != 1);
}

void ScanFloat(float *d) /*接收float类型数值函数*/
{
    int flag = 1; /*flag表示输入是否合法*/
    do
    {
        flag = 1;
        if ((scanf("%f", d)) != 1) /*使用if+scanf+do-while循环来确保输入合法*/
        {
            while (getchar() != '\n')
                ;
            flag = 0;
            fputs("输入不合法,请重新输入数据\n", stderr);
        }
    } while (flag != 1);
}

void ScanDouble(double *d) /*接收double类型数值函数*/
{
    int flag = 1; /*flag表示输入是否合法*/
    do
    {
        flag = 1;
        if ((scanf("%lf", d)) != 1) /*使用if+scanf+do-while循环来确保输入合法*/
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
    printf("                         ******************************泛型队列ADT******************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              **************************************************************\n");
    printf("                              * 1.初始化队列		**	2.遍历队列		*\n");
    printf("                              **************************************************************\n");
    printf("                              * 3.检查队列是否为空	**	4.查看队头元素		*\n");
    printf("                              **************************************************************\n");
    printf("                              * 5.确定队列长度		**	6.入队操作		*\n");
    printf("                              **************************************************************\n");
    printf("                              * 7.出队操作		**	8.清空队列		*\n");
    printf("                              **************************************************************\n");
    printf("                              * 9.		销毁队列并退出系统			*\n");
    printf("                              **************************************************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              请选择菜单编号:");
}

void EnLQueueMenu(LQueue *Q) /*入队功能函数*/
{
    if (Q == NULL || Q->front == NULL)
    {
        fputs("队列未初始化!!\n", stderr);
        return;
    }
    int ord; /*ord用于接收指令*/
    do
    {
        printf("1-代表short类型，2-代表int类型，3-代表long类型，4-代表char类型 \n");
        printf("5-代表float类型，6-代表double类型，7-代表字符串，8-返回主菜单\n");
        printf("请输入想要插入的数据类型:");
        ScanOrd(&ord);             /*调用ScanOrd来确保输入合法*/
        void *target = malloc(50); /*target用于存储接收的data*/
        switch (ord)               /*switch多重选择*/
        {
        case 1: {
            target = (short *)target; /*转换target类型*/
            printf("请输入想要入队的short类型数据:");
            ScanShort(target);
            datatype[tail] = 'h'; /*给datatype赋值*/
            break;
        }
        case 2: {
            target = (int *)target; /*转换target类型*/
            printf("请输入想要入队的int类型数据:");
            ScanInt(target);
            datatype[tail] = 'i'; /*给datatype赋值*/
            break;
        }
        case 3: {
            target = (long *)target; /*转换target类型*/
            printf("请输入想要入队的long类型数据:");
            ScanInt(target);
            datatype[tail] = 'l'; /*给datatype赋值*/
            break;
        }
        case 4: {
            target = (char *)target; /*转换target类型*/
            printf("请输入想要插入的char类型数据:");
            getchar(); /*getchar是为了消掉回车符*/
            scanf("%c", target);
            datatype[tail] = 'c'; /*给datatype赋值*/
            break;
        }
        case 5: {
            target = (float *)target; /*转换target类型*/
            printf("请输入想要插入的float类型数据:");
            ScanFloat(target);
            datatype[tail] = 'f'; /*给datatype赋值*/
            break;
        }
        case 6: {
            target = (double *)target; /*转换target类型*/
            printf("请输入想要插入的double类型数据:");
            ScanDouble(target);
            datatype[tail] = 'd'; /*给datatype赋值*/
            break;
        }
        case 7: {
            target = (char *)target; /*转换target类型*/
            printf("请输入想要入队的字符串，限制在50个字符内哦:");
            scanf("%s", target);
            datatype[tail] = 's'; /*给datatype赋值*/
            break;
        }
        case 8: {
            break;
        }
        default: {
            fputs("指令错误，请重新输入!!\n", stderr); /*处理错误指令*/
            system("pause");
            break;
        }
        }
        if (ord >= 1 && ord <= 7) /*开始入队*/
        {
            if (EnLQueue(Q, target)) /*用EnLQueue返回值判断是否入队成功*/
            {
                printf("入队成功!\n");
            }
            else
            {
                printf("入队失败!\n");
            }
        }
        if (ord != 8)
        {
            system("pause");
            system("cls");
        }
    } while (ord != 8);
}