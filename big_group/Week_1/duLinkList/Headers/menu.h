#include"duLinkedList.h"
void scanNum(int* num);                                  /*接收指令or数值函数*/
void printmenu();											    /*这是打印主菜单函数*/
void printElem(ElemType e);							    /*打印单元素值函数*/
void InitList_DuL_Menu(DuLinkedList* List);		/*初始化链表菜单函数*/
void InsertListMenu(DuLinkedList* L);				    /*插入链表结点函数*/
void DeleteListMenu(DuLinkedList* L);			    /*删除元素菜单*/
void TraverseListDuLMenu(DuLinkedList* List);  /*遍历链表函数*/
void IsLoopList(DuLinkedList List);						/*判断链表是否成环函数*/
void ReverseList(DuLinkedList* L);						/*反转链表函数*/