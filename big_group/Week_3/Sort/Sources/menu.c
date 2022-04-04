#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/menu.h"
#include "../Headers/sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_1 10000 /*���������С�ĺ꣬����֮�����ɴ�������ʱʹ��*/
#define MAX_2 50000
#define MAX_3 200000

char *name[] = {"��������", "�鲢����", "��������(�ݹ�)", "��������(�ǵݹ�)", "��������", "��������"};
/*���name�����ڴ洢�㷨���֣�����֮���ӡ��ʾ*/

void ScanOrd(int *num) /*����ָ���*/
{
    if ((scanf("%d", num)) != 1) /*ʹ��if+scanf+do-whileѭ����ȷ������Ϸ�*/
    {
        while (getchar() != '\n')
            ;
        *num = -1;
    }
}

void MainMenu() /*���˵�����*/
{
    printf("\n\n");
    printf("                             ***************************�����㷨****************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              **************************************************************\n");
    printf("                              * 1.����������ʱ����	* 2.����С��������ʱ����	*\n");
    printf("                              **************************************************************\n");
    printf("                              * 3.��ɫ����		* 4.���������е�K����		*\n");
    printf("                              **************************************************************\n");
    printf("                              * 5.�����㷨Ч������	* 6.�˳�			*\n");
    printf("                              **************************************************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              ��ѡ��˵����:");
}

void BigDataTime() /*���Դ�������������㷨��ʱ����*/
{
    int ord = 0;  /*ord���ڽ��ղ�������ָ��*/
    int size;     /*size�������С*/
    int flag = 0; /*flag�����ж��Ƿ��������ѡ���������ѭ����Ϊ0ʱ�˳�*/
    do
    {
        system("cls"); /*��ӡ���˵�*/
        printf("\n\n");
        printf("                             *************************��������ѡ��**************************\n");
        printf("                         ------------------------------------------------------------------------\n");
        printf("                              **************************************************************\n");
        printf("                              * 1.10000������						*\n");
        printf("                              **************************************************************\n");
        printf("                              * 2.50000������						*\n");
        printf("                              **************************************************************\n");
        printf("                              * 3.200000������						*\n");
        printf("                              **************************************************************\n");
        printf("                              * 4.�˳��������ϼ��˵�					*\n");
        printf("                              **************************************************************\n");
        printf("                         ------------------------------------------------------------------------\n");
        printf("                              ��ѡ��ѡ����:");
        ScanOrd(&ord); /*��ScanOrd��ȷ������Ϸ�*/
        switch (ord)   /*switch����ѭ���ж������Ƿ���ȷ*/
        {
        case 1: /*ordΪ1��ѡ��10000������*/
        {
            flag = 1;     /*flag����Ϊ1*/
            DataGen(1);   /*����DataGen�����������ļ���д��10000������*/
            size = MAX_1; /*Ϊsize��MAX_1��ֵ*/
            break;
        }
        case 2: /*ord'Ϊ2��ѡ��50000������*/
        {
            flag = 1;     /*flag����Ϊ1*/
            DataGen(2);   /*����DataGen�����������ļ���д��50000������*/
            size = MAX_2; /*Ϊsize��MAX_2��ֵ*/
            break;
        }
        case 3: /*ord'Ϊ3��ѡ��200000������*/
        {
            flag = 1;     /*flag����Ϊ1*/
            DataGen(3);   /*����DataGen�����������ļ���д��200000������*/
            size = MAX_3; /*Ϊsize��MAX_3��ֵ*/
            break;
        }
        case 4: /*ordΪ4�������ϼ��˵�*/
        {
            return;
        }
        default: /*������벻�Ϸ�*/
        {
            fputs("������������������!!\n", stderr);
            system("pause");
            break;
        }
        }
        system("cls");
    } while (flag == 0);
    /*DataScan���ڴ��ļ��ж�ȡ��Ӧѡ���С��������*/
    int *data = DataScan(ord);                     /*data���ڽ���DataScan���ص���������*/
    int *temp = (int *)malloc(sizeof(int) * size); /*temp����֮��鲢����ʹ��*/
    int max = data[0];                             /*max���ڲ��������е����ֵ���ڼ���������ʹ��*/
    printf("���ڽ��м�⣬�����ĵȴ�\n");
    for (int i = 0; i < size; i++)
    { /*ʹ��forѭ��Ѱ���������ֵ������max*/
        /*ͬʱʹtempȫ������Ϊ0*/
        if (max < data[i])
        {
            max = data[i];
        }
        temp[i] = 0;
    }
    for (int i = 0; i < 6; i++) /*ʹ��forѭ��ѭ��ѡ���㷨���м��*/
    {
        data = DataScan(ord); /*ʹdata����Ϊδ��������*/

        clock_t start = clock(); /*��ʹ��start����ʼ��ʱ��*/
        switch (i)               /*switch���֦ѡ�񣬵��ò�ͬ�㷨���м��*/
        {
        case 0: {
            insertSort(data, size); /*��������*/
            break;
        }
        case 1: {
            MergeSort(data, 0, size - 1, temp); /*�鲢����*/
            break;
        }
        case 2: {
            QuickSort_Recursion(data, 0, size - 1); /*��������(�ݹ�)*/
            break;
        }
        case 3: {
            QuickSort(data, size); /*��������(�ǵݹ�)*/
            break;
        }
        case 4: {
            CountSort(data, size, max); /*��������*/
            break;
        }
        case 5: {
            RadixCountSort(data, size); /*��������*/
            break;
        }
        }
        clock_t diff = clock() - start; /*�������ʱ�䲢��ӡ���*/
        printf("�� %d ���������£�%s ����ʱΪ %d ms\n", size, name[i], diff);
        free(data); /*�ͷ��ڴ�*/
        data = NULL;
    }
    free(temp);
    temp == NULL;
}

void ALotOfSmallData() /*����㷨�ڴ���С����������ʱ��*/
{
    system("cls");
    printf("���ڽ���100������ѭ��100k���ԣ������ĵȴ�\n");
    DataGen(1);
    int *arr = DataScan(0);
    int max = arr[0]; /*max���ڼ�¼�������ֵ*/
                      /*������Ǽ��������򲻱ز����������ֵ*/
    for (int j = 0; j < 100; j++)
    {
        if (max < arr[j])
        {
            max = arr[j];
        }
    }
    for (int i = 0; i < 6; i++) /*��forѭ����ⲻͬ�㷨*/
    {
        clock_t start = clock();         /*startΪ��ʼʱ��*/
        for (int k = 0; k < 100000; k++) /*forѭ����ʼ����ظ�*/
        {
            int data[100] = {0};
            for (int n = 0; n < 100; n++)
            {
                data[n] = arr[n];
            }
            int temp[100] = {0}; /*temp��������֮��鲢����ʹ��*/
            int size = 100;      /*size��ʹ�����С*/
            switch (i)           /*switch���֦ѡ��*/
            {
            case 0: {
                insertSort(data, size); /*��������*/
                break;
            }
            case 1: {
                MergeSort(data, 0, size - 1, temp); /*�鲢����*/
                break;
            }
            case 2: {
                QuickSort_Recursion(data, 0, size - 1); /*��������(�ݹ�)*/
                break;
            }
            case 3: {
                QuickSort(data, size); /*��������(�ǵݹ�)*/
                break;
            }
            case 4: {
                CountSort(data, size, max); /*��������*/
                break;
            }
            case 5: {
                RadixCountSort(data, size); /*��������*/
                break;
            }
            }
        }
        clock_t diff = clock() - start; /*���ڼ������ʱ��*/
        printf("�� 100 ����������ѭ�� 100k ������£�%s ����ʱΪ %d ms\n", name[i], diff);
    }
    printf("���������!!\n");
}

void ColorSortMenu() /*��ɫ������*/
{
    system("cls");
    int data[100]; /*data�ǽ�Ҫ�������������*/
    srand((unsigned)time(NULL));
    for (int i = 0; i < 100; i++)
    {
        data[i] = rand() % 3; /*��data��ÿһ��Ԫ�������ֵ*/
    }
    printf("�ڽ�����ɫ����֮ǰ��ԭ��������:\n");
    for (int j = 1; j <= 100; j++) /*��ʾ����ǰ������*/
    {
        printf("%d  ", data[j - 1]);
        if (j % 10 == 0) /*ÿ��ʾ10���ͻ���*/
        {
            putchar('\n');
        }
    }
    putchar('\n');
    ColorSort(data, 100); /*������ɫ������*/
    printf("�ڽ�����ɫ����֮�󣬽����������:\n");
    for (int k = 1; k <= 100; k++) /*��ʾ������*/
    {
        printf("%d  ", data[k - 1]);
        if (k % 10 == 0) /*ÿ10������*/
        {
            putchar('\n');
        }
    }
    putchar('\n');
}

void FindKthMenu() /*�������е�K��������*/
{
    system("cls");
    int data[100] = {0}; /*data��ʾ����������*/
    srand((unsigned)time(NULL));
    for (int i = 0; i < 100; i++)
    {
        data[i] = rand() % 1000; /*��data���ÿһ��Ԫ�������ֵ*/
    }
    int K = 0;   /*K��ʾҪ���ҵ��ǵ�K����*/
    while (TRUE) /*while��ѭ������ȷ���û���������ȷ��Χ֮��*/
    {
        printf("100������������ɣ���������Ҫ���ҵڼ��������:");
        ScanOrd(&K);           /*ScanOrd����ȷ������ָ��Ϸ�*/
        if (K <= 0 || K > 100) /*���Ϸ������¿�ʼѭ��*/
        {
            fputs("������������������!!\n", stderr);
            system("pause");
            system("cls");
            continue;
        }
        system("cls"); /*�Ϸ����˳�ѭ��*/
        break;
    }
    int result = FindKth(data, 100, K); /*����FindKth���������ڷ����������K����*/
    printf("�ڴ������У��� %d �������Ϊ %d \n\n", K, result);
    printf("ԭ���������������(����):\n"); /*����ʾ����ú���*/
    QuickSort(data, 100);                    /*���ÿ���������������*/
    for (int n = 99; n >= 0; n--)            //*forѭ����ӡ������*/
    {
        printf("%d  ", data[n]);
        if (n % 10 == 0) /*ÿ��ӡ10���ͻ���*/
        {
            putchar('\n');
        }
    }
}

int FindKth(int *a, int size, int K) /*���������K�������ú���*/
{
    int mid = SearchKth(a, 0, size - 1); /*�ȵ���һ��SearchKth��������������ֵ�����±��mid*/
    /*size-mid��ʹ����ֵ�������еĴ�С����*/
    while (size - mid != K) /*�ж�size-mid�Ƿ�ΪҪ�ҵ�����*/
    {
        if (size - mid < K) /*size-midС��K��������ֵ�Ĵ�С��������K��*/
        {                   /*�������µ�����ֵ�������¿�ʼ�µ�ѭ��*/
            mid = SearchKth(a, 0, mid - 1);
        }
        if (size - mid > K) /*size-midС��K��������ֵ�Ĵ�С��������KС*/
        {                   /*�������µ�����ֵ�������¿�ʼ�µ�ѭ��*/
            mid = SearchKth(a, mid + 1, size - 1);
        }
    }
    /*���ҵ���ȷ������ֵ�±꣬���ظ������ֵ*/
    return a[mid];
}

void CheckSort() /*����㷨�Ƿ���ȷ����*/
{
    system("cls");
    int size = 100;             /*�������ߴ�*/
    for (int i = 0; i < 6; i++) /*forѭ����ѡ�������㷨*/
    {
        int *data = DataScan(0); /*dataÿ��ѭ������Ϊδ��������*/
        int temp[100] = {0};     /*temp����֮��鲢����ʹ��*/
        int max = data[0];       /*max����֮���������ʹ��*/
        printf("�� %s ����ǰ��ԭʼ��������:\n", name[i]);
        for (int k = 1; k <= 100; k++) /*��ӡ����ǰ�����ͬʱ���������е����ֵ*/
        {
            printf("%d  ", data[k - 1]);
            if (max < data[k - 1])
            {
                max = data[k - 1];
            }
            if (k % 10 == 0) /*ÿ��ӡ10���ͻ���*/
            {
                putchar('\n');
            }
        }
        printf("\n\n");
        switch (i) /*switch�����ò�ͬ�㷨*/
        {
        case 0: {
            insertSort(data, size); /*��������*/
            break;
        }
        case 1: {
            MergeSort(data, 0, size - 1, temp); /*�鲢����*/
            break;
        }
        case 2: {
            QuickSort_Recursion(data, 0, size - 1); /*��������(�ݹ��)*/
            break;
        }
        case 3: {
            QuickSort(data, size); /*��������(�ǵݹ��)*/
            break;
        }
        case 4: {
            CountSort(data, size, max); /*��������*/
            break;
        }
        case 5: {
            RadixCountSort(data, size); /*��������*/
            break;
        }
        }
        printf("�� %s ����󣬽����������:\n", name[i]);
        for (int n = 1; n <= 100; n++) /*��ʾ�������*/
        {
            printf("%d  ", data[n - 1]);
            if (n % 10 == 0)
            {
                putchar('\n');
            }
        }
        printf("\n\n");
    }
}
int *DataScan(int ord) /*DataScan���ڴ��ļ��ж�ȡ���ݲ���������ָ��*/
{
    int n = 0;   /*n��ʾ��������С*/
    switch (ord) /*��ord+switch���ж�ѡ����������С*/
    {
    case 0: /*0����ʾ100������*/
    {
        n = 100; /*n��Ϊ100*/
        break;
    }
    case 1: /*1����ʾ10000������*/
    {
        n = MAX_1; /*n��Ϊ10000*/
        break;
    }
    case 2: /*2����ʾ50000������*/
    {
        n = MAX_2; /*n��Ϊ50000*/
        break;
    }
    case 3: /*3����ʾ200000������*/
    {
        n = MAX_3; /*n��Ϊ200000*/
        break;
    }
    default: {
        break;
    }
    }
    FILE *fptr = fopen("data.txt", "r+"); /*��r+��ʽ���ļ����ļ�ָ��Ϊfptr*/
    if (fptr == NULL)                     /*�жϴ��Ƿ�ɹ�*/
    {
        return NULL;
    }
    int *data = (int *)malloc(sizeof(int) * n); /*data���������ݵ�����*/
    for (int i = 0; i < n && !feof(fptr); i++)  /*ʹ��forѭ����fscanf���ļ��ж�ȡ���ݵ�data*/
    {
        fscanf(fptr, "%d  ", data + i);
    }
    fclose(fptr); /*�ر��ļ�*/
    return data;
}

Status DataGen(int ord) /*�������ɺ���*/
{
    int n = 0;   /*n��ʹ�����������Ĵ�С*/
    switch (ord) /*switch��ѡ����������С*/
    {
    case 1: /*nΪ1��������10000������*/
    {
        n = MAX_1;
        break;
    }
    case 2: /*nΪ2��������50000������*/
    {
        n = MAX_2;
        break;
    }
    case 3: /*nΪ3��������200000������*/
    {
        n = MAX_3;
        break;
    }
    default: {
        return FALSE; /*���󣬷���FALSE*/
        break;
    }
    }
    int *arr = (int *)malloc(sizeof(int) * n); /*arr���Ǵ����д���ļ����ݵ�����*/
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) //��ʼ������
    {
        arr[i] = rand(); //�����������
        if (rand() % 2)
        {
            arr[i] += rand() * rand() / (rand() + 1);
            arr[i] %= n;
        }
    }
    FILE *fptr = fopen("data.txt", "w+"); /*��w+��ʽ���ļ����ļ�ָ��Ϊfptr*/
    if (fptr == NULL)                     /*�жϴ��Ƿ�ɹ�*/
    {
        return FALSE; /*ʧ�ܣ�����FALSE*/
    }
    for (int i = 0; i < n; i++) /*ʹ��forѭ��д���ļ���*/
    {
        fprintf(fptr, "%d  ", arr[i]);
    }
    fclose(fptr); /*�ر��ļ�*/
    return;
}