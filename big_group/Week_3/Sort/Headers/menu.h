typedef enum
{
    FALSE = 0,
    TRUE = 1
} Status;

void ScanOrd(int *num);               /*����ָ���*/
void MainMenu();                      /*���˵�����*/
void BigDataTime();                   /*���Դ�������������㷨��ʱ����*/
void ALotOfSmallData();               /*����㷨�ڴ���С����������ʱ��*/
void ColorSortMenu();                 /*��ɫ������*/
void FindKthMenu();                   /*�������е�K��������*/
int FindKth(int *a, int size, int K); /*���������K�������ú���*/
void CheckSort();                     /*����㷨�Ƿ���ȷ���к���*/
int *DataScan(int ord);               /*���ݶ�ȡ����*/
Status DataGen(int ord);              /*�������ɺ���*/