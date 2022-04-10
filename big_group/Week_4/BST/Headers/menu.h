#include"binary_sort_tree.h"
void ScanOrd(int *num);                 /*接收指令函数*/
void ScanInt(int *num);                 /*接收int数据类型函数*/
void MainMenu();                        /*主菜单函数*/
void printValue(NodePtr treeNodePtr);   /*打印指针指向值的函数*/
void InsertMenu(BinarySortTreePtr T);   /*插入功能函数*/
void orderRMemu(BinarySortTreePtr T);   /*递归遍历菜单函数*/
void orderdelMemu(BinarySortTreePtr T); /*非递归遍历菜单函数*/