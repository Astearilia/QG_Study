#include"struct.h"

void scanNum(int* num);													/*���ڽ�������ָ��*/
Status CheckExp(char* exp);												/*���ڽ�������ı��ʽ�Ƿ���ȷ*/
void toRPN(char* s,char* RPNexp,PtrtoLinkstack stack);		/*��������ַ���ת��δ��׺���ʽ*/
int calRPN(char* RPNexp, PtrtoLinkstack stack);					/*�����׺���ʽ*/