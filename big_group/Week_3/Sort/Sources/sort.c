#include "../Headers/sort.h"
#include "../Headers/menu.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct QuickSortStack
{              /*快速排序(非递归)使用的栈*/
    int *data; /*栈用于存储待排序数组下标的数组*/
    int size;  /*size-1用于记录栈顶下标*/
} stack, *stackPtr;

void InitStack(stackPtr s, int size) /*初始化栈*/
{
    int *data = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) /*为栈中所有元素设为0*/
    {
        data[i] = 0;
    }
    s->data = data;
    s->size = 0;
    return;
}

void PushStack(stackPtr s, int e) /*入栈操作*/
{
    s->data[s->size] = e; /*e元素入栈*/
    s->size++;            /*栈的size值+1*/
}

void Popstack(stackPtr s) /*出栈操作*/
{
    if (s->size == 0) /*判断栈是否为空*/
    {
        return;
    }
    s->size--; /*不空，size的值-1*/
}

int TopSatck(stackPtr s) /*得到栈顶元素函数*/
{
    if (s != NULL)
    {
        return s->data[s->size - 1]; /*栈不为空，返回栈顶元素*/
    }
}

Status isEmpty(stackPtr s) /*判断栈是否为空*/
{
    if (s->size > 0) /*不为空，返回FALSE*/
    {
        return FALSE;
    }
    else /*为空，返回TRUE*/
    {
        return TRUE;
    }
}

void SwapNum(int *a, int i, int j) /*交换数组中i，j下标指向的数据*/
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}

void insertSort(int *a, int n) /*插入排序函数*/
{
    if (n < 0) /*判断数组是否有元素*/
    {          /*数组无元素就退出*/
        fputs("ERROR\n", stderr);
        return;
    }
    if (n == 1) /*数组只有一个数据，不需要排序*/
    {
        return;
    }
    for (int i = 1; i < n; i++) /*i表示待插入数组元素的下标*/
    {
        int temp = a[i]; /*temp用于存储待插入元素的值，方便之后使用*/
        int j;
        for (j = i - 1; j >= 0 && a[j] > temp; j--) /*通过循环找出数组小于temp的序列*/
        {
            a[j + 1] = a[j]; /*假如a[j]的值小于temp，则数组元素需要右移以腾出位置给temp*/
        }
        a[j + 1] = temp; /*将temp插入待插入位置*/
                         /*插入之后a的0~j下标的元素都小于temp，j+2~i下标的元素值都大于temp*/
    }
    return;
}

void MergeArray(int *a, int begin, int mid, int end, int *temp) /*归并排序合并数组函数*/
{
    int i = 0;                   /*i用于记录临时数组的已排好序的元素下标*/
    int j = begin;               /*j表示待排序左序列的当前下标*/
    int k = mid + 1;             /*j表示待排序的有序列的当前下标*/
    while (j <= mid && k <= end) /*循环，直到左序列或右序列走完为止*/
    {
        if (a[j] < a[k]) /*判断左右序列指向的元素值大小*/
        {
            temp[i++] = a[j++]; /*小的赋予临时数组temp，之后i，j各往后走一步*/
        }
        else
        {
            temp[i++] = a[k++]; /*小的赋予临时数组temp，之后i，k各往后走一步*/
        }
    }
    while (j <= mid) /*j小于mid，即k已走完数组右序列，此时需要把数组左序列的所有值写入temp*/
    { /*因为左，右序列的值已拍好序，所有的左序列剩下的值肯定均大于temp中的最大值*/
        temp[i++] = a[j++];
    }
    while (k <= end) /*k小于end，即k已走完数组左序列，此时需要把数组右序列的所有值写入temp*/
    { /*因为左，右序列的值已拍好序，所有的右序列剩下的值肯定均大于temp中的最大值*/
        temp[i++] = a[k++];
    }

    for (int m = 0; m < i; m++) /*将临时数组的值写入排序数组a中，以begin为起点*/
    {
        a[begin + m] = temp[m];
    }
}

void MergeSort(int *a, int begin, int end, int *temp) /*归并排序分割数组函数*/
{
    if (a == NULL || temp == NULL || begin > end) /*判断是否出错，出错显示错误信息并退出*/
    {
        fputs("ERROR\n", stderr);
        return;
    }
    if (begin == end) /*判断是否到递归结束条件*/
    {
        return;
    }
    int mid = (begin + end) / 2; /*找寻待划分的中点*/

    MergeSort(a, begin, mid, temp); /*递归划分左右数组*/
    MergeSort(a, mid + 1, end, temp);

    MergeArray(a, begin, mid, end, temp); /*完成划分后调用合并函数，排序并合并数组*/

    return;
}

void QuickSort_Recursion(int *a, int begin, int end) /*快速排序递归版*/
{
    if (begin > end) /*递归的结束条件*/
    {
        return;
    }
    int mid = Partition(a, begin, end); /*通过三数取中法来确定枢轴值*/
    SwapNum(a, begin, mid);             /*交换起始下标和原数组枢轴下标指向的值*/
    int target = a[begin];              /*target即枢轴的值*/
    int i = begin;                      /*i即数组的起始*/
    int j = end;                        /*j即数组的末尾*/
    while (i != j)                      /*i，j出发，遍历整个数组*/
    {
        while (a[j] >= target && j > i) /*j先从数组末尾开始出发直到找到小于target的值或和i相遇*/
        {
            j--;
        }
        while (a[i] <= target && j > i) /*i后从数组起始出发直到找到大于target的值或与j相遇*/
        {
            i++;
        }
        if (j > i) /*当i不等于j下标时，就交换i，j指向的值，再进行循环*/
        {
            SwapNum(a, i, j);
        }
    }                /*循环结束之后，即i=j，此时i左边的数均小于target，i右边的数均大于target*/
    a[begin] = a[i]; /*将中心的值与起始位置的值进行交换*/
    a[i] = target;   /*将中心的值赋为枢轴值*/
    /*再用递归对数组的两边开始排序*/
    QuickSort_Recursion(a, begin, i - 1);
    QuickSort_Recursion(a, i + 1, end);
}

void QuickSort(int *a, int size) /*快速排序(非递归版)*/
{                                /*通过栈来模拟递归情况，进而实现非递归*/
    if (size == 0)               /*判断数组是否为空*/
    {
        return;
    }
    stackPtr *stack = (stackPtr)malloc(sizeof(stack)); /*生成模拟递归用的栈*/
    InitStack(stack, 1000);                            /*初始化栈*/
    PushStack(stack, 0);                               /*先将数组左下标入栈*/
    PushStack(stack, size - 1);                        /*再将数组右下标入栈*/
    while (!isEmpty(stack))                            /*当栈不为空时，即需要继续进行排序*/
    {                                        /*因为都是尾部先进栈的，所以栈顶为右侧的下标值*/
        int right = TopSatck(stack);         /*先读取出栈顶元素赋予right*/
        Popstack(stack);                     /*出栈*/
        int left = TopSatck(stack);          /*再读取出栈顶元素赋予left*/
        Popstack(stack);                     /*出栈*/
        int mid = Partition(a, left, right); /*用三数取中法提高快排效率*/
        SwapNum(a, left, mid);               /*交换起始位置和枢纽位置的值*/
        int target = a[left];                /*target即枢纽的值*/
        int i = left, j = right;             /*left和right用于遍历数组*/
        while (i != j)                       /*用while循环来遍历数组*/
        {
            while (a[j] >= target && j > i) /*j先从数组末尾开始出发直到找到小于target的值或和i相遇*/
            {
                j--;
            }
            while (a[i] <= target && j > i) /*i后从数组起始出发直到找到大于target的值或与j相遇*/
            {
                i++;
            }
            if (j > i) /*当i不等于j下标时，就交换i，j指向的值，再进行循环*/
            {
                SwapNum(a, i, j);
            }
        } /*循环结束之后，即i=j，此时i左边的数均小于target，i右边的数均大于target*/
        a[left] = a[i]; /*将中心的值与起始位置的值进行交换*/
        a[i] = target;
        if (left <= i - 1) /*当left小于等于i-1时，即还未遍历完数组左侧，故需要继续进栈*/
        {
            PushStack(stack, left);
            PushStack(stack, i - 1);
        }
        if (j + 1 <= right) /*当j+1小于等于right时，即还未遍历完数组右侧，故需要继续进栈*/
        {
            PushStack(stack, j + 1);
            PushStack(stack, right);
        }
    }
}

int Partition(int *a, int begin, int end) /*三数取中法函数*/
{
    int mid = (end - begin) / 2; /*找出数组中点*/
    /*以下这几个if都是用于判断a数组那个数值大小位于中间，并返回那个值所在下标*/
    if (a[begin] < a[mid])
    {
        if (a[mid] < a[end])
        {
            return mid;
        }
        else
        {
            if (a[begin] > a[end])
            {
                return begin;
            }
            else
            {
                return end;
            }
        }
    }
    else
    {
        if (a[mid] > a[end])
        {
            return mid;
        }
        else
        {
            if (a[begin] < a[end])
            {
                return begin;
            }
            else
            {
                return end;
            }
        }
    }
}

void CountSort(int *a, int size, int max) /*计数排序函数*/
{
    int min = a[0]; /*min是待排序数组的最小值*/
    for (int b = 0; b < size; b++)
    {
        if (min > a[b])
        {
            min = a[b];
        }
    }
    int length = max - min;                                     /*用于计数的数组长度*/
    int *count_arr = (int *)malloc(sizeof(int) * (length + 1)); /*定义计数数组*/
    int *temp = (int *)malloc(sizeof(int) * size);              /*定义临时数组大小*/
    for (int i = 0; i < length + 1; i++)                        /*将计数数组元素全设为0*/
    {
        count_arr[i] = 0;
    }
    for (int j = 0; j < size; j++) /*将临时数组设为0，同时开始计数*/
    {
        temp[j] = 0;
        count_arr[a[j] - min]++;
    }
    for (int k = 1; k < length + 1; k++) /*计数数组累加数组之前的元素下标，得到所有插入元素下标*/
    {
        count_arr[k] += count_arr[k - 1];
    }
    for (int n = size - 1; n >= 0; n--) /*为了确保插入的稳定性，从末尾开始遍历原数组*/
    {                                   /*每读取一次原数组，就在临时数组中放置在对应位置*/
        temp[count_arr[a[n] - min] - 1] = a[n];
        count_arr[a[n] - min]--;
    }
    for (int m = 0; m < size; m++) /*将临时数组的所有值赋予原数组*/
    {
        a[m] = temp[m];
    }
    free(count_arr); /*释放临时数组和计数数组的内存*/
    free(temp);
}

void RadixCountSort(int *a, int size) /*基数排序函数*/
{
    int *b = (int *)malloc(sizeof(int) * size); /*b用于临时存储排序结果*/
    int max = a[0];                             /*max用于记录数组的最大值*/
    int exp = 1;                                /*exp是待会用来除a数组元素的值的数*/
    for (int i = 0; i < size; i++)              /*for循环来找最大值和设b为空*/
    {
        if (max < a[i])
        {
            max = a[i];
        }
        b[i] = 0;
    }
    while (max / exp > 0) /*循环来确保得到了数组的最高位数*/
    {
        int bucket[10] = {0};          /*bucket用于记录数组中读取到的当前值位数与0~9的值*/
        for (int j = 0; j < size; j++) /*装入桶中*/
        {
            int temp = a[j] / exp % 10;
            bucket[temp]++;
        }
        for (int k = 1; k < 10; k++) /*累加，得到对应下标*/
        {
            bucket[k] += bucket[k - 1];
        }
        for (int n = size - 1; n >= 0; n--) /*从尾部开始遍历数据，确保数据的稳定性*/
        {
            int temp01 = a[n] / exp % 10;
            int temp02 = --bucket[temp01];
            b[temp02] = a[n];
        }
        for (int m = 0; m < size; m++) /*将临时数组的值赋予原数组*/
        {
            a[m] = b[m];
        }
        exp *= 10;
    }
    free(b);
}

void ColorSort(int *a, int size) /*颜色排序函数*/
{
    int p1 = 0;        /*p1用于指向排好的0的末尾*/
    int p2 = 0;        /*p2与p3结合用于遍历数组，同时判断值是否为1*/
    int p3 = size - 1; /*p3用于指向排好的2的起始*/
    while (p2 <= p3)   /*当p2与p3不相遇时执行循环*/
    {
        if (a[p2] == 1) /*p2指向为1，p2的值+1*/
        {
            p2++;
        }
        else if (a[p2] == 0) /*p2指向的值为0，判断p1指向的值是否为0后交换*/
        {
            if (a[p1] != 0)
            {
                int temp = a[p1];
                a[p1] = a[p2];
                a[p2] = temp;
            }
            p1++; /*p1和p2都向后前进*/
            p2++;
        }
        else if (a[p2] == 2) /*p2指向的值为2，判断p3指向的值是否为2后交换*/
        {
            if (a[p3] != 2)
            {
                int temp = a[p2];
                a[p2] = a[p3];
                a[p3] = temp;
            }
            p3--; /*p3都向后前进*/
        }
    }
}

int SearchKth(int *a, int begin, int end) /*查找第K大数函数*/
{
    if (begin > end)
    {
        return -1;
    }
    int mid = Partition(a, begin, end); /*三数取中法取枢轴值*/
    SwapNum(a, begin, mid);             /*交换起始下标和原数组枢轴下标指向的值*/
    int target = a[begin];              /*target即枢轴的值*/
    int i = begin;                      /*i即数组的起始*/
    int j = end;                        /*j即数组的末尾*/
    while (i != j)                      /*i，j出发，遍历整个数组*/
    {
        while (a[j] >= target && j > i) /*j先从数组末尾开始出发直到找到小于target的值或和i相遇*/
        {
            j--;
        }
        while (a[i] <= target && j > i) /*i后从数组起始出发直到找到大于target的值或与j相遇*/
        {
            i++;
        }
        if (j > i)
        {
            SwapNum(a, i, j); /*当i不等于j下标时，就交换i，j指向的值*/
        }
    }
    a[begin] = a[i]; /*将中心的值与起始位置的值进行交换*/
    a[i] = target;   /*将中心的值赋为枢轴值*/
    return i;        /*返回中心下标*/
}