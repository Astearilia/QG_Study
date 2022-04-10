#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/binary_sort_tree.h"
#include "../Headers/menu.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ord = 0; /*ord用于接收指令*/
    BinarySortTreePtr T = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    BST_init(T); /*初始化树*/
    do
    {
        system("cls");
        MainMenu();    /*显示主菜单*/
        ScanOrd(&ord); /*接收指令*/
        switch (ord)
        {
        case 1: {
            InsertMenu(T); /*调用插入功能*/
            putchar('\n');
            system("pause");
            break;
        }
        case 2: {
            system("cls"); /*调用查找功能*/
            int num = 0;
            printf("请输入想要查找的数字:");
            ScanInt(&num);          /*scanInt确保输入合法*/
            if (BST_search(T, num)) /*用返回值判断是否找到目标数值*/
            {
                printf("成功找到元素 %d", num);
            }
            else
            {
                printf("未找到元素 %d", num);
            }
            putchar('\n');
            system("pause");
            break;
        }
        case 3: {
            orderRMemu(T); /*递归遍历菜单函数*/
            break;
        }
        case 4: {
            orderdelMemu(T); /*非递归遍历菜单函数*/
            break;
        }
        case 5: {
            system("cls"); /*使用删除功能*/
            int num = 0;
            printf("请输入想要删除的数字:");
            ScanInt(&num);          /*接收想要删除的数据*/
            if (BST_delete(T, num)) /*用返回值判断删除是否成功*/
            {
                printf("删除成功!!\n");
            }
            else
            {
                fputs("删除失败!!\n", stderr);
            }
            putchar('\n');
            system("pause");
            break;
        }
        case 6: {
            break;
        }
        default: {
            fputs("输入有误!!，请重新输入!!", stderr); /*解决不合法输入*/
            putchar('\n');
            system("pause");
            break;
        }
        }
    } while (ord != 6);
}