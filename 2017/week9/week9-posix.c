#include<stdio.h>

#define bool2str(b) ((b)?"true":"false")	//利用巨集將0與非0的bool判定轉換為true或false的字串
#define shift_left(a,n)  (a<<n)				//巨集化位移方便表達
#define shift_right(a,n) (a>>n)				//巨集化位移方便表達

typedef unsigned int Int32;

int CheckRangeLoop (Int32 input, Int32 high, Int32 low){
	int i;
	int test_area = high-low;
	Int32 mask = 1;
	/*
	 *最大化loop的作用(loop中可控制流程)
	 *在loop中靠流程控制創造符合檢定範圍的連續1 (high-low+1)
	 *同時shift至指定位元(high)
	 *製作遮罩(mask)
	 *實作時使用的流程為反過來運作 在將1移動至指定位元(high)的過程中創造符合檢定範圍的連續1((high-low)+原本的1)
	 *回傳 input與mask的and值 作為檢定
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
	 *可以化為
	 *return shift_right(shift_left(shift_left(shift_right(input,low),low),31-high),31-high)
	 *相當於
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
	/*直接print出回傳值轉換過後的字串*/
	printf("NoLoop = %s\n",bool2str(CheckRangeNoLoop(input,high,low)));
	printf("Loop = %s\n",bool2str(CheckRangeLoop(input,high,low)));
	return 0;
}
