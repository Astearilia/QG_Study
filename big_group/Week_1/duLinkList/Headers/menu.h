#include"duLinkedList.h"
void scanNum(int* num);                                  /*����ָ��or��ֵ����*/
void printmenu();											    /*���Ǵ�ӡ���˵�����*/
void printElem(ElemType e);							    /*��ӡ��Ԫ��ֵ����*/
void InitList_DuL_Menu(DuLinkedList* List);		/*��ʼ������˵�����*/
void InsertListMenu(DuLinkedList* L);				    /*���������㺯��*/
void DeleteListMenu(DuLinkedList* L);			    /*ɾ��Ԫ�ز˵�*/
void TraverseListDuLMenu(DuLinkedList* List);  /*����������*/
void IsLoopList(DuLinkedList List);						/*�ж������Ƿ�ɻ�����*/
void ReverseList(DuLinkedList* L);						/*��ת������*/