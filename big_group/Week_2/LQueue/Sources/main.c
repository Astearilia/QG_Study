#include "../Headers/LQueue.h"
#include "../Headers/menu.h"
#include <stdio.h>
#include <stdlib.h>
extern int head; /*datatype头下标*/
extern int tail; /*datatype尾下标*/

int main()
{
    int ord = 0;                                  /*用于接收指令*/
    LQueue *Q = (LQueue *)malloc(sizeof(LQueue)); /*初始化队列*/
    Q->front = Q->rear = NULL;
    Q->length = 0;
    do /*do-while多次选择*/
    {
        MainMenu(); /*打印主菜单*/
        ScanOrd(&ord);
        system("cls");
        switch (ord) /*多分支选择*/
        {
        case 1: /*初始化队列*/
        {
            InitLQueue(Q);
            printf("初始化完成!!\n");
            break;
        }
        case 2: { /*遍历队列功能*/
            printf("遍历结果如下:\n");
            TraverseLQueue(Q, LPrint);
            break;
        }
        case 3: {                 /*判断队列是否为空*/
            if (Q->front == NULL) /*判断队列是否初始化完成*/
            {
                fputs("队列未初始化!!\n", stderr);
                break;
            }
            if (IsEmptyLQueue(Q))
            {
                printf("队列为空!!\n");
            }
            else
            {
                printf("队列不为空!!\n");
            }
            break;
        }
        case 4: { /*读取队首结点data值*/
            void *e = malloc(50);
            if (GetHeadLQueue(Q, e))
            {
                printf("队首元素为");
                LPrint(e); /*调用LPrint打印*/
            }
            break;
        }
        case 5: {
            LengthLQueue(Q); /*判断队列长度*/
            break;
        }
        case 6: {
            EnLQueueMenu(Q); /*调用入队功能菜单*/
            break;
        }
        case 7: {
            DeLQueue(Q); /*出队功能*/
            break;
        }
        case 8: {
            if (Q->front == NULL) /*判断队列是否初始化完成*/
            {
                fputs("队列未初始化!!\n", stderr);
                break;
            }
            ClearLQueue(Q);
            printf("清空队列成功!!\n"); /*清空队列功能*/
            break;
        }
        case 9: {
            DestoryLQueue(Q); /*销毁队列并退出*/
            break;
        }
        default: {
            fputs("请输入正确指令!!\n", stderr);
            break;
        }
        }
        if (ord != 9)
        {
            system("pause");
            system("cls");
        }
    } while (ord != 9);
}