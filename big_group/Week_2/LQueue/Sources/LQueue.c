#include "../Headers/LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int head; /*head��datatype��ͷ��*/
extern int tail; /*tail��datatype��β��*/

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) /*�ж��Ƿ����ɳɹ�*/
    {
        fputs("�ڴ�ռ䲻��!!\n", stderr);
        return;
    }
    newNode->data = newNode->next = NULL; /*��ͷ����data��next�ÿ�*/
    Q->front = Q->rear = newNode;         /*Q��ͷָ���βָ��ָ���½��*/
    Q->length = 0;                        /*��������Ϊ0*/
    head = tail = 0;                      /*����datatype��ͷβ��Ϊ0*/
    datatype[0] = type = '\0';            /*���datatype*/
    return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
    while (Q->front != NULL) /*ͨ��whileѭ�������ٶ���*/
    {
        LQueue *temp = Q->front; /*temp������ʱ�洢ͷָ��ָ��Ľ��*/
        Q->front = Q->front->next;
        free(temp);
    }
    free(Q);
    datatype[0] = type = '\0'; /*�ÿ�datatype*/
    head = tail = 0;           /*����datatypeͷβ*/
    return;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    if (Q->length == 0) /*ͨ��Q->length��ֵ�ж϶����Ƿ�Ϊ��*/
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
    if (Q->front == NULL) /*�ж϶����Ƿ��ʼ�����*/
    {
        fputs("����δ��ʼ��!!\n", stderr);
        return FALSE; /*δ��ʼ�����˳�������FALSE*/
    }
    if (IsEmptyLQueue(Q)) /*�ж϶����Ƿ�Ϊ��*/
    {
        fputs("����Ϊ��\n", stderr);
        return FALSE;
    }
    type = datatype[head];               /*��ȡͷ���ָ��Ľ��data����������*/
    memcpy(e, Q->front->next->data, 50); /*��memcpy�������ڴ�*/
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
    if (Q->front == NULL) /*�ж϶����Ƿ��ʼ�����*/
    {
        fputs("����δ��ʼ��!!\n", stderr);
        return FALSE; /*δ��ʼ�����˳�������FALSE*/
    }
    if (IsEmptyLQueue(Q)) /*�ж϶����Ƿ�Ϊ��*/
    {
        fputs("����Ϊ��\n", stderr);
        return FALSE;
    }
    printf("���г���Ϊ:%d\n", Q->length); /*��Q->length��ֵ����ȡ����*/
    return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
    if (Q->front == NULL) /*�ж϶����Ƿ��ʼ��*/
    {
        fputs("����δ��ʼ��\n", stderr);
        return FALSE;
    }
    if (Q->length == 29) /*�ж϶����Ƿ�����*/
    {
        fputs("��������\n", stderr);
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node)); /*�½�������ڴ洢*data*/
    if (newNode == NULL)                          /*�ж��Ƿ�����ڴ�ʧ��*/
    {
        fputs("��������ʧ�ܣ��ڴ�ռ䲻��\n", stderr);
        return FALSE;
    }
    newNode->data = malloc(50);      /*Ϊ�½���data����ռ�*/
    memcpy(newNode->data, data, 50); /*�����ڴ棬�ֽ���Ϊ50*/
    newNode->next = NULL;            /*�½��->next�ÿ�*/
    Q->rear->next = newNode;         /*�������β��*/
    Q->rear = newNode;
    if (Q->length == 0) /*�ж��Ƿ�˽���Ƿ�Ϊ���е�һ�����*/
    {
        Q->front->next = newNode;
    }
    tail = (tail + 1) % 30; /*tail��β���±�+1*/
    Q->length++;            /*��30������Ϊ���γ�ѭ������*/
    return TRUE;            /*������ɣ�length��ֵ+1*/
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
    if (Q->front == NULL) /*�ж϶����Ƿ��ʼ�����*/
    {
        fputs("����δ��ʼ��!!\n", stderr);
        return FALSE; /*δ��ʼ�����˳�������FALSE*/
    }
    if (IsEmptyLQueue(Q)) /*�ж϶����Ƿ�Ϊ��*/
    {
        fputs("����Ϊ��\n", stderr);
        return FALSE;
    }
    printf("����Ԫ��Ϊ:");       /*�Լ�����д����ʾ�����е�data*/
    void *e = malloc(50);        /*e���ڴ洢����ͷ��data*/
    GetHeadLQueue(Q, e);         /*��ȡ����ͷԪ������*/
    type = datatype[head];       /*��ȡ����ͷ��dataԪ������*/
    LPrint(e);                   /*��ʾ���ӵ�Ԫ��*/
    head = (head + 1) % 30;      /*head+1����ôд��Ϊ���γ�ѭ������*/
    Q->length--;                 /*���ӣ����г���length-1*/
    Node *temp = Q->front->next; /*�ͷŶ���ͷ���Ľ��*/
    Q->front->next = Q->front->next->next;
    free(temp);
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
    if (Q->front == NULL) /*�ж϶����Ƿ��ʼ�����*/
    {
        fputs("����δ��ʼ��!!\n", stderr);
        return FALSE; /*δ��ʼ�����˳�������FALSE*/
    }
    if (IsEmptyLQueue(Q)) /*�ж϶����Ƿ�Ϊ��*/
    {
        fputs("����Ϊ��\n", stderr);
        return;
    }
    Q->length = 0;   /*�Ȱ�length��0*/
    head = tail = 0; /*��datatype��head��tail��ʼ��*/
    datatype[0] = type = '\0';
    while (Q->front->next != NULL) /*ʹ��whileѭ��+freeʹ�����������*/
    {                              /*���˶��в��洢���ݵĵ�ͷ���*/
        Node *temp = Q->front->next;
        Q->front->next = Q->front->next->next;
        free(temp);
    }
    return;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{ /*foo��ָ������LPrint������ָ��*/
    if (Q->front == NULL)
    {
        printf("����δ��ʼ��!!\n");
        return;
    }
    if (IsEmptyLQueue(Q)) /*�ж϶����Ƿ�Ϊ��*/
    {
        fputs("����Ϊ��\n", stderr);
        return FALSE;
    }
    Node *temp = Q->front->next; /*�õ�����ͷ��*/
    int tempHead = head;         /*�õ�datatype��ͷ��*/
    while (temp != NULL)         /*��whileѭ���ͺ���ָ�������������*/
    {
        type = datatype[tempHead];
        foo(temp->data);
        temp = temp->next;
        tempHead = (tempHead + 1) % 30; /*�����30������Ϊ�����ѭ������*/
    }
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void *q)
{
    switch (type) /*ͨ����ȡȫ�ֱ���type����ȡ��ǰ��ʾ���ݵ�����*/
    {             /*��switch�����ж��֧ѡ��*/
    case 'h':     /*��h'����short����*/
    {
        printf("-->%hd", *(short *)q);
        break;
    }
    case 'i': /*'i' ���� int ����*/
    {
        printf("-->%d", *(int *)q);
        break;
    }
    case 'l': /*��l'����long����*/
    {
        printf("-->%ld", *(long *)q);
        break;
    }
    case 'c': /*'c' ���� char ����*/
    {
        printf("-->%c", *(char *)q);
        break;
    }
    case 'f': /*'f' ���� float ����*/
    {
        printf("-->%f", *(float *)q);
        break;
    }
    case 'd': /*'d' ���� double ����*/
    {
        printf("-->%lf", *(double *)q);
        break;
    }
    case 's': /*'s' ���� �ַ���*/
    {
        printf("-->%s", (char *)q);
        break;
    }
    }
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/