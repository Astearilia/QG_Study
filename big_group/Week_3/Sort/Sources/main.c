#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/menu.h"
#include "../Headers/sort.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ord = 0; /*ord���ڽ����û�ָ��*/
    do
    {
        system("cls");
        MainMenu();    /*��ʾ���˵�*/
        ScanOrd(&ord); /*��ScanOrd��ȷ���û�����Ϸ�*/
        switch (ord)   /*switchѡ��*/
        {
        case 1: {
            BigDataTime(); /*���Դ�������������㷨��ʱ����*/
            break;
        }
        case 2: {
            ALotOfSmallData(); /*����㷨�ڴ���С����������ʱ��*/
            break;
        }
        case 3: {
            ColorSortMenu(); /*��ɫ������*/
            break;
        }
        case 4: {
            FindKthMenu(); /*�������е�K��������*/
            break;
        }
        case 5: {
            CheckSort(); /*����㷨�Ƿ���ȷ���к���*/
            break;
        }
        case 6: {
            break;
        }
        default: {
            fputs("����ָ���������������!!\n", stderr); /*��������ָ��������*/
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