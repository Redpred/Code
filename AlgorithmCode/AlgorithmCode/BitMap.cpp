#include "BitMap.h"

BitMap::BitMap()
{
	int a = 0;//32 bit

	int arr[10]{};// 32bit * 10 =320bits

	//arr[0] int 0~31
	//arr[1] int 32~63
	//arr[2] int 64~95

	int i = 178;//���ȡ��178λbit��״̬

	int numIndex = 178 / 32;//Ѱ��178λ��arr����ڼ�Ԫ����
	int bitIndex = 178 % 32;//��arr[5]�Ķ����Ƶڼ�λ

	//�õ�178λ״̬
	int s = ((arr[numIndex] >> bitIndex) & 1);//arr[5]����bitIndexλ�����ǽ�178λ�Ƶ����ұߣ�����1����������λ��

	//��178λ�ĳ�1
	arr[numIndex] = arr[numIndex] | (1 << bitIndex);

	//��178λ�ĳ�0
	arr[numIndex] = arr[numIndex] & (~(1 << bitIndex));
}