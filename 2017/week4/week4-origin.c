#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define len 25
#define clear(a) memset(a,'\0',sizeof(a))   //��l�ư}�C

char **word_array;

void swap(char **s1,char **s2){               //�Ω�Ƨǥ洫�r��
	char **t = (char**)malloc(sizeof(char*)*125);
	*t = *s1;
	*s1 = *s2;
	*s2 = *t; 
	free(t);
}

//�ϥΧֳt�ƧǪk     �ɶ������׬�O(n log n)
void q_sort(int l,int r){
  int head = l;
  int tail = r;
  if(r<=l) return ;
  else{
    int std = l;
    l += 1;
    while(1){
      for(;strcmp(*(word_array+std),*(word_array+l))>0 && l<tail ;l++);       //strcmp() ��O(n)���r��r���������
      for(;strcmp(*(word_array+std),*(word_array+r))<=0 && head<r ;r--);
      if(l>=r) {
        break;
      }
      swap((word_array+l),(word_array+r));
    }
    swap((word_array+std),(word_array+r));
    q_sort(head,r-1);
    q_sort(r+1,tail);
  }
}

void (*used_sort)(int,int) = q_sort;          //�i��������L�ƧǪk
                                              //�ƧǪk�M�w�ɶ�������
 int main(void){
 	word_array = (char**)malloc(sizeof(char*)*125);
   char *buffer;
   int i;
	 char c;
	 int flag = 0;
	 int count = 0;
   clear(word_array);
	 while(1){
	 	buffer = (char*)malloc(len);
		 for(i=0;i<25;){                                  //#1   �L�o���I�Ÿ��P�Ů���o�����r��
			 c = getchar();
			 if(isalpha(c)){
				 *(buffer+i) = tolower(c);
         flag = 1;
         i++;
			 }else{
         if(flag) {
           *(buffer+i) = '\0';               //�r����'\0'����i�H���ݭn�ϥ�memset�������m�}�C
           *(word_array+count)=buffer;
           count++;
           flag = 0;                                  //�T�{����s�b�קK�[�J�Ŧr��
         }
         break;
        }
      }                                              //#1end
       if(c=='\n') {                                 //����Ÿ�'\n'�����J
         used_sort(0,count-1);                       //�r��̦r����Ƨ�
         break;
       }
     }
	buffer = (char*)malloc(len);
   for(i = 0;i<count;i++){                           //#2  �r��w�ƧǮɥi�H�HO(n)���ɶ������׹L�o���Ʀr��
     if(strcmp(buffer,*(word_array+i))){
       clear(buffer);
       strcpy(buffer,*(word_array+i));
       puts(buffer);
     }                                              //#2end
   }
   free(buffer);
   free(word_array);
   return 0;
 }

