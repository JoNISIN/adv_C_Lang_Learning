#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define len 25
#define clear(a) memset(a,'\0',sizeof(a))   //初始化陣列

char **word_array;

void swap(char **s1,char **s2){               //用於排序交換字串
	char **t = (char**)malloc(sizeof(char*)*125);
	*t = *s1;
	*s1 = *s2;
	*s2 = *t; 
	free(t);
}

//使用快速排序法     時間複雜度為O(n log n)
void q_sort(int l,int r){
  int head = l;
  int tail = r;
  if(r<=l) return ;
  else{
    int std = l;
    l += 1;
    while(1){
      for(;strcmp(*(word_array+std),*(word_array+l))>0 && l<tail ;l++);       //strcmp() 為O(n)的字串字典續比較函數
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

void (*used_sort)(int,int) = q_sort;          //可替換為其他排序法
                                              //排序法決定時間複雜度
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
		 for(i=0;i<25;){                                  //#1   過濾標點符號與空格取得詞的字串
			 c = getchar();
			 if(isalpha(c)){
				 *(buffer+i) = tolower(c);
         flag = 1;
         i++;
			 }else{
         if(flag) {
           *(buffer+i) = '\0';               //字尾用'\0'中止可以不需要使用memset完全重置陣列
           *(word_array+count)=buffer;
           count++;
           flag = 0;                                  //確認詞串存在避免加入空字串
         }
         break;
        }
      }                                              //#1end
       if(c=='\n') {                                 //換行符號'\n'中止輸入
         used_sort(0,count-1);                       //字串依字典續排序
         break;
       }
     }
	buffer = (char*)malloc(len);
   for(i = 0;i<count;i++){                           //#2  字串已排序時可以以O(n)的時間複雜度過濾重複字串
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

