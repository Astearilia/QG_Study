typedef enum
{
    FALSE = 0,
    TRUE = 1
} Status;

void ScanOrd(int *num);               /*接收指令函数*/
void MainMenu();                      /*主菜单函数*/
void BigDataTime();                   /*测试大量数据情况下算法用时函数*/
void ALotOfSmallData();               /*检测算法在大量小数据下所用时间*/
void ColorSortMenu();                 /*颜色排序函数*/
void FindKthMenu();                   /*找数组中第K大数函数*/
int FindKth(int *a, int size, int K); /*查找数组第K大数所用函数*/
void CheckSort();                     /*检查算法是否正确运行函数*/
int *DataScan(int ord);               /*数据读取函数*/
Status DataGen(int ord);              /*数据生成函数*/