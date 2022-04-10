#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/menu.h"
#include "../Headers/binary_sort_tree.h"
#include <stdio.h>
#include <stdlib.h>

void ScanOrd(int *num) /*接收指令函数*/
{
    if ((scanf("%d", num)) != 1) /*使用if+scanf+do-while循环来确保输入合法*/
    {
        while (getchar() != '\n')
            ;
        *num = -1;
    }
}

void ScanInt(int *num) /*接收int数据类型函数*/
{
    int flag = 1; /*flag表示输入是否合法*/
    do
    {
        flag = 1;
        if ((scanf("%d", num)) != 1) /*使用if+scanf+do-while循环来确保输入合法*/
        {
            while (getchar() != '\n')
                ;
            flag = 0;
            fputs("输入不合法,请重新输入数据\n", stderr);
        }
    } while (flag != 1);
}

void MainMenu() /*主菜单函数*/
{
    system("cls");
    printf("\n\n");
    printf("                         ******************************BST ADT******************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              **************************************************************\n");
    printf("                              * 1.插入元素		*	2.查找元素		*\n");
    printf("                              **************************************************************\n");
    printf("                              * 3.遍历树（递归）	*	4.遍历树（非递归）	*\n");
    printf("                              **************************************************************\n");
    printf("                              * 5.删除元素		*	6.退出系统		*\n");
    printf("                              **************************************************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              请选择菜单编号:");
}

void printOrderRMenu() /*显示递归遍历菜单函数*/
{
    system("cls");
    printf("\n\n");
    printf("                         ******************************遍历方式 ******************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              **************************************************************\n");
    printf("                              * 1.前序遍历					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 2.中序遍历					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 3.后序遍历					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 4.退出并返回上级菜单				*\n");
    printf("                              **************************************************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              请选择遍历方式:");
}

void printOrderdelMenu() /*显示非递归遍历菜单函数*/
{
    system("cls");
    printf("\n\n");
    printf("                         ******************************遍历方式 ******************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              **************************************************************\n");
    printf("                              * 1.前序遍历					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 2.中序遍历					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 3.后序遍历					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 4.层序遍历					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 5.退出并返回上级菜单				*\n");
    printf("                              **************************************************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              请选择遍历方式:");
}

void printValue(NodePtr treeNodePtr) /*打印指针指向值的函数*/
{
    printf("%d  ", treeNodePtr->value);
    return;
}

void InsertMenu(BinarySortTreePtr T) /*插入功能函数*/
{
    system("cls");
    printf("请输入想要插入的元素数量,0表示退出:");
    int nums = 0; /*nums用于接收要插入的数据数量*/
    ScanOrd(&nums);
    if (nums < 0) /*判断数字是否合法*/
    {
        printf("输入有误，请重新输入;");
        ScanOrd(&nums);
    }
    if (nums == 0) /*为0，退出*/
    {
        return;
    }
    for (int i = 0; i < nums; i++) /*用循环进行多次插入*/
    {
        printf("请输入第 %d 个数据:", i + 1);
        int tmp = 0; /*tmp即要插入的数值*/
        ScanInt(&tmp);
        if (BST_insert(T, tmp)) /*用返回值判断插入是否成功*/
        {
            printf("插入成功!!\n");
        }
        else
        {
            printf("插入失败!!\n");
        }
    }
    printf("完成插入\n");
    return;
}

void orderRMemu(BinarySortTreePtr T) /*递归遍历函数*/
{
    if (T->root == NULL) /*判断此时树是否为空*/
    {
        fputs("树为空，请先插入结点!!\n", stderr);
        return;
    }
    int ord = 0; /*ord用于接收指令*/
    do
    {
        printOrderRMenu(); /*显示菜单*/
        ScanOrd(&ord);     /*用scanOrd确保输入合法*/
        system("cls");
        switch (ord)
        {
        case 1: {
            printf("前序遍历结果如下:\n"); /*ord为1，调用前序遍历（递归）*/
            BST_preorderR(T, printValue);
            putchar('\n');
            break;
        }
        case 2: {
            printf("中序遍历结果如下:\n"); /*ord为2，调用中序遍历（递归）*/
            BST_inorderR(T, printValue);
            putchar('\n');
            break;
        }
        case 3: {
            printf("后序遍历结果如下:\n"); /*ord为3，调用后序遍历（递归）*/
            BST_postorderR(T, printValue);
            putchar('\n');
        }
        case 4: {
            break; /*ord为4，退出*/
        }
        default: {
            fputs("请输入正确指令!!", stderr); /*解决输入不合法情况*/
            break;
        }
        }
        system("pause");
    } while (ord != 4);
}

void orderdelMemu(BinarySortTreePtr T) /*非递归遍历函数*/
{
    if (T->root == NULL) /*判断此时树是否为空*/
    {
        fputs("树为空，请先插入结点!!\n", stderr);
        system("pause");
        return;
    }
    int ord = 0; /*ord用于接收指令*/
    do
    {
        printOrderdelMenu(); /*显示菜单*/
        ScanOrd(&ord);       /*用scanOrd确保输入合法*/
        system("cls");
        switch (ord)
        {
        case 1: {
            printf("前序遍历结果如下:\n"); /*ord为1，调用前序遍历（非递归）*/
            BST_preorderI(T, printValue);
            putchar('\n');
            break;
        }
        case 2: {
            printf("中序遍历结果如下:\n"); /*ord为2，调用中序遍历（非递归）*/
            BST_inorderI(T, printValue);
            putchar('\n');
            break;
        }
        case 3: {
            printf("后序遍历结果如下:\n"); /*ord为3，调用后序遍历（非递归）*/
            BST_postorderI(T, printValue);
            putchar('\n');
            break;
        }
        case 4: {
            printf("层序遍历结果如下:\n"); /*ord为4，调用层序遍历*/
            BST_levelOrder(T, printValue);
            putchar('\n');
            break;
        }
        case 5: {
            break; /*ord为5，退出*/
        }
        default: {
            fputs("请输入正确指令!!", stderr); /*解决输入不合法情况*/
            break;
        }
        }
        system("pause");
    } while (ord != 5);
}