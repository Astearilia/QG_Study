#include "../Headers/sort.h"
#include "../Headers/menu.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct QuickSortStack
{              /*��������(�ǵݹ�)ʹ�õ�ջ*/
    int *data; /*ջ���ڴ洢�����������±������*/
    int size;  /*size-1���ڼ�¼ջ���±�*/
} stack, *stackPtr;

void InitStack(stackPtr s, int size) /*��ʼ��ջ*/
{
    int *data = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) /*Ϊջ������Ԫ����Ϊ0*/
    {
        data[i] = 0;
    }
    s->data = data;
    s->size = 0;
    return;
}

void PushStack(stackPtr s, int e) /*��ջ����*/
{
    s->data[s->size] = e; /*eԪ����ջ*/
    s->size++;            /*ջ��sizeֵ+1*/
}

void Popstack(stackPtr s) /*��ջ����*/
{
    if (s->size == 0) /*�ж�ջ�Ƿ�Ϊ��*/
    {
        return;
    }
    s->size--; /*���գ�size��ֵ-1*/
}

int TopSatck(stackPtr s) /*�õ�ջ��Ԫ�غ���*/
{
    if (s != NULL)
    {
        return s->data[s->size - 1]; /*ջ��Ϊ�գ�����ջ��Ԫ��*/
    }
}

Status isEmpty(stackPtr s) /*�ж�ջ�Ƿ�Ϊ��*/
{
    if (s->size > 0) /*��Ϊ�գ�����FALSE*/
    {
        return FALSE;
    }
    else /*Ϊ�գ�����TRUE*/
    {
        return TRUE;
    }
}

void SwapNum(int *a, int i, int j) /*����������i��j�±�ָ�������*/
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}

void insertSort(int *a, int n) /*����������*/
{
    if (n < 0) /*�ж������Ƿ���Ԫ��*/
    {          /*������Ԫ�ؾ��˳�*/
        fputs("ERROR\n", stderr);
        return;
    }
    if (n == 1) /*����ֻ��һ�����ݣ�����Ҫ����*/
    {
        return;
    }
    for (int i = 1; i < n; i++) /*i��ʾ����������Ԫ�ص��±�*/
    {
        int temp = a[i]; /*temp���ڴ洢������Ԫ�ص�ֵ������֮��ʹ��*/
        int j;
        for (j = i - 1; j >= 0 && a[j] > temp; j--) /*ͨ��ѭ���ҳ�����С��temp������*/
        {
            a[j + 1] = a[j]; /*����a[j]��ֵС��temp��������Ԫ����Ҫ�������ڳ�λ�ø�temp*/
        }
        a[j + 1] = temp; /*��temp���������λ��*/
                         /*����֮��a��0~j�±��Ԫ�ض�С��temp��j+2~i�±��Ԫ��ֵ������temp*/
    }
    return;
}

void MergeArray(int *a, int begin, int mid, int end, int *temp) /*�鲢����ϲ����麯��*/
{
    int i = 0;                   /*i���ڼ�¼��ʱ��������ź����Ԫ���±�*/
    int j = begin;               /*j��ʾ�����������еĵ�ǰ�±�*/
    int k = mid + 1;             /*j��ʾ������������еĵ�ǰ�±�*/
    while (j <= mid && k <= end) /*ѭ����ֱ�������л�����������Ϊֹ*/
    {
        if (a[j] < a[k]) /*�ж���������ָ���Ԫ��ֵ��С*/
        {
            temp[i++] = a[j++]; /*С�ĸ�����ʱ����temp��֮��i��j��������һ��*/
        }
        else
        {
            temp[i++] = a[k++]; /*С�ĸ�����ʱ����temp��֮��i��k��������һ��*/
        }
    }
    while (j <= mid) /*jС��mid����k���������������У���ʱ��Ҫ�����������е�����ֵд��temp*/
    { /*��Ϊ�������е�ֵ���ĺ������е�������ʣ�µ�ֵ�϶�������temp�е����ֵ*/
        temp[i++] = a[j++];
    }
    while (k <= end) /*kС��end����k���������������У���ʱ��Ҫ�����������е�����ֵд��temp*/
    { /*��Ϊ�������е�ֵ���ĺ������е�������ʣ�µ�ֵ�϶�������temp�е����ֵ*/
        temp[i++] = a[k++];
    }

    for (int m = 0; m < i; m++) /*����ʱ�����ֵд����������a�У���beginΪ���*/
    {
        a[begin + m] = temp[m];
    }
}

void MergeSort(int *a, int begin, int end, int *temp) /*�鲢����ָ����麯��*/
{
    if (a == NULL || temp == NULL || begin > end) /*�ж��Ƿ����������ʾ������Ϣ���˳�*/
    {
        fputs("ERROR\n", stderr);
        return;
    }
    if (begin == end) /*�ж��Ƿ񵽵ݹ��������*/
    {
        return;
    }
    int mid = (begin + end) / 2; /*��Ѱ�����ֵ��е�*/

    MergeSort(a, begin, mid, temp); /*�ݹ黮����������*/
    MergeSort(a, mid + 1, end, temp);

    MergeArray(a, begin, mid, end, temp); /*��ɻ��ֺ���úϲ����������򲢺ϲ�����*/

    return;
}

void QuickSort_Recursion(int *a, int begin, int end) /*��������ݹ��*/
{
    if (begin > end) /*�ݹ�Ľ�������*/
    {
        return;
    }
    int mid = Partition(a, begin, end); /*ͨ������ȡ�з���ȷ������ֵ*/
    SwapNum(a, begin, mid);             /*������ʼ�±��ԭ���������±�ָ���ֵ*/
    int target = a[begin];              /*target�������ֵ*/
    int i = begin;                      /*i���������ʼ*/
    int j = end;                        /*j�������ĩβ*/
    while (i != j)                      /*i��j������������������*/
    {
        while (a[j] >= target && j > i) /*j�ȴ�����ĩβ��ʼ����ֱ���ҵ�С��target��ֵ���i����*/
        {
            j--;
        }
        while (a[i] <= target && j > i) /*i���������ʼ����ֱ���ҵ�����target��ֵ����j����*/
        {
            i++;
        }
        if (j > i) /*��i������j�±�ʱ���ͽ���i��jָ���ֵ���ٽ���ѭ��*/
        {
            SwapNum(a, i, j);
        }
    }                /*ѭ������֮�󣬼�i=j����ʱi��ߵ�����С��target��i�ұߵ���������target*/
    a[begin] = a[i]; /*�����ĵ�ֵ����ʼλ�õ�ֵ���н���*/
    a[i] = target;   /*�����ĵ�ֵ��Ϊ����ֵ*/
    /*���õݹ����������߿�ʼ����*/
    QuickSort_Recursion(a, begin, i - 1);
    QuickSort_Recursion(a, i + 1, end);
}

void QuickSort(int *a, int size) /*��������(�ǵݹ��)*/
{                                /*ͨ��ջ��ģ��ݹ����������ʵ�ַǵݹ�*/
    if (size == 0)               /*�ж������Ƿ�Ϊ��*/
    {
        return;
    }
    stackPtr *stack = (stackPtr)malloc(sizeof(stack)); /*����ģ��ݹ��õ�ջ*/
    InitStack(stack, 1000);                            /*��ʼ��ջ*/
    PushStack(stack, 0);                               /*�Ƚ��������±���ջ*/
    PushStack(stack, size - 1);                        /*�ٽ��������±���ջ*/
    while (!isEmpty(stack))                            /*��ջ��Ϊ��ʱ������Ҫ������������*/
    {                                        /*��Ϊ����β���Ƚ�ջ�ģ�����ջ��Ϊ�Ҳ���±�ֵ*/
        int right = TopSatck(stack);         /*�ȶ�ȡ��ջ��Ԫ�ظ���right*/
        Popstack(stack);                     /*��ջ*/
        int left = TopSatck(stack);          /*�ٶ�ȡ��ջ��Ԫ�ظ���left*/
        Popstack(stack);                     /*��ջ*/
        int mid = Partition(a, left, right); /*������ȡ�з���߿���Ч��*/
        SwapNum(a, left, mid);               /*������ʼλ�ú���Ŧλ�õ�ֵ*/
        int target = a[left];                /*target����Ŧ��ֵ*/
        int i = left, j = right;             /*left��right���ڱ�������*/
        while (i != j)                       /*��whileѭ������������*/
        {
            while (a[j] >= target && j > i) /*j�ȴ�����ĩβ��ʼ����ֱ���ҵ�С��target��ֵ���i����*/
            {
                j--;
            }
            while (a[i] <= target && j > i) /*i���������ʼ����ֱ���ҵ�����target��ֵ����j����*/
            {
                i++;
            }
            if (j > i) /*��i������j�±�ʱ���ͽ���i��jָ���ֵ���ٽ���ѭ��*/
            {
                SwapNum(a, i, j);
            }
        } /*ѭ������֮�󣬼�i=j����ʱi��ߵ�����С��target��i�ұߵ���������target*/
        a[left] = a[i]; /*�����ĵ�ֵ����ʼλ�õ�ֵ���н���*/
        a[i] = target;
        if (left <= i - 1) /*��leftС�ڵ���i-1ʱ������δ������������࣬����Ҫ������ջ*/
        {
            PushStack(stack, left);
            PushStack(stack, i - 1);
        }
        if (j + 1 <= right) /*��j+1С�ڵ���rightʱ������δ�����������Ҳ࣬����Ҫ������ջ*/
        {
            PushStack(stack, j + 1);
            PushStack(stack, right);
        }
    }
}

int Partition(int *a, int begin, int end) /*����ȡ�з�����*/
{
    int mid = (end - begin) / 2; /*�ҳ������е�*/
    /*�����⼸��if���������ж�a�����Ǹ���ֵ��Сλ���м䣬�������Ǹ�ֵ�����±�*/
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

void CountSort(int *a, int size, int max) /*����������*/
{
    int min = a[0]; /*min�Ǵ������������Сֵ*/
    for (int b = 0; b < size; b++)
    {
        if (min > a[b])
        {
            min = a[b];
        }
    }
    int length = max - min;                                     /*���ڼ��������鳤��*/
    int *count_arr = (int *)malloc(sizeof(int) * (length + 1)); /*�����������*/
    int *temp = (int *)malloc(sizeof(int) * size);              /*������ʱ�����С*/
    for (int i = 0; i < length + 1; i++)                        /*����������Ԫ��ȫ��Ϊ0*/
    {
        count_arr[i] = 0;
    }
    for (int j = 0; j < size; j++) /*����ʱ������Ϊ0��ͬʱ��ʼ����*/
    {
        temp[j] = 0;
        count_arr[a[j] - min]++;
    }
    for (int k = 1; k < length + 1; k++) /*���������ۼ�����֮ǰ��Ԫ���±꣬�õ����в���Ԫ���±�*/
    {
        count_arr[k] += count_arr[k - 1];
    }
    for (int n = size - 1; n >= 0; n--) /*Ϊ��ȷ��������ȶ��ԣ���ĩβ��ʼ����ԭ����*/
    {                                   /*ÿ��ȡһ��ԭ���飬������ʱ�����з����ڶ�Ӧλ��*/
        temp[count_arr[a[n] - min] - 1] = a[n];
        count_arr[a[n] - min]--;
    }
    for (int m = 0; m < size; m++) /*����ʱ���������ֵ����ԭ����*/
    {
        a[m] = temp[m];
    }
    free(count_arr); /*�ͷ���ʱ����ͼ���������ڴ�*/
    free(temp);
}

void RadixCountSort(int *a, int size) /*����������*/
{
    int *b = (int *)malloc(sizeof(int) * size); /*b������ʱ�洢������*/
    int max = a[0];                             /*max���ڼ�¼��������ֵ*/
    int exp = 1;                                /*exp�Ǵ���������a����Ԫ�ص�ֵ����*/
    for (int i = 0; i < size; i++)              /*forѭ���������ֵ����bΪ��*/
    {
        if (max < a[i])
        {
            max = a[i];
        }
        b[i] = 0;
    }
    while (max / exp > 0) /*ѭ����ȷ���õ�����������λ��*/
    {
        int bucket[10] = {0};          /*bucket���ڼ�¼�����ж�ȡ���ĵ�ǰֵλ����0~9��ֵ*/
        for (int j = 0; j < size; j++) /*װ��Ͱ��*/
        {
            int temp = a[j] / exp % 10;
            bucket[temp]++;
        }
        for (int k = 1; k < 10; k++) /*�ۼӣ��õ���Ӧ�±�*/
        {
            bucket[k] += bucket[k - 1];
        }
        for (int n = size - 1; n >= 0; n--) /*��β����ʼ�������ݣ�ȷ�����ݵ��ȶ���*/
        {
            int temp01 = a[n] / exp % 10;
            int temp02 = --bucket[temp01];
            b[temp02] = a[n];
        }
        for (int m = 0; m < size; m++) /*����ʱ�����ֵ����ԭ����*/
        {
            a[m] = b[m];
        }
        exp *= 10;
    }
    free(b);
}

void ColorSort(int *a, int size) /*��ɫ������*/
{
    int p1 = 0;        /*p1����ָ���źõ�0��ĩβ*/
    int p2 = 0;        /*p2��p3������ڱ������飬ͬʱ�ж�ֵ�Ƿ�Ϊ1*/
    int p3 = size - 1; /*p3����ָ���źõ�2����ʼ*/
    while (p2 <= p3)   /*��p2��p3������ʱִ��ѭ��*/
    {
        if (a[p2] == 1) /*p2ָ��Ϊ1��p2��ֵ+1*/
        {
            p2++;
        }
        else if (a[p2] == 0) /*p2ָ���ֵΪ0���ж�p1ָ���ֵ�Ƿ�Ϊ0�󽻻�*/
        {
            if (a[p1] != 0)
            {
                int temp = a[p1];
                a[p1] = a[p2];
                a[p2] = temp;
            }
            p1++; /*p1��p2�����ǰ��*/
            p2++;
        }
        else if (a[p2] == 2) /*p2ָ���ֵΪ2���ж�p3ָ���ֵ�Ƿ�Ϊ2�󽻻�*/
        {
            if (a[p3] != 2)
            {
                int temp = a[p2];
                a[p2] = a[p3];
                a[p3] = temp;
            }
            p3--; /*p3�����ǰ��*/
        }
    }
}

int SearchKth(int *a, int begin, int end) /*���ҵ�K��������*/
{
    if (begin > end)
    {
        return -1;
    }
    int mid = Partition(a, begin, end); /*����ȡ�з�ȡ����ֵ*/
    SwapNum(a, begin, mid);             /*������ʼ�±��ԭ���������±�ָ���ֵ*/
    int target = a[begin];              /*target�������ֵ*/
    int i = begin;                      /*i���������ʼ*/
    int j = end;                        /*j�������ĩβ*/
    while (i != j)                      /*i��j������������������*/
    {
        while (a[j] >= target && j > i) /*j�ȴ�����ĩβ��ʼ����ֱ���ҵ�С��target��ֵ���i����*/
        {
            j--;
        }
        while (a[i] <= target && j > i) /*i���������ʼ����ֱ���ҵ�����target��ֵ����j����*/
        {
            i++;
        }
        if (j > i)
        {
            SwapNum(a, i, j); /*��i������j�±�ʱ���ͽ���i��jָ���ֵ*/
        }
    }
    a[begin] = a[i]; /*�����ĵ�ֵ����ʼλ�õ�ֵ���н���*/
    a[i] = target;   /*�����ĵ�ֵ��Ϊ����ֵ*/
    return i;        /*���������±�*/
}