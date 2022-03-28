#include "../Headers/LQueue.h"
#include "../Headers/menu.h"
#include <stdio.h>
#include <stdlib.h>
extern int head; /*datatypeͷ�±�*/
extern int tail; /*datatypeβ�±�*/

int main()
{
    int ord = 0;                                  /*���ڽ���ָ��*/
    LQueue *Q = (LQueue *)malloc(sizeof(LQueue)); /*��ʼ������*/
    Q->front = Q->rear = NULL;
    Q->length = 0;
    do /*do-while���ѡ��*/
    {
        MainMenu(); /*��ӡ���˵�*/
        ScanOrd(&ord);
        system("cls");
        switch (ord) /*���֧ѡ��*/
        {
        case 1: /*��ʼ������*/
        {
            InitLQueue(Q);
            printf("��ʼ�����!!\n");
            break;
        }
        case 2: { /*�������й���*/
            printf("�����������:\n");
            TraverseLQueue(Q, LPrint);
            break;
        }
        case 3: {                 /*�ж϶����Ƿ�Ϊ��*/
            if (Q->front == NULL) /*�ж϶����Ƿ��ʼ�����*/
            {
                fputs("����δ��ʼ��!!\n", stderr);
                break;
            }
            if (IsEmptyLQueue(Q))
            {
                printf("����Ϊ��!!\n");
            }
            else
            {
                printf("���в�Ϊ��!!\n");
            }
            break;
        }
        case 4: { /*��ȡ���׽��dataֵ*/
            void *e = malloc(50);
            if (GetHeadLQueue(Q, e))
            {
                printf("����Ԫ��Ϊ");
                LPrint(e); /*����LPrint��ӡ*/
            }
            break;
        }
        case 5: {
            LengthLQueue(Q); /*�ж϶��г���*/
            break;
        }
        case 6: {
            EnLQueueMenu(Q); /*������ӹ��ܲ˵�*/
            break;
        }
        case 7: {
            DeLQueue(Q); /*���ӹ���*/
            break;
        }
        case 8: {
            if (Q->front == NULL) /*�ж϶����Ƿ��ʼ�����*/
            {
                fputs("����δ��ʼ��!!\n", stderr);
                break;
            }
            ClearLQueue(Q);
            printf("��ն��гɹ�!!\n"); /*��ն��й���*/
            break;
        }
        case 9: {
            DestoryLQueue(Q); /*���ٶ��в��˳�*/
            break;
        }
        default: {
            fputs("��������ȷָ��!!\n", stderr);
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