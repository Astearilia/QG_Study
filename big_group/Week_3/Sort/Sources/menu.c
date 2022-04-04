#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/menu.h"
#include "../Headers/sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_1 10000 /*定义数组大小的宏，方便之后生成大量数据时使用*/
#define MAX_2 50000
#define MAX_3 200000

char *name[] = {"插入排序", "归并排序", "快速排序(递归)", "快速排序(非递归)", "计数排序", "基数排序"};
/*这个name是用于存储算法名字，方便之后打印显示*/

void ScanOrd(int *num) /*接收指令函数*/
{
    if ((scanf("%d", num)) != 1) /*使用if+scanf+do-while循环来确保输入合法*/
    {
        while (getchar() != '\n')
            ;
        *num = -1;
    }
}

void MainMenu() /*主菜单函数*/
{
    printf("\n\n");
    printf("                             ***************************排序算法****************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              **************************************************************\n");
    printf("                              * 1.大数据量用时测试	* 2.大量小数据量用时测试	*\n");
    printf("                              **************************************************************\n");
    printf("                              * 3.颜色排序		* 4.查找数组中第K大数		*\n");
    printf("                              **************************************************************\n");
    printf("                              * 5.排序算法效果检验	* 6.退出			*\n");
    printf("                              **************************************************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              请选择菜单编号:");
}

void BigDataTime() /*测试大量数据情况下算法用时函数*/
{
    int ord = 0;  /*ord用于接收测试用量指令*/
    int size;     /*size是数组大小*/
    int flag = 0; /*flag用于判断是否继续进行选择测试用量循环，为0时退出*/
    do
    {
        system("cls"); /*打印主菜单*/
        printf("\n\n");
        printf("                             *************************测试用量选择**************************\n");
        printf("                         ------------------------------------------------------------------------\n");
        printf("                              **************************************************************\n");
        printf("                              * 1.10000数据量						*\n");
        printf("                              **************************************************************\n");
        printf("                              * 2.50000数据量						*\n");
        printf("                              **************************************************************\n");
        printf("                              * 3.200000数据量						*\n");
        printf("                              **************************************************************\n");
        printf("                              * 4.退出并返回上级菜单					*\n");
        printf("                              **************************************************************\n");
        printf("                         ------------------------------------------------------------------------\n");
        printf("                              请选择选项编号:");
        ScanOrd(&ord); /*用ScanOrd来确保输入合法*/
        switch (ord)   /*switch多重循环判断输入是否正确*/
        {
        case 1: /*ord为1，选择10000数据量*/
        {
            flag = 1;     /*flag设置为1*/
            DataGen(1);   /*调用DataGen函数，生成文件并写入10000数据量*/
            size = MAX_1; /*为size赋MAX_1的值*/
            break;
        }
        case 2: /*ord'为2，选择50000数据量*/
        {
            flag = 1;     /*flag设置为1*/
            DataGen(2);   /*调用DataGen函数，生成文件并写入50000数据量*/
            size = MAX_2; /*为size赋MAX_2的值*/
            break;
        }
        case 3: /*ord'为3，选择200000数据量*/
        {
            flag = 1;     /*flag设置为1*/
            DataGen(3);   /*调用DataGen函数，生成文件并写入200000数据量*/
            size = MAX_3; /*为size赋MAX_3的值*/
            break;
        }
        case 4: /*ord为4，返回上级菜单*/
        {
            return;
        }
        default: /*解决输入不合法*/
        {
            fputs("输入有误，请重新输入!!\n", stderr);
            system("pause");
            break;
        }
        }
        system("cls");
    } while (flag == 0);
    /*DataScan用于从文件中读取对应选择大小的数据量*/
    int *data = DataScan(ord);                     /*data用于接收DataScan返回的数据数组*/
    int *temp = (int *)malloc(sizeof(int) * size); /*temp用于之后归并排序使用*/
    int max = data[0];                             /*max用于查找数组中的最大值，于计数排序中使用*/
    printf("正在进行检测，请耐心等待\n");
    for (int i = 0; i < size; i++)
    { /*使用for循环寻找数组最大值并赋予max*/
        /*同时使temp全部设置为0*/
        if (max < data[i])
        {
            max = data[i];
        }
        temp[i] = 0;
    }
    for (int i = 0; i < 6; i++) /*使用for循环循环选择算法进行检测*/
    {
        data = DataScan(ord); /*使data重置为未排序数组*/

        clock_t start = clock(); /*计使，start即开始数时间*/
        switch (i)               /*switch多分枝选择，调用不同算法进行检测*/
        {
        case 0: {
            insertSort(data, size); /*插入排序*/
            break;
        }
        case 1: {
            MergeSort(data, 0, size - 1, temp); /*归并排序*/
            break;
        }
        case 2: {
            QuickSort_Recursion(data, 0, size - 1); /*快速排序(递归)*/
            break;
        }
        case 3: {
            QuickSort(data, size); /*快速排序(非递归)*/
            break;
        }
        case 4: {
            CountSort(data, size, max); /*计数排序*/
            break;
        }
        case 5: {
            RadixCountSort(data, size); /*基数排序*/
            break;
        }
        }
        clock_t diff = clock() - start; /*检测所用时间并打印结果*/
        printf("在 %d 的数据量下，%s 的用时为 %d ms\n", size, name[i], diff);
        free(data); /*释放内存*/
        data = NULL;
    }
    free(temp);
    temp == NULL;
}

void ALotOfSmallData() /*检测算法在大量小数据下所用时间*/
{
    system("cls");
    printf("正在进行100数据量循环100k测试，请耐心等待\n");
    DataGen(1);
    int *arr = DataScan(0);
    int max = arr[0]; /*max用于记录数组最大值*/
                      /*如果不是计数排序，则不必查找数组最大值*/
    for (int j = 0; j < 100; j++)
    {
        if (max < arr[j])
        {
            max = arr[j];
        }
    }
    for (int i = 0; i < 6; i++) /*用for循环检测不同算法*/
    {
        clock_t start = clock();         /*start为起始时间*/
        for (int k = 0; k < 100000; k++) /*for循环开始多次重复*/
        {
            int data[100] = {0};
            for (int n = 0; n < 100; n++)
            {
                data[n] = arr[n];
            }
            int temp[100] = {0}; /*temp数组用于之后归并排序使用*/
            int size = 100;      /*size即使数组大小*/
            switch (i)           /*switch多分枝选择*/
            {
            case 0: {
                insertSort(data, size); /*插入排序*/
                break;
            }
            case 1: {
                MergeSort(data, 0, size - 1, temp); /*归并排序*/
                break;
            }
            case 2: {
                QuickSort_Recursion(data, 0, size - 1); /*快速排序(递归)*/
                break;
            }
            case 3: {
                QuickSort(data, size); /*快速排序(非递归)*/
                break;
            }
            case 4: {
                CountSort(data, size, max); /*计数排序*/
                break;
            }
            case 5: {
                RadixCountSort(data, size); /*基数排序*/
                break;
            }
            }
        }
        clock_t diff = clock() - start; /*用于检测所耗时间*/
        printf("在 100 的数据量下循环 100k 的情况下，%s 的用时为 %d ms\n", name[i], diff);
    }
    printf("测试已完成!!\n");
}

void ColorSortMenu() /*颜色排序函数*/
{
    system("cls");
    int data[100]; /*data是将要进行排序的数组*/
    srand((unsigned)time(NULL));
    for (int i = 0; i < 100; i++)
    {
        data[i] = rand() % 3; /*给data中每一个元素随机赋值*/
    }
    printf("在进行颜色排序之前，原数组如下:\n");
    for (int j = 1; j <= 100; j++) /*显示排序前的数组*/
    {
        printf("%d  ", data[j - 1]);
        if (j % 10 == 0) /*每显示10个就换行*/
        {
            putchar('\n');
        }
    }
    putchar('\n');
    ColorSort(data, 100); /*调用颜色排序函数*/
    printf("在进行颜色排序之后，结果数组如下:\n");
    for (int k = 1; k <= 100; k++) /*显示排序结果*/
    {
        printf("%d  ", data[k - 1]);
        if (k % 10 == 0) /*每10个换行*/
        {
            putchar('\n');
        }
    }
    putchar('\n');
}

void FindKthMenu() /*找数组中第K大数函数*/
{
    system("cls");
    int data[100] = {0}; /*data表示待查找数组*/
    srand((unsigned)time(NULL));
    for (int i = 0; i < 100; i++)
    {
        data[i] = rand() % 1000; /*给data里的每一个元素随机赋值*/
    }
    int K = 0;   /*K表示要查找的是第K个数*/
    while (TRUE) /*while死循环用于确保用户输入在正确范围之内*/
    {
        printf("100个随机数已生成，请输入想要查找第几大的数字:");
        ScanOrd(&K);           /*ScanOrd用于确保接收指令合法*/
        if (K <= 0 || K > 100) /*不合法，重新开始循环*/
        {
            fputs("输入有误，请重新输入!!\n", stderr);
            system("pause");
            system("cls");
            continue;
        }
        system("cls"); /*合法，退出循环*/
        break;
    }
    int result = FindKth(data, 100, K); /*调用FindKth函数，用于返回数组里第K大数*/
    printf("在此数组中，第 %d 大的数字为 %d \n\n", K, result);
    printf("原数组排序后结果如下(逆序):\n"); /*再显示排序好后结果*/
    QuickSort(data, 100);                    /*调用快速排序排序数组*/
    for (int n = 99; n >= 0; n--)            //*for循环打印排序结果*/
    {
        printf("%d  ", data[n]);
        if (n % 10 == 0) /*每打印10个就换行*/
        {
            putchar('\n');
        }
    }
}

int FindKth(int *a, int size, int K) /*查找数组第K大数所用函数*/
{
    int mid = SearchKth(a, 0, size - 1); /*先调用一次SearchKth，返回数组枢轴值所在下标给mid*/
    /*size-mid即使枢轴值在数组中的大小排行*/
    while (size - mid != K) /*判断size-mid是否为要找的序数*/
    {
        if (size - mid < K) /*size-mid小于K，即枢轴值的大小排行数比K大*/
        {                   /*向左找新的枢轴值，并重新开始新的循环*/
            mid = SearchKth(a, 0, mid - 1);
        }
        if (size - mid > K) /*size-mid小于K，即枢轴值的大小排行数比K小*/
        {                   /*向右找新的枢轴值，并重新开始新的循环*/
            mid = SearchKth(a, mid + 1, size - 1);
        }
    }
    /*查找到正确的枢轴值下标，返回该枢轴的值*/
    return a[mid];
}

void CheckSort() /*检查算法是否正确运行*/
{
    system("cls");
    int size = 100;             /*检测数组尺寸*/
    for (int i = 0; i < 6; i++) /*for循环来选择所有算法*/
    {
        int *data = DataScan(0); /*data每次循环重置为未排序数组*/
        int temp[100] = {0};     /*temp用于之后归并排序使用*/
        int max = data[0];       /*max用于之后计数排序使用*/
        printf("在 %s 排序前，原始数组如下:\n", name[i]);
        for (int k = 1; k <= 100; k++) /*打印排序前情况，同时查找数组中的最大值*/
        {
            printf("%d  ", data[k - 1]);
            if (max < data[k - 1])
            {
                max = data[k - 1];
            }
            if (k % 10 == 0) /*每打印10个就换行*/
            {
                putchar('\n');
            }
        }
        printf("\n\n");
        switch (i) /*switch来调用不同算法*/
        {
        case 0: {
            insertSort(data, size); /*插入排序*/
            break;
        }
        case 1: {
            MergeSort(data, 0, size - 1, temp); /*归并排序*/
            break;
        }
        case 2: {
            QuickSort_Recursion(data, 0, size - 1); /*快速排序(递归版)*/
            break;
        }
        case 3: {
            QuickSort(data, size); /*快速排序(非递归版)*/
            break;
        }
        case 4: {
            CountSort(data, size, max); /*计数排序*/
            break;
        }
        case 5: {
            RadixCountSort(data, size); /*基数排序*/
            break;
        }
        }
        printf("在 %s 排序后，结果数组如下:\n", name[i]);
        for (int n = 1; n <= 100; n++) /*显示排序后结果*/
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
int *DataScan(int ord) /*DataScan用于从文件中读取数据并返回数组指针*/
{
    int n = 0;   /*n表示数据量大小*/
    switch (ord) /*用ord+switch来判断选用数据量大小*/
    {
    case 0: /*0即表示100数据量*/
    {
        n = 100; /*n赋为100*/
        break;
    }
    case 1: /*1即表示10000数据量*/
    {
        n = MAX_1; /*n赋为10000*/
        break;
    }
    case 2: /*2即表示50000数据量*/
    {
        n = MAX_2; /*n赋为50000*/
        break;
    }
    case 3: /*3即表示200000数据量*/
    {
        n = MAX_3; /*n赋为200000*/
        break;
    }
    default: {
        break;
    }
    }
    FILE *fptr = fopen("data.txt", "r+"); /*以r+方式打开文件，文件指针为fptr*/
    if (fptr == NULL)                     /*判断打开是否成功*/
    {
        return NULL;
    }
    int *data = (int *)malloc(sizeof(int) * n); /*data即接收数据的数组*/
    for (int i = 0; i < n && !feof(fptr); i++)  /*使用for循环和fscanf从文件中读取数据到data*/
    {
        fscanf(fptr, "%d  ", data + i);
    }
    fclose(fptr); /*关闭文件*/
    return data;
}

Status DataGen(int ord) /*数据生成函数*/
{
    int n = 0;   /*n即使生成数据量的大小*/
    switch (ord) /*switch来选择数据量大小*/
    {
    case 1: /*n为1，即生成10000数据量*/
    {
        n = MAX_1;
        break;
    }
    case 2: /*n为2，即生成50000数据量*/
    {
        n = MAX_2;
        break;
    }
    case 3: /*n为3，即生成200000数据量*/
    {
        n = MAX_3;
        break;
    }
    default: {
        return FALSE; /*错误，返回FALSE*/
        break;
    }
    }
    int *arr = (int *)malloc(sizeof(int) * n); /*arr即是储存待写入文件数据的数组*/
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) //初始化数据
    {
        arr[i] = rand(); //随机生成数据
        if (rand() % 2)
        {
            arr[i] += rand() * rand() / (rand() + 1);
            arr[i] %= n;
        }
    }
    FILE *fptr = fopen("data.txt", "w+"); /*以w+方式打开文件，文件指针为fptr*/
    if (fptr == NULL)                     /*判断打开是否成功*/
    {
        return FALSE; /*失败，返回FALSE*/
    }
    for (int i = 0; i < n; i++) /*使用for循环写入文件中*/
    {
        fprintf(fptr, "%d  ", arr[i]);
    }
    fclose(fptr); /*关闭文件*/
    return;
}