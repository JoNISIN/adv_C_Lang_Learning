/*
*	ㄏノ跑计print99猭 
*/

#include<stdio.h>

int main(void){
	int i = 0;																				//跑计﹍て0 
	while(i<81){																			//癹伴块9x9舱计 
		printf("%dx%d =%2d%s",i/9+1,i%9+1,(i/9+1)*(i%9+1),(((i%9+1)==9)?"\n":", "));		//ノ i/9 籔 i%9 家览9秈 +1菠筁0计  ノprintf北Α  程ㄏノ (((i%9+1)==9)?"\n":", ") 耞Α块跑计 北传︽ 
		i++;																				//i患糤 
	}
	return 0;
}
