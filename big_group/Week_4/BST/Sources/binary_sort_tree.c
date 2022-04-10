#include "../Headers/binary_sort_tree.h"
#include "../Headers/menu.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode /*实现非递归遍历的栈*/
{
    NodePtr Node;           /*指向树中的结点*/
    struct StackNode *next; /*指向栈的下一个结点*/
} StackNode, *LinkStackPtr;

typedef struct LinkStack /*链栈头结点*/
{
    LinkStackPtr top; /*指向栈的头结点*/
    int count;        /*记录栈结点个数*/
} LinkStack;

typedef struct node /*层序遍历用队列*/
{
    NodePtr Node;      /*树结点指针*/
    struct node *next; /*指向当前结点的下一结点*/
} NodeQueue;

typedef struct Lqueue
{
    NodeQueue *front; //队头
    NodeQueue *rear;  //队尾
    int length;       //队列长度
} LQueue;

NodePtr getTopLStack(LinkStack *s) /*得到栈顶元素函数*/
{
    if (isEmptyLStack(s)) /*判断链栈是否为空*/
    {
        fputs("栈为空!!\n", stderr);
        system("pause");
        return;
    } /*e用于接收栈顶数据*/
    return s->top;
}

Status isEmptyLStack(LinkStack *s) /*判断栈是否为空函数*/
{
    if (s == NULL || s->top == NULL) /*用s==NULL和s->top==NULL来判断是否为空*/
    {
        return true; /*为空返回true*/
    }
    else
    {
        return false; /*不为空返回false*/
    }
}

Status pushLStack(LinkStack *s, NodePtr node) /*入栈函数*/
{
    if (s == NULL) /*先判断结点是否为NULL*/
    {
        fputs("栈未初始化!!\n", stderr);
        system("pause");
        return failed; /*失败，返回failed*/
    }                  /*创建新结点用于存储数据*/
    LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));
    newNode->Node = node;
    newNode->next = s->top; /*结点进栈*/
    s->top = newNode;
    s->count++;     /*进栈后count++*/
    return succeed; /*成功，返回succeed*/
}

Status popLStack(LinkStack *s, NodePtr *ptrNode) /*出栈函数*/
{
    if (isEmptyLStack(s)) /*判断栈是否为空*/
    {
        fputs("栈为空!!\n", stderr);
        system("pause");
        return failed; /*为空，返回failed*/
    }                  /*不为空，用temp临时存储出栈结点地址*/
    *ptrNode = s->top->Node;
    s->top = s->top->next; /*从栈中移除栈顶元素*/
    s->count--;            /*count-1*/

    return succeed; /*成功，返回succeed*/
}

Status destroyLStack(LinkStack *s) /*销毁栈函数*/
{
    while (s->top != NULL) /*用while循环释放内存*/
    {
        LinkStackPtr *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->count = 0;   /*将count设为0*/
    return succeed; /*成功，返回succeed*/
}

void InitLQueue(LQueue *Q) /*初始化队列函数*/
{
    NodeQueue *newNode = (NodeQueue *)malloc(sizeof(NodeQueue));
    if (newNode == NULL) /*判断是否生成成功*/
    {
        fputs("内存空间不足!!\n", stderr);
        return;
    }
    newNode->Node = newNode->next = NULL; /*将头结点的data和next置空*/
    Q->front = Q->rear = newNode;         /*Q的头指针和尾指针指向新结点*/
    Q->length = 0;                        /*长度设置为0*/
    return;
}

void DestoryLQueue(LQueue *Q) /*销毁队列函数*/
{
    while (Q->front->next != NULL) /*通过while循环来销毁队列*/
    {
        LQueue *temp = Q->front; /*temp用来临时存储头指针指向的结点*/
        Q->front = Q->front->next;
        free(temp);
    }
    free(Q);
    return;
}

Status IsEmptyLQueue(const LQueue *Q) /*判断队列是否为空函数*/
{
    if (Q->length == 0) /*通过Q->length的值判断队列是否为空*/
    {
        return true;
    }
    else
    {
        return false;
    }
}

Status EnLQueue(LQueue *Q, NodePtr node) /*入队函数*/
{
    if (Q->front == NULL) /*判断队列是否初始化*/
    {
        fputs("队列未初始化\n", stderr);
        return failed;
    }
    if (Q->length == 29) /*判断队列是否已满*/
    {
        fputs("队列已满\n", stderr);
        return;
    }
    NodeQueue *newNode = (NodeQueue *)malloc(sizeof(NodeQueue)); /*新建结点用于存储*data*/
    if (newNode == NULL)                                         /*判断是否分配内存失败*/
    {
        fputs("插入数据失败，内存空间不足\n", stderr);
        return failed;
    }
    newNode->Node = node;    /*为新结点的data分配空间*/
    newNode->next = NULL;    /*新结点->next置空*/
    Q->rear->next = newNode; /*插入队列尾部*/
    Q->rear = newNode;
    if (Q->length == 0) /*判断是否此结点是否为队列第一个结点*/
    {
        Q->front->next = newNode;
    }
    Q->length++; /*插入完成，length的值+1*/
    return succeed;
}

Status GetHeadLQueue(LQueue *Q, NodePtr *node) /*得到队首元素函数*/
{
    if (Q->front == NULL) /*判断队列是否初始化完成*/
    {
        fputs("队列未初始化!!\n", stderr);
        return failed; /*未初始化，退出并返回FALSE*/
    }
    if (IsEmptyLQueue(Q)) /*判断队列是否为空*/
    {
        fputs("队列为空\n", stderr);
        return failed;
    }
    (*node) = Q->front->next->Node;
    return succeed;
}

Status DeLQueue(LQueue *Q) /*出队函数*/
{
    if (Q->front == NULL) /*判断队列是否初始化完成*/
    {
        fputs("队列未初始化!!\n", stderr);
        return failed; /*未初始化，退出并返回FALSE*/
    }
    if (IsEmptyLQueue(Q)) /*判断队列是否为空*/
    {
        fputs("队列为空\n", stderr);
        return failed;
    }
    Q->length--;                      /*出队，队列长度length-1*/
    NodeQueue *temp = Q->front->next; /*释放队列头部的结点*/
    Q->front->next = Q->front->next->next;
    free(temp);
    return succeed;
}

Status BST_init(BinarySortTreePtr T) /*初始化树*/
{
    if (T == NULL)
    {
        return failed; /*若树T为NULL，则返回failed*/
    }
    T->root = NULL;
    return succeed; /*返回succeed*/
}

Status BST_insert(BinarySortTreePtr T, ElemType e) /*插入树函数*/
{
    if (BST_search(T, e)) /*先判断树是否已存在相同元素*/
    {
        printf("元素已存在!!\n"); /*存在，返回插入失败*/
        return failed;
    }
    NodePtr newNode = (NodePtr)malloc(sizeof(Node)); /*新建树结点*/
    newNode->value = e;                              /*为树结点赋值*/
    newNode->left = NULL;                            /*将新结点的左右置空*/
    newNode->right = NULL;
    NodePtr tmp = T->root;
    NodePtr parent = NULL;
    if (tmp == NULL) /*判断现在树是否为空*/
    {
        T->root = newNode;
        return succeed; /*插入成功，返回succeed*/
    }
    while (tmp != NULL) /*如若不为空，用循环找到插入位点*/
    {
        parent = tmp; /*parent用于记录tmp的上一个结点*/
        if (tmp->value > e)
        {
            tmp = tmp->left;
        }
        else
        {
            tmp = tmp->right;
        }
    }
    if (parent->value > e) /*此时用parent开始插入*/
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
    return succeed; /*插入成功，返回succeed*/
}

Status Delete_Node(NodePtr *TreeNode) /*删除结点函数*/
{
    if ((*TreeNode)->right == NULL) /*先判断结点是否只有一个左孩子or右孩子*/
    {
        NodePtr tmp = *TreeNode; /*只有一个的话就直接连上结点就行*/
        (*TreeNode) = (*TreeNode)->left;
        free(tmp);
    }
    else if ((*TreeNode)->left == NULL) /*先判断结点是否只有一个左孩子or右孩子*/
    {
        NodePtr tmp = *TreeNode; /*只有一个的话就直接连上结点就行*/
        (*TreeNode) = (*TreeNode)->right;
        free(tmp);
    }
    else /*如若待删除结点具有左右孩子*/
    {
        NodePtr tmp = *TreeNode;               /*tmp用于记录searchPtr上一个结点*/
        NodePtr searchPtr = (*TreeNode)->left; /*目标时找到待删除的前驱*/
        while (searchPtr->right)               /*循环找到替代删除的结点*/
        {
            tmp = searchPtr;
            searchPtr = searchPtr->right;
        }
        (*TreeNode)->value = searchPtr->value; /*为待删除结点赋值，进行替死操作*/
        if ((*TreeNode) != tmp)                /*判断此时tmp是否为原结点*/
        {
            tmp->right = searchPtr->left;
        }
        else
        {
            tmp->left = searchPtr->left;
        }
        free(searchPtr); /*释放删除的结点*/
    }
    return succeed; /*删除成功，返回succeed*/
}

Status BST_delete(BinarySortTreePtr T, ElemType e) /*删除二叉树结点函数*/
{
    if (!BST_search(T, e)) /*先查找树中存不存在待删除数据*/
    {
        fputs("删除数字不存在!!\n", stderr);
        return failed; /*不存在，返回failed*/
    }
    NodePtr target = T->root;  /*target代表待删除结点指针*/
    NodePtr parent = NULL;     /*parent即target的父指针*/
    int flag = 0;              /*flag用于判断target是parent的左or右孩子*/
    while (target->value != e) /*循环找到待删除位置*/
    {
        parent = target;
        if (target->value < e)
        {
            target = target->right;
            flag = 1; /*target是parent的右结点，flag为1*/
        }
        else
        {
            target = target->left;
            flag = 0; /*target是parent的左结点，flag为0*/
        }
    }
    if (Delete_Node(&target)) /*执行删除操作，target会被赋为删除结点后的子树*/
    {
        if (parent == NULL) /*判断删除的结点是否为根结点*/
        {
            T->root = target; /*是就直接让 T->root为target*/
        }
        else if (flag == 0) /*如若target为parent的左子树*/
        {
            parent->left = target; /*parent左子树为删除后子树*/
        }
        else
        {
            parent->right = target; /*parent右子树为删除后子树*/
        }
        return succeed; /*删除成功，返回succeed*/
    }
    else
    {
        return failed; /*删除失败，返回failed*/
    }
}

Status BST_search(BinarySortTreePtr T, ElemType e) /*查找数据函数*/
{
    if (!T || !T->root) /*判断树是否为空*/
    {
        return false;
    }
    NodePtr tmp = T->root; /*tmp用于记录目前结点*/
    while (tmp != NULL)    /*直到tmp为空，即找到树的末尾*/
    {
        if (tmp->value == e) /*若存在相同的值，则返回true*/
        {
            return true;
        }
        else
        {
            if (tmp->value < e) /*不是则根据大小，查找左or右子树*/
            {
                tmp = tmp->right;
            }
            else
            {
                tmp = tmp->left;
            }
        }
    }
    return false; /*如若tmp为空，即遍历完树，未找到相同的值，即返回false*/
}

Status BST_preorderI(BinarySortTreePtr T, void (*visit)(NodePtr)) /*前序遍历非递归版*/
{
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack)); /*初始化栈*/
    stack->top = NULL;
    stack->count = 0;
    NodePtr tmp = T->root;
    while (tmp != NULL || stack->count > 0) /*循环遍历整树*/
    {
        if (tmp != NULL) /*判断此时tmp是否为空*/
        {
            printValue(tmp);        /*不为空，打印值*/
            pushLStack(stack, tmp); /*入栈*/
            tmp = tmp->left;        /*先指向左儿子*/
        }
        else
        {
            popLStack(stack, &tmp); /*tmp已为空，即已遍历左结点*/
            tmp = tmp->right;       /*开始读取右边结点*/
        }
    }
    destroyLStack(stack); /*销毁栈*/
    stack = NULL;
    return succeed; /*返回succeed*/
}

Status BST_preorderR(BinarySortTreePtr T, void (*visit)(NodePtr)) /*前序遍历递归版*/
{
    if (T->root == NULL) /*递归退出条件*/
    {
        return;
    }
    visit(T->root); /*打印值*/
    NodePtr tmp = T->root;
    T->root = T->root->left;
    BST_preorderR(T, visit); /*先读取左结点*/
    T->root = tmp;
    T->root = T->root->right;
    BST_preorderR(T, visit); /*后读取右结点*/
    T->root = tmp;
    return succeed;
}

Status BST_inorderI(BinarySortTreePtr T, void (*visit)(NodePtr)) /*中序遍历非递归版*/
{
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack)); /*初始化栈*/
    stack->top = NULL;
    stack->count = 0;
    NodePtr tmp = T->root;
    while (tmp != NULL || stack->count > 0) /*循环遍历整树*/
    {
        if (tmp != NULL) /*判断此时tmp是否为空*/
        {
            pushLStack(stack, tmp); /*入栈*/
            tmp = tmp->left;        /*先指向左儿子*/
        }
        else
        {
            popLStack(stack, &tmp); /*tmp已为空，即已遍历左结点*/
            printValue(tmp);        /*打印结点值*/
            tmp = tmp->right;       /*开始读取右边结点*/
        }
    }
    destroyLStack(stack); /*销毁栈*/
    stack = NULL;
    return succeed; /*返回succeed*/
}

Status BST_inorderR(BinarySortTreePtr T, void (*visit)(NodePtr)) /*中序遍历递归版*/
{
    if (T->root == NULL) /*递归退出条件*/
    {
        return;
    }
    NodePtr tmp = T->root;
    T->root = T->root->left;
    BST_inorderR(T, visit); /*先访问左结点*/
    T->root = tmp;
    visit(T->root); /*打印值*/
    T->root = T->root->right;
    BST_inorderR(T, visit); /*再访问右结点*/
    T->root = tmp;
    return succeed;
}

Status BST_postorderI(BinarySortTreePtr T, void (*visit)(NodePtr)) /*后序遍历非递归版*/
{
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack)); /*初始化栈stack和stacktmp*/
    LinkStack *stacktmp = (LinkStack *)malloc(sizeof(LinkStack));
    stack->top = stacktmp->top = NULL;
    stack->count = stacktmp->count = 0;
    NodePtr tmp = T->root; /*tmp即为当前读取结点*/
    while (tmp != NULL || stacktmp->count > 0)
    {                       /*用两个栈将结点转化为适合后序遍历的形式，存于stack栈中*/
        while (tmp != NULL) /*遍历完所有结点*/
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
    while (stack->count > 0) /*开始读取stack栈的内容并打印*/
    {
        popLStack(stack, &tmp);
        printValue(tmp);
    }
    destroyLStack(stack); /*销毁栈*/
    destroyLStack(stacktmp);
    stack = NULL;
    stacktmp = NULL;
    return succeed; /*返回succeed*/
}

Status BST_postorderR(BinarySortTreePtr T, void (*visit)(NodePtr)) /*后序遍历递归版*/
{
    if (T->root == NULL) /*递归退出条件*/
    {
        return;
    }
    NodePtr tmp = T->root;
    T->root = T->root->left;
    BST_postorderI(T, visit); /*先访问左结点*/
    T->root = tmp;
    T->root = T->root->right;
    BST_postorderI(T, visit); /*再访问右结点*/
    T->root = tmp;
    visit(T->root); /*最后打印值*/
    return succeed;
}

Status BST_levelOrder(BinarySortTreePtr T, void (*visit)(NodePtr)) /*层序遍历函数*/
{
    LQueue *Q = (LQueue *)malloc(sizeof(LQueue)); /*初始化队列*/
    Q->front = Q->rear = NULL;
    Q->length = 0;
    InitLQueue(Q);
    NodePtr tmp = T->root; /*tmp即当前读取到的结点指针*/
    EnLQueue(Q, tmp);      /*进行入队*/
    while (Q->length > 0)
    {
        GetHeadLQueue(Q, &tmp); /*先得到对顶*/
        DeLQueue(Q);            /*出队操作*/
        printValue(tmp);        /*显示此时tmp指向结点的值*/
        if (tmp->left != NULL)
        {
            EnLQueue(Q, tmp->left); /*先让左节点入队*/
        }
        if (tmp->right != NULL)
        {
            EnLQueue(Q, tmp->right); /*后让右结点入队*/
        }
    }
    free(Q);
    Q = NULL;
    return succeed;
}