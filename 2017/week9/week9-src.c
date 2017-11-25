#include<stdio.h>
#include<stdlib.h>

#define bool2str(b) ((b)?"true":"false")
#define shift_left(a,n)  (a<<n)
#define shift_right(a,n) (a>>n)

typedef unsigned int Int32;

int CheckRangeLoop (Int32 input, Int32 high, Int32 low){
	int i;
	int test_area = high-low; 
	Int32 mask = 1;
	
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
}

Int32 input = 0b1100011010;   /* example:   Int32 input = 0x22334455*/
Int32 high = 7;   /*max value = 31*/
Int32 low = 4;     /*min value = 0*/

int main(void){
	printf("NoLoop = %s\n",bool2str(CheckRangeNoLoop(input,high,low)));
	printf("Loop = %s\n",bool2str(CheckRangeLoop(input,high,low)));
	return 0;
}
