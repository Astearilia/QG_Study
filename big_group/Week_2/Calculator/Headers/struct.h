#ifndef STACK_CALCU
#define STACK_CALCU

typedef struct stackNode			/*栈结点定义*/
{
	char data;
	struct stack* next;
}stackNode,*PtrtostackNode;

typedef struct Linkstack				/*栈头定义*/
{
	PtrtostackNode top;
}Linkstack,*PtrtoLinkstack;

typedef enum								/*枚举类的定义，用于判断是or否*/
{
	FALSE = 0, 
	TRUE = 1
} Status;

void IntStack(PtrtoLinkstack* stack);						/*初始化栈函数*/
void PushStack(PtrtoLinkstack stack, char e);			/*入栈功能函数*/
void PopStack(PtrtoLinkstack stack, char* e);			/*出栈功能函数*/
void GetStackHead(PtrtoLinkstack stack, char* e);  /*取得栈顶元素函数功能函数*/
Status isEmpty(PtrtoLinkstack stack);						/*判断栈是否为空功能函数*/

#endif //STACK_CALCU