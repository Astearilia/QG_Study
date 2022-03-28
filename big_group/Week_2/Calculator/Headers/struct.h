#ifndef STACK_CALCU
#define STACK_CALCU

typedef struct stackNode			/*ջ��㶨��*/
{
	char data;
	struct stack* next;
}stackNode,*PtrtostackNode;

typedef struct Linkstack				/*ջͷ����*/
{
	PtrtostackNode top;
}Linkstack,*PtrtoLinkstack;

typedef enum								/*ö����Ķ��壬�����ж���or��*/
{
	FALSE = 0, 
	TRUE = 1
} Status;

void IntStack(PtrtoLinkstack* stack);						/*��ʼ��ջ����*/
void PushStack(PtrtoLinkstack stack, char e);			/*��ջ���ܺ���*/
void PopStack(PtrtoLinkstack stack, char* e);			/*��ջ���ܺ���*/
void GetStackHead(PtrtoLinkstack stack, char* e);  /*ȡ��ջ��Ԫ�غ������ܺ���*/
Status isEmpty(PtrtoLinkstack stack);						/*�ж�ջ�Ƿ�Ϊ�չ��ܺ���*/

#endif //STACK_CALCU