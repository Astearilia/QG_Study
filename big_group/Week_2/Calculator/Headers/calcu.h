#include"struct.h"

void scanNum(int* num);													/*用于接收输入指令*/
Status CheckExp(char* exp);												/*用于接收输入的表达式是否正确*/
void toRPN(char* s,char* RPNexp,PtrtoLinkstack stack);		/*将输入的字符串转换未后缀表达式*/
int calRPN(char* RPNexp, PtrtoLinkstack stack);					/*计算后缀表达式*/