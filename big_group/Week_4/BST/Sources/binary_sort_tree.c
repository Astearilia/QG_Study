#include "../Headers/binary_sort_tree.h"
#include "../Headers/menu.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode /*ʵ�ַǵݹ������ջ*/
{
    NodePtr Node;           /*ָ�����еĽ��*/
    struct StackNode *next; /*ָ��ջ����һ�����*/
} StackNode, *LinkStackPtr;

typedef struct LinkStack /*��ջͷ���*/
{
    LinkStackPtr top; /*ָ��ջ��ͷ���*/
    int count;        /*��¼ջ������*/
} LinkStack;

typedef struct node /*��������ö���*/
{
    NodePtr Node;      /*�����ָ��*/
    struct node *next; /*ָ��ǰ������һ���*/
} NodeQueue;

typedef struct Lqueue
{
    NodeQueue *front; //��ͷ
    NodeQueue *rear;  //��β
    int length;       //���г���
} LQueue;

NodePtr getTopLStack(LinkStack *s) /*�õ�ջ��Ԫ�غ���*/
{
    if (isEmptyLStack(s)) /*�ж���ջ�Ƿ�Ϊ��*/
    {
        fputs("ջΪ��!!\n", stderr);
        system("pause");
        return;
    } /*e���ڽ���ջ������*/
    return s->top;
}

Status isEmptyLStack(LinkStack *s) /*�ж�ջ�Ƿ�Ϊ�պ���*/
{
    if (s == NULL || s->top == NULL) /*��s==NULL��s->top==NULL���ж��Ƿ�Ϊ��*/
    {
        return true; /*Ϊ�շ���true*/
    }
    else
    {
        return false; /*��Ϊ�շ���false*/
    }
}

Status pushLStack(LinkStack *s, NodePtr node) /*��ջ����*/
{
    if (s == NULL) /*���жϽ���Ƿ�ΪNULL*/
    {
        fputs("ջδ��ʼ��!!\n", stderr);
        system("pause");
        return failed; /*ʧ�ܣ�����failed*/
    }                  /*�����½�����ڴ洢����*/
    LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));
    newNode->Node = node;
    newNode->next = s->top; /*����ջ*/
    s->top = newNode;
    s->count++;     /*��ջ��count++*/
    return succeed; /*�ɹ�������succeed*/
}

Status popLStack(LinkStack *s, NodePtr *ptrNode) /*��ջ����*/
{
    if (isEmptyLStack(s)) /*�ж�ջ�Ƿ�Ϊ��*/
    {
        fputs("ջΪ��!!\n", stderr);
        system("pause");
        return failed; /*Ϊ�գ�����failed*/
    }                  /*��Ϊ�գ���temp��ʱ�洢��ջ����ַ*/
    *ptrNode = s->top->Node;
    s->top = s->top->next; /*��ջ���Ƴ�ջ��Ԫ��*/
    s->count--;            /*count-1*/

    return succeed; /*�ɹ�������succeed*/
}

Status destroyLStack(LinkStack *s) /*����ջ����*/
{
    while (s->top != NULL) /*��whileѭ���ͷ��ڴ�*/
    {
        LinkStackPtr *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->count = 0;   /*��count��Ϊ0*/
    return succeed; /*�ɹ�������succeed*/
}

void InitLQueue(LQueue *Q) /*��ʼ�����к���*/
{
    NodeQueue *newNode = (NodeQueue *)malloc(sizeof(NodeQueue));
    if (newNode == NULL) /*�ж��Ƿ����ɳɹ�*/
    {
        fputs("�ڴ�ռ䲻��!!\n", stderr);
        return;
    }
    newNode->Node = newNode->next = NULL; /*��ͷ����data��next�ÿ�*/
    Q->front = Q->rear = newNode;         /*Q��ͷָ���βָ��ָ���½��*/
    Q->length = 0;                        /*��������Ϊ0*/
    return;
}

void DestoryLQueue(LQueue *Q) /*���ٶ��к���*/
{
    while (Q->front->next != NULL) /*ͨ��whileѭ�������ٶ���*/
    {
        LQueue *temp = Q->front; /*temp������ʱ�洢ͷָ��ָ��Ľ��*/
        Q->front = Q->front->next;
        free(temp);
    }
    free(Q);
    return;
}

Status IsEmptyLQueue(const LQueue *Q) /*�ж϶����Ƿ�Ϊ�պ���*/
{
    if (Q->length == 0) /*ͨ��Q->length��ֵ�ж϶����Ƿ�Ϊ��*/
    {
        return true;
    }
    else
    {
        return false;
    }
}

Status EnLQueue(LQueue *Q, NodePtr node) /*��Ӻ���*/
{
    if (Q->front == NULL) /*�ж϶����Ƿ��ʼ��*/
    {
        fputs("����δ��ʼ��\n", stderr);
        return failed;
    }
    if (Q->length == 29) /*�ж϶����Ƿ�����*/
    {
        fputs("��������\n", stderr);
        return;
    }
    NodeQueue *newNode = (NodeQueue *)malloc(sizeof(NodeQueue)); /*�½�������ڴ洢*data*/
    if (newNode == NULL)                                         /*�ж��Ƿ�����ڴ�ʧ��*/
    {
        fputs("��������ʧ�ܣ��ڴ�ռ䲻��\n", stderr);
        return failed;
    }
    newNode->Node = node;    /*Ϊ�½���data����ռ�*/
    newNode->next = NULL;    /*�½��->next�ÿ�*/
    Q->rear->next = newNode; /*�������β��*/
    Q->rear = newNode;
    if (Q->length == 0) /*�ж��Ƿ�˽���Ƿ�Ϊ���е�һ�����*/
    {
        Q->front->next = newNode;
    }
    Q->length++; /*������ɣ�length��ֵ+1*/
    return succeed;
}

Status GetHeadLQueue(LQueue *Q, NodePtr *node) /*�õ�����Ԫ�غ���*/
{
    if (Q->front == NULL) /*�ж϶����Ƿ��ʼ�����*/
    {
        fputs("����δ��ʼ��!!\n", stderr);
        return failed; /*δ��ʼ�����˳�������FALSE*/
    }
    if (IsEmptyLQueue(Q)) /*�ж϶����Ƿ�Ϊ��*/
    {
        fputs("����Ϊ��\n", stderr);
        return failed;
    }
    (*node) = Q->front->next->Node;
    return succeed;
}

Status DeLQueue(LQueue *Q) /*���Ӻ���*/
{
    if (Q->front == NULL) /*�ж϶����Ƿ��ʼ�����*/
    {
        fputs("����δ��ʼ��!!\n", stderr);
        return failed; /*δ��ʼ�����˳�������FALSE*/
    }
    if (IsEmptyLQueue(Q)) /*�ж϶����Ƿ�Ϊ��*/
    {
        fputs("����Ϊ��\n", stderr);
        return failed;
    }
    Q->length--;                      /*���ӣ����г���length-1*/
    NodeQueue *temp = Q->front->next; /*�ͷŶ���ͷ���Ľ��*/
    Q->front->next = Q->front->next->next;
    free(temp);
    return succeed;
}

Status BST_init(BinarySortTreePtr T) /*��ʼ����*/
{
    if (T == NULL)
    {
        return failed; /*����TΪNULL���򷵻�failed*/
    }
    T->root = NULL;
    return succeed; /*����succeed*/
}

Status BST_insert(BinarySortTreePtr T, ElemType e) /*����������*/
{
    if (BST_search(T, e)) /*���ж����Ƿ��Ѵ�����ͬԪ��*/
    {
        printf("Ԫ���Ѵ���!!\n"); /*���ڣ����ز���ʧ��*/
        return failed;
    }
    NodePtr newNode = (NodePtr)malloc(sizeof(Node)); /*�½������*/
    newNode->value = e;                              /*Ϊ����㸳ֵ*/
    newNode->left = NULL;                            /*���½��������ÿ�*/
    newNode->right = NULL;
    NodePtr tmp = T->root;
    NodePtr parent = NULL;
    if (tmp == NULL) /*�ж��������Ƿ�Ϊ��*/
    {
        T->root = newNode;
        return succeed; /*����ɹ�������succeed*/
    }
    while (tmp != NULL) /*������Ϊ�գ���ѭ���ҵ�����λ��*/
    {
        parent = tmp; /*parent���ڼ�¼tmp����һ�����*/
        if (tmp->value > e)
        {
            tmp = tmp->left;
        }
        else
        {
            tmp = tmp->right;
        }
    }
    if (parent->value > e) /*��ʱ��parent��ʼ����*/
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
    return succeed; /*����ɹ�������succeed*/
}

Status Delete_Node(NodePtr *TreeNode) /*ɾ����㺯��*/
{
    if ((*TreeNode)->right == NULL) /*���жϽ���Ƿ�ֻ��һ������or�Һ���*/
    {
        NodePtr tmp = *TreeNode; /*ֻ��һ���Ļ���ֱ�����Ͻ�����*/
        (*TreeNode) = (*TreeNode)->left;
        free(tmp);
    }
    else if ((*TreeNode)->left == NULL) /*���жϽ���Ƿ�ֻ��һ������or�Һ���*/
    {
        NodePtr tmp = *TreeNode; /*ֻ��һ���Ļ���ֱ�����Ͻ�����*/
        (*TreeNode) = (*TreeNode)->right;
        free(tmp);
    }
    else /*������ɾ�����������Һ���*/
    {
        NodePtr tmp = *TreeNode;               /*tmp���ڼ�¼searchPtr��һ�����*/
        NodePtr searchPtr = (*TreeNode)->left; /*Ŀ��ʱ�ҵ���ɾ����ǰ��*/
        while (searchPtr->right)               /*ѭ���ҵ����ɾ���Ľ��*/
        {
            tmp = searchPtr;
            searchPtr = searchPtr->right;
        }
        (*TreeNode)->value = searchPtr->value; /*Ϊ��ɾ����㸳ֵ��������������*/
        if ((*TreeNode) != tmp)                /*�жϴ�ʱtmp�Ƿ�Ϊԭ���*/
        {
            tmp->right = searchPtr->left;
        }
        else
        {
            tmp->left = searchPtr->left;
        }
        free(searchPtr); /*�ͷ�ɾ���Ľ��*/
    }
    return succeed; /*ɾ���ɹ�������succeed*/
}

Status BST_delete(BinarySortTreePtr T, ElemType e) /*ɾ����������㺯��*/
{
    if (!BST_search(T, e)) /*�Ȳ������д治���ڴ�ɾ������*/
    {
        fputs("ɾ�����ֲ�����!!\n", stderr);
        return failed; /*�����ڣ�����failed*/
    }
    NodePtr target = T->root;  /*target�����ɾ�����ָ��*/
    NodePtr parent = NULL;     /*parent��target�ĸ�ָ��*/
    int flag = 0;              /*flag�����ж�target��parent����or�Һ���*/
    while (target->value != e) /*ѭ���ҵ���ɾ��λ��*/
    {
        parent = target;
        if (target->value < e)
        {
            target = target->right;
            flag = 1; /*target��parent���ҽ�㣬flagΪ1*/
        }
        else
        {
            target = target->left;
            flag = 0; /*target��parent�����㣬flagΪ0*/
        }
    }
    if (Delete_Node(&target)) /*ִ��ɾ��������target�ᱻ��Ϊɾ�����������*/
    {
        if (parent == NULL) /*�ж�ɾ���Ľ���Ƿ�Ϊ�����*/
        {
            T->root = target; /*�Ǿ�ֱ���� T->rootΪtarget*/
        }
        else if (flag == 0) /*����targetΪparent��������*/
        {
            parent->left = target; /*parent������Ϊɾ��������*/
        }
        else
        {
            parent->right = target; /*parent������Ϊɾ��������*/
        }
        return succeed; /*ɾ���ɹ�������succeed*/
    }
    else
    {
        return failed; /*ɾ��ʧ�ܣ�����failed*/
    }
}

Status BST_search(BinarySortTreePtr T, ElemType e) /*�������ݺ���*/
{
    if (!T || !T->root) /*�ж����Ƿ�Ϊ��*/
    {
        return false;
    }
    NodePtr tmp = T->root; /*tmp���ڼ�¼Ŀǰ���*/
    while (tmp != NULL)    /*ֱ��tmpΪ�գ����ҵ�����ĩβ*/
    {
        if (tmp->value == e) /*��������ͬ��ֵ���򷵻�true*/
        {
            return true;
        }
        else
        {
            if (tmp->value < e) /*��������ݴ�С��������or������*/
            {
                tmp = tmp->right;
            }
            else
            {
                tmp = tmp->left;
            }
        }
    }
    return false; /*����tmpΪ�գ�������������δ�ҵ���ͬ��ֵ��������false*/
}

Status BST_preorderI(BinarySortTreePtr T, void (*visit)(NodePtr)) /*ǰ������ǵݹ��*/
{
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack)); /*��ʼ��ջ*/
    stack->top = NULL;
    stack->count = 0;
    NodePtr tmp = T->root;
    while (tmp != NULL || stack->count > 0) /*ѭ����������*/
    {
        if (tmp != NULL) /*�жϴ�ʱtmp�Ƿ�Ϊ��*/
        {
            printValue(tmp);        /*��Ϊ�գ���ӡֵ*/
            pushLStack(stack, tmp); /*��ջ*/
            tmp = tmp->left;        /*��ָ�������*/
        }
        else
        {
            popLStack(stack, &tmp); /*tmp��Ϊ�գ����ѱ�������*/
            tmp = tmp->right;       /*��ʼ��ȡ�ұ߽��*/
        }
    }
    destroyLStack(stack); /*����ջ*/
    stack = NULL;
    return succeed; /*����succeed*/
}

Status BST_preorderR(BinarySortTreePtr T, void (*visit)(NodePtr)) /*ǰ������ݹ��*/
{
    if (T->root == NULL) /*�ݹ��˳�����*/
    {
        return;
    }
    visit(T->root); /*��ӡֵ*/
    NodePtr tmp = T->root;
    T->root = T->root->left;
    BST_preorderR(T, visit); /*�ȶ�ȡ����*/
    T->root = tmp;
    T->root = T->root->right;
    BST_preorderR(T, visit); /*���ȡ�ҽ��*/
    T->root = tmp;
    return succeed;
}

Status BST_inorderI(BinarySortTreePtr T, void (*visit)(NodePtr)) /*��������ǵݹ��*/
{
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack)); /*��ʼ��ջ*/
    stack->top = NULL;
    stack->count = 0;
    NodePtr tmp = T->root;
    while (tmp != NULL || stack->count > 0) /*ѭ����������*/
    {
        if (tmp != NULL) /*�жϴ�ʱtmp�Ƿ�Ϊ��*/
        {
            pushLStack(stack, tmp); /*��ջ*/
            tmp = tmp->left;        /*��ָ�������*/
        }
        else
        {
            popLStack(stack, &tmp); /*tmp��Ϊ�գ����ѱ�������*/
            printValue(tmp);        /*��ӡ���ֵ*/
            tmp = tmp->right;       /*��ʼ��ȡ�ұ߽��*/
        }
    }
    destroyLStack(stack); /*����ջ*/
    stack = NULL;
    return succeed; /*����succeed*/
}

Status BST_inorderR(BinarySortTreePtr T, void (*visit)(NodePtr)) /*��������ݹ��*/
{
    if (T->root == NULL) /*�ݹ��˳�����*/
    {
        return;
    }
    NodePtr tmp = T->root;
    T->root = T->root->left;
    BST_inorderR(T, visit); /*�ȷ�������*/
    T->root = tmp;
    visit(T->root); /*��ӡֵ*/
    T->root = T->root->right;
    BST_inorderR(T, visit); /*�ٷ����ҽ��*/
    T->root = tmp;
    return succeed;
}

Status BST_postorderI(BinarySortTreePtr T, void (*visit)(NodePtr)) /*��������ǵݹ��*/
{
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack)); /*��ʼ��ջstack��stacktmp*/
    LinkStack *stacktmp = (LinkStack *)malloc(sizeof(LinkStack));
    stack->top = stacktmp->top = NULL;
    stack->count = stacktmp->count = 0;
    NodePtr tmp = T->root; /*tmp��Ϊ��ǰ��ȡ���*/
    while (tmp != NULL || stacktmp->count > 0)
    {                       /*������ջ�����ת��Ϊ�ʺϺ����������ʽ������stackջ��*/
        while (tmp != NULL) /*���������н��*/
        {
            pushLStack(stack, tmp);
            pushLStack(stacktmp, tmp);
            tmp = tmp->right;
        }
        if (stacktmp->count > 0)
        {
            popLStack(stacktmp, &tmp);
            tmp = tmp->left;
        }
    }
    while (stack->count > 0) /*��ʼ��ȡstackջ�����ݲ���ӡ*/
    {
        popLStack(stack, &tmp);
        printValue(tmp);
    }
    destroyLStack(stack); /*����ջ*/
    destroyLStack(stacktmp);
    stack = NULL;
    stacktmp = NULL;
    return succeed; /*����succeed*/
}

Status BST_postorderR(BinarySortTreePtr T, void (*visit)(NodePtr)) /*��������ݹ��*/
{
    if (T->root == NULL) /*�ݹ��˳�����*/
    {
        return;
    }
    NodePtr tmp = T->root;
    T->root = T->root->left;
    BST_postorderI(T, visit); /*�ȷ�������*/
    T->root = tmp;
    T->root = T->root->right;
    BST_postorderI(T, visit); /*�ٷ����ҽ��*/
    T->root = tmp;
    visit(T->root); /*����ӡֵ*/
    return succeed;
}

Status BST_levelOrder(BinarySortTreePtr T, void (*visit)(NodePtr)) /*�����������*/
{
    LQueue *Q = (LQueue *)malloc(sizeof(LQueue)); /*��ʼ������*/
    Q->front = Q->rear = NULL;
    Q->length = 0;
    InitLQueue(Q);
    NodePtr tmp = T->root; /*tmp����ǰ��ȡ���Ľ��ָ��*/
    EnLQueue(Q, tmp);      /*�������*/
    while (Q->length > 0)
    {
        GetHeadLQueue(Q, &tmp); /*�ȵõ��Զ�*/
        DeLQueue(Q);            /*���Ӳ���*/
        printValue(tmp);        /*��ʾ��ʱtmpָ�����ֵ*/
        if (tmp->left != NULL)
        {
            EnLQueue(Q, tmp->left); /*������ڵ����*/
        }
        if (tmp->right != NULL)
        {
            EnLQueue(Q, tmp->right); /*�����ҽ�����*/
        }
    }
    free(Q);
    Q = NULL;
    return succeed;
}