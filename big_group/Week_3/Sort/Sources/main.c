#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/menu.h"
#include "../Headers/sort.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ord = 0; /*ord用于接收用户指令*/
    do
    {
        system("cls");
        MainMenu();    /*显示主菜单*/
        ScanOrd(&ord); /*用ScanOrd来确保用户输入合法*/
        switch (ord)   /*switch选择*/
        {
        case 1: {
            BigDataTime(); /*测试大量数据情况下算法用时函数*/
            break;
        }
        case 2: {
            ALotOfSmallData(); /*检测算法在大量小数据下所用时间*/
            break;
        }
        case 3: {
            ColorSortMenu(); /*颜色排序函数*/
            break;
        }
        case 4: {
            FindKthMenu(); /*找数组中第K大数函数*/
            break;
        }
        case 5: {
            CheckSort(); /*检查算法是否正确运行函数*/
            break;
        }
        case 6: {
            break;
        }
        default: {
            fputs("输入指令错误，请重新输入!!\n", stderr); /*处理输入指令出错情况*/
            break;
        }
        }
        if (ord != 6)
        {
            system("pause");
            system("cls");
        }
    } while (ord != 6);
    return;
}