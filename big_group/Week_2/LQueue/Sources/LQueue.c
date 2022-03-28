#include "../Headers/LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int head; /*head是datatype的头部*/
extern int tail; /*tail是datatype的尾部*/

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) /*判断是否生成成功*/
    {
        fputs("内存空间不足!!\n", stderr);
        return;
    }
    newNode->data = newNode->next = NULL; /*将头结点的data和next置空*/
    Q->front = Q->rear = newNode;         /*Q的头指针和尾指针指向新结点*/
    Q->length = 0;                        /*长度设置为0*/
    head = tail = 0;                      /*设置datatype的头尾都为0*/
    datatype[0] = type = '\0';            /*清空datatype*/
    return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
    while (Q->front != NULL) /*通过while循环来销毁队列*/
    {
        LQueue *temp = Q->front; /*temp用来临时存储头指针指向的结点*/
        Q->front = Q->front->next;
        free(temp);
    }
    free(Q);
    datatype[0] = type = '\0'; /*置空datatype*/
    head = tail = 0;           /*重设datatype头尾*/
    return;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    if (Q->length == 0) /*通过Q->length的值判断队列是否为空*/
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
    if (Q->front == NULL) /*判断队列是否初始化完成*/
    {
        fputs("队列未初始化!!\n", stderr);
        return FALSE; /*未初始化，退出并返回FALSE*/
    }
    if (IsEmptyLQueue(Q)) /*判断队列是否为空*/
    {
        fputs("队列为空\n", stderr);
        return FALSE;
    }
    type = datatype[head];               /*读取头结点指向的结点data的数据类型*/
    memcpy(e, Q->front->next->data, 50); /*用memcpy来复制内存*/
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
    if (Q->front == NULL) /*判断队列是否初始化完成*/
    {
        fputs("队列未初始化!!\n", stderr);
        return FALSE; /*未初始化，退出并返回FALSE*/
    }
    if (IsEmptyLQueue(Q)) /*判断队列是否为空*/
    {
        fputs("队列为空\n", stderr);
        return FALSE;
    }
    printf("队列长度为:%d\n", Q->length); /*用Q->length的值来读取长度*/
    return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
    if (Q->front == NULL) /*判断队列是否初始化*/
    {
        fputs("队列未初始化\n", stderr);
        return FALSE;
    }
    if (Q->length == 29) /*判断队列是否已满*/
    {
        fputs("队列已满\n", stderr);
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node)); /*新建结点用于存储*data*/
    if (newNode == NULL)                          /*判断是否分配内存失败*/
    {
        fputs("插入数据失败，内存空间不足\n", stderr);
        return FALSE;
    }
    newNode->data = malloc(50);      /*为新结点的data分配空间*/
    memcpy(newNode->data, data, 50); /*复制内存，字节数为50*/
    newNode->next = NULL;            /*新结点->next置空*/
    Q->rear->next = newNode;         /*插入队列尾部*/
    Q->rear = newNode;
    if (Q->length == 0) /*判断是否此结点是否为队列第一个结点*/
    {
        Q->front->next = newNode;
    }
    tail = (tail + 1) % 30; /*tail即尾部下标+1*/
    Q->length++;            /*对30求余是为了形成循环队列*/
    return TRUE;            /*插入完成，length的值+1*/
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
    if (Q->front == NULL) /*判断队列是否初始化完成*/
    {
        fputs("队列未初始化!!\n", stderr);
        return FALSE; /*未初始化，退出并返回FALSE*/
    }
    if (IsEmptyLQueue(Q)) /*判断队列是否为空*/
    {
        fputs("队列为空\n", stderr);
        return FALSE;
    }
    printf("出队元素为:");       /*自己在这写了显示出队列的data*/
    void *e = malloc(50);        /*e用于存储队列头的data*/
    GetHeadLQueue(Q, e);         /*读取队列头元素类型*/
    type = datatype[head];       /*读取队列头的data元素类型*/
    LPrint(e);                   /*显示出队的元素*/
    head = (head + 1) % 30;      /*head+1，这么写是为了形成循环队列*/
    Q->length--;                 /*出队，队列长度length-1*/
    Node *temp = Q->front->next; /*释放队列头部的结点*/
    Q->front->next = Q->front->next->next;
    free(temp);
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
    if (Q->front == NULL) /*判断队列是否初始化完成*/
    {
        fputs("队列未初始化!!\n", stderr);
        return FALSE; /*未初始化，退出并返回FALSE*/
    }
    if (IsEmptyLQueue(Q)) /*判断队列是否为空*/
    {
        fputs("队列为空\n", stderr);
        return;
    }
    Q->length = 0;   /*先把length置0*/
    head = tail = 0; /*把datatype和head、tail初始化*/
    datatype[0] = type = '\0';
    while (Q->front->next != NULL) /*使用while循环+free使整个队列清空*/
    {                              /*除了队列不存储数据的的头结点*/
        Node *temp = Q->front->next;
        Q->front->next = Q->front->next->next;
        free(temp);
    }
    return;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{ /*foo即指向下面LPrint函数的指针*/
    if (Q->front == NULL)
    {
        printf("队列未初始化!!\n");
        return;
    }
    if (IsEmptyLQueue(Q)) /*判断队列是否为空*/
    {
        fputs("队列为空\n", stderr);
        return FALSE;
    }
    Node *temp = Q->front->next; /*得到队列头部*/
    int tempHead = head;         /*得到datatype的头部*/
    while (temp != NULL)         /*用while循环和函数指针遍历整个队列*/
    {
        type = datatype[tempHead];
        foo(temp->data);
        temp = temp->next;
        tempHead = (tempHead + 1) % 30; /*这里对30求余是为了配合循环队列*/
    }
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void *q)
{
    switch (type) /*通过读取全局变量type来获取当前显示数据的类型*/
    {             /*用switch来进行多分支选择*/
    case 'h':     /*‘h'代表short类型*/
    {
        printf("-->%hd", *(short *)q);
        break;
    }
    case 'i': /*'i' 代表 int 类型*/
    {
        printf("-->%d", *(int *)q);
        break;
    }
    case 'l': /*‘l'代表long类型*/
    {
        printf("-->%ld", *(long *)q);
        break;
    }
    case 'c': /*'c' 代表 char 类型*/
    {
        printf("-->%c", *(char *)q);
        break;
    }
    case 'f': /*'f' 代表 float 类型*/
    {
        printf("-->%f", *(float *)q);
        break;
    }
    case 'd': /*'d' 代表 double 类型*/
    {
        printf("-->%lf", *(double *)q);
        break;
    }
    case 's': /*'s' 代表 字符串*/
    {
        printf("-->%s", (char *)q);
        break;
    }
    }
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/