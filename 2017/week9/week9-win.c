#include<stdio.h>

#define bool2str(b) ((b)?"true":"false")	//�Q�Υ����N0�P�D0��bool�P�w�ഫ��true��false���r�� 
#define shift_left(a,n)  (a<<n)				//�����Ʀ첾��K��F 
#define shift_right(a,n) (a>>n)				//�����Ʀ첾��K��F 

typedef unsigned int Int32;

int CheckRangeLoop (Int32 input, Int32 high, Int32 low){
	int i;
	int test_area = high-low; 
	Int32 mask = 1;
	/*
	 *�̤j��loop���@��(loop���i����y�{) 
	 *�bloop���a�y�{����гy�ŦX�˩w�d�򪺳s��1 (high-low+1)
	 *�P��shift�ܫ��w�줸(high)
	 *�s�@�B�n(mask) 
	 *��@�ɨϥΪ��y�{���ϹL�ӹB�@ �b�N1���ʦܫ��w�줸(high)���L�{���гy�ŦX�˩w�d�򪺳s��1((high-low)+�쥻��1)
	 *�^�� input�Pmask��and�� �@���˩w 
	 */ 
	for(i=0;i<high;i++){
		mask=mask<<1;
		if(test_area){
			mask+=1;
			test_area--;
		}
	}
	return input&mask;
}

int CheckRangeNoLoop (Int32 input, Int32 high, Int32 low){
	return ((((input>>low)<<low)<<31-high)>>31-high);
	/*
	 *�i�H�Ƭ�
	 *return shift_right(shift_left(shift_left(shift_right(input,low),low),31-high),31-high)
	 *�۷�� 
	 *input = shift_right(input,low);
	 *input = shift_left(input,low);
	 *input = shift_left(input,31-high);
	 *input = shift_right(input,31-high);
	 *return input;
	 */
}

Int32 input = 0b1100011010;   /* example:   Int32 input = 0x22334455*/
Int32 high = 7;   /*max value = 31*/
Int32 low = 4;     /*min value = 0*/

int main(void){
	/*����print�X�^�ǭ��ഫ�L�᪺�r��*/ 
	printf("NoLoop = %s\n",bool2str(CheckRangeNoLoop(input,high,low)));
	printf("Loop = %s\n",bool2str(CheckRangeLoop(input,high,low)));
	return 0;
}
