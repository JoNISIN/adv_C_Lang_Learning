#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(a,b) do{a=a+b; b=a-b; a=a-b;}while(0)							//�ƾǥ洫�k 
int *sheetRoot;

void change_row (int number, int size);
void change_column (int number, int size);
void printAll(int number, int size);

int main(int argc, char *argv[])											//�ϥαa�Ѽƪ��{�� 
{
	if(argc==1){															//�ư��S����L�Ѽƪ����p 
		puts("Err: No arg");
		return 0;
	}
	int i;
	const int size = atoi(*(argv+1));										//�O�U�j�q�ϥΨ쪺�ƭ�  # int atoi(char*) ���r����Ʀr��� 
	const int edge_len = (int)sqrt(size);									//�O�U�j�q�ϥΨ쪺�ƭ� �ñj���૬  # double sqrt(double) ���}�ڨ�� 
	sheetRoot = (int*)malloc(sizeof(int)*size);								//�̷ӼƦr�ƥثإ�int��ư}�C 
	for(i=0 ; i<size ; i++) *(sheetRoot+i) = atoi(*(argv+2+i));				//�N�r���ର�Ʀr���J�}�C�� 
	printAll(edge_len,size);												//�@�~�{������ 
	change_row(edge_len,size);
	printAll(edge_len,size);
	change_column(edge_len,size);
	printAll(edge_len,size);												//�@�~�{������
	return 0; 
}

void printAll(int number, int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%2d%c",*(sheetRoot+i),(((i+1)%number==0)?'\n':' '));		//�`�ǦL�X+�榡���� 
	puts("");
}

void change_row (int number, int size)
{
	int i,offset = number*2;												//�Ĥ@������ĤT�� �䰾���q�� ��ƪ���(���)*2 
    for(i=0;i<number;i++) swap(*(sheetRoot+i),*(sheetRoot+offset+i));		//�`�ǨϲĤ@�檺�ƭȻP��������ĤT��ƭȥ洫 
}

void change_column (int number, int size)
{
	int i, offset = 2;														//�Ĥ@�C�P�ĤT�C ��ƭȹ��������q�� 2 
    for(i=0;i<number;i++) swap(*(sheetRoot+(number*i)),*(sheetRoot+(number*i)+offset));		//�Ĥ@�C�C�ӼƭȦ�m�� ���*��� 
}
