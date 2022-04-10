#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/menu.h"
#include "../Headers/binary_sort_tree.h"
#include <stdio.h>
#include <stdlib.h>

void ScanOrd(int *num) /*����ָ���*/
{
    if ((scanf("%d", num)) != 1) /*ʹ��if+scanf+do-whileѭ����ȷ������Ϸ�*/
    {
        while (getchar() != '\n')
            ;
        *num = -1;
    }
}

void ScanInt(int *num) /*����int�������ͺ���*/
{
    int flag = 1; /*flag��ʾ�����Ƿ�Ϸ�*/
    do
    {
        flag = 1;
        if ((scanf("%d", num)) != 1) /*ʹ��if+scanf+do-whileѭ����ȷ������Ϸ�*/
        {
            while (getchar() != '\n')
                ;
            flag = 0;
            fputs("���벻�Ϸ�,��������������\n", stderr);
        }
    } while (flag != 1);
}

void MainMenu() /*���˵�����*/
{
    system("cls");
    printf("\n\n");
    printf("                         ******************************BST ADT******************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              **************************************************************\n");
    printf("                              * 1.����Ԫ��		*	2.����Ԫ��		*\n");
    printf("                              **************************************************************\n");
    printf("                              * 3.���������ݹ飩	*	4.���������ǵݹ飩	*\n");
    printf("                              **************************************************************\n");
    printf("                              * 5.ɾ��Ԫ��		*	6.�˳�ϵͳ		*\n");
    printf("                              **************************************************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              ��ѡ��˵����:");
}

void printOrderRMenu() /*��ʾ�ݹ�����˵�����*/
{
    system("cls");
    printf("\n\n");
    printf("                         ******************************������ʽ ******************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              **************************************************************\n");
    printf("                              * 1.ǰ�����					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 2.�������					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 3.�������					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 4.�˳��������ϼ��˵�				*\n");
    printf("                              **************************************************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              ��ѡ�������ʽ:");
}

void printOrderdelMenu() /*��ʾ�ǵݹ�����˵�����*/
{
    system("cls");
    printf("\n\n");
    printf("                         ******************************������ʽ ******************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              **************************************************************\n");
    printf("                              * 1.ǰ�����					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 2.�������					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 3.�������					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 4.�������					*\n");
    printf("                              **************************************************************\n");
    printf("                              * 5.�˳��������ϼ��˵�				*\n");
    printf("                              **************************************************************\n");
    printf("                         ------------------------------------------------------------------------\n");
    printf("                              ��ѡ�������ʽ:");
}

void printValue(NodePtr treeNodePtr) /*��ӡָ��ָ��ֵ�ĺ���*/
{
    printf("%d  ", treeNodePtr->value);
    return;
}

void InsertMenu(BinarySortTreePtr T) /*���빦�ܺ���*/
{
    system("cls");
    printf("��������Ҫ�����Ԫ������,0��ʾ�˳�:");
    int nums = 0; /*nums���ڽ���Ҫ�������������*/
    ScanOrd(&nums);
    if (nums < 0) /*�ж������Ƿ�Ϸ�*/
    {
        printf("������������������;");
        ScanOrd(&nums);
    }
    if (nums == 0) /*Ϊ0���˳�*/
    {
        return;
    }
    for (int i = 0; i < nums; i++) /*��ѭ�����ж�β���*/
    {
        printf("������� %d ������:", i + 1);
        int tmp = 0; /*tmp��Ҫ�������ֵ*/
        ScanInt(&tmp);
        if (BST_insert(T, tmp)) /*�÷���ֵ�жϲ����Ƿ�ɹ�*/
        {
            printf("����ɹ�!!\n");
        }
        else
        {
            printf("����ʧ��!!\n");
        }
    }
    printf("��ɲ���\n");
    return;
}

void orderRMemu(BinarySortTreePtr T) /*�ݹ��������*/
{
    if (T->root == NULL) /*�жϴ�ʱ���Ƿ�Ϊ��*/
    {
        fputs("��Ϊ�գ����Ȳ�����!!\n", stderr);
        return;
    }
    int ord = 0; /*ord���ڽ���ָ��*/
    do
    {
        printOrderRMenu(); /*��ʾ�˵�*/
        ScanOrd(&ord);     /*��scanOrdȷ������Ϸ�*/
        system("cls");
        switch (ord)
        {
        case 1: {
            printf("ǰ������������:\n"); /*ordΪ1������ǰ��������ݹ飩*/
            BST_preorderR(T, printValue);
            putchar('\n');
            break;
        }
        case 2: {
            printf("��������������:\n"); /*ordΪ2����������������ݹ飩*/
            BST_inorderR(T, printValue);
            putchar('\n');
            break;
        }
        case 3: {
            printf("��������������:\n"); /*ordΪ3�����ú���������ݹ飩*/
            BST_postorderR(T, printValue);
            putchar('\n');
        }
        case 4: {
            break; /*ordΪ4���˳�*/
        }
        default: {
            fputs("��������ȷָ��!!", stderr); /*������벻�Ϸ����*/
            break;
        }
        }
        system("pause");
    } while (ord != 4);
}

void orderdelMemu(BinarySortTreePtr T) /*�ǵݹ��������*/
{
    if (T->root == NULL) /*�жϴ�ʱ���Ƿ�Ϊ��*/
    {
        fputs("��Ϊ�գ����Ȳ�����!!\n", stderr);
        system("pause");
        return;
    }
    int ord = 0; /*ord���ڽ���ָ��*/
    do
    {
        printOrderdelMenu(); /*��ʾ�˵�*/
        ScanOrd(&ord);       /*��scanOrdȷ������Ϸ�*/
        system("cls");
        switch (ord)
        {
        case 1: {
            printf("ǰ������������:\n"); /*ordΪ1������ǰ��������ǵݹ飩*/
            BST_preorderI(T, printValue);
            putchar('\n');
            break;
        }
        case 2: {
            printf("��������������:\n"); /*ordΪ2����������������ǵݹ飩*/
            BST_inorderI(T, printValue);
            putchar('\n');
            break;
        }
        case 3: {
            printf("��������������:\n"); /*ordΪ3�����ú���������ǵݹ飩*/
            BST_postorderI(T, printValue);
            putchar('\n');
            break;
        }
        case 4: {
            printf("��������������:\n"); /*ordΪ4�����ò������*/
            BST_levelOrder(T, printValue);
            putchar('\n');
            break;
        }
        case 5: {
            break; /*ordΪ5���˳�*/
        }
        default: {
            fputs("��������ȷָ��!!", stderr); /*������벻�Ϸ����*/
            break;
        }
        }
        system("pause");
    } while (ord != 5);
}