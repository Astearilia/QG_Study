#ifndef MENU
#define MENU

void ScanOrd(int* num);							/*接收指令函数*/
void ScanShort(short* num);						/*接收short类型数据函数*/
void ScanInt(int* num);								/*接收int类型数据函数*/
void ScanLong(long* num);						/*接收Longt类型数据函数*/
void ScanFloat(float* d);							/*接收float类型数据函数*/
void ScanDouble(double* d);						/*接收double类型数据函数*/
void MainMenu();										/*主菜单函数*/
void EnLQueueMenu(LQueue* Q);			/*入队功能菜单函数*/
#endif MENU