#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/binary_sort_tree.h"
#include "../Headers/menu.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ord = 0; /*ord���ڽ���ָ��*/
    BinarySortTreePtr T = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    BST_init(T); /*��ʼ����*/
    do
    {
        system("cls");
        MainMenu();    /*��ʾ���˵�*/
        ScanOrd(&ord); /*����ָ��*/
        switch (ord)
        {
        case 1: {
            InsertMenu(T); /*���ò��빦��*/
            putchar('\n');
            system("pause");
            break;
        }
        case 2: {
            system("cls"); /*���ò��ҹ���*/
            int num = 0;
            printf("��������Ҫ���ҵ�����:");
            ScanInt(&num);          /*scanIntȷ������Ϸ�*/
            if (BST_search(T, num)) /*�÷���ֵ�ж��Ƿ��ҵ�Ŀ����ֵ*/
            {
                printf("�ɹ��ҵ�Ԫ�� %d", num);
            }
            else
            {
                printf("δ�ҵ�Ԫ�� %d", num);
            }
            putchar('\n');
            system("pause");
            break;
        }
        case 3: {
            orderRMemu(T); /*�ݹ�����˵�����*/
            break;
        }
        case 4: {
            orderdelMemu(T); /*�ǵݹ�����˵�����*/
            break;
        }
        case 5: {
            system("cls"); /*ʹ��ɾ������*/
            int num = 0;
            printf("��������Ҫɾ��������:");
            ScanInt(&num);          /*������Ҫɾ��������*/
            if (BST_delete(T, num)) /*�÷���ֵ�ж�ɾ���Ƿ�ɹ�*/
            {
                printf("ɾ���ɹ�!!\n");
            }
            else
            {
                fputs("ɾ��ʧ��!!\n", stderr);
            }
            putchar('\n');
            system("pause");
            break;
        }
        case 6: {
            break;
        }
        default: {
            fputs("��������!!������������!!", stderr); /*������Ϸ�����*/
            putchar('\n');
            system("pause");
            break;
        }
        }
    } while (ord != 6);
}