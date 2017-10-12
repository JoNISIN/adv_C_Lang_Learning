#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(a,b) do{a=a+b; b=a-b; a=a-b;}while(0)							//數學交換法 
int *sheetRoot;

void change_row (int number, int size);
void change_column (int number, int size);
void printAll(int number, int size);

int main(int argc, char *argv[])											//使用帶參數的程式 
{
	if(argc==1){															//排除沒有其他參數的狀況 
		puts("Err: No arg");
		return 0;
	}
	int i;
	const int size = atoi(*(argv+1));										//記下大量使用到的數值  # int atoi(char*) 為字串轉數字函數 
	const int edge_len = (int)sqrt(size);									//記下大量使用到的數值 並強制轉型  # double sqrt(double) 為開根函數 
	sheetRoot = (int*)malloc(sizeof(int)*size);								//依照數字數目建立int整數陣列 
	for(i=0 ; i<size ; i++) *(sheetRoot+i) = atoi(*(argv+2+i));				//將字串轉為數字後放入陣列中 
	printAll(edge_len,size);												//作業程式執行 
	change_row(edge_len,size);
	printAll(edge_len,size);
	change_column(edge_len,size);
	printAll(edge_len,size);												//作業程式結束
	return 0; 
}

void printAll(int number, int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%2d%c",*(sheetRoot+i),(((i+1)%number==0)?'\n':' '));		//循序印出+格式控制 
	puts("");
}

void change_row (int number, int size)
{
	int i,offset = number*2;												//第一行對應第三行 其偏移量為 單排長度(邊長)*2 
    for(i=0;i<number;i++) swap(*(sheetRoot+i),*(sheetRoot+offset+i));		//循序使第一行的數值與其對應的第三行數值交換 
}

void change_column (int number, int size)
{
	int i, offset = 2;														//第一列與第三列 其數值對應偏移量為 2 
    for(i=0;i<number;i++) swap(*(sheetRoot+(number*i)),*(sheetRoot+(number*i)+offset));		//第一列每個數值位置為 邊長*行數 
}
