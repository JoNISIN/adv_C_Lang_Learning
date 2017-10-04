/*
 *week2
 *input-1	  詞數不超過100的文章
 *output-1	找出將文章中所有不重複的詞
 *			    並按照第一個字母的字母序列出(大小寫不分)
 *每個單詞不超過20字
 *速度為W(2(n^2))的解法: 窮舉法並使用泡沫排序(O(n^2))  
 *
 *可能要斟酌是否可以使用的函數
 *C++存在以紅黑樹為底的set容器
 *程式語言自帶存在快速排序法
 */

/*
 *函數拓展使用:
 *strcmp(src,dst)
 *strcpy(dst,src)
 *memset()
 */

 /*使用排序法*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define clear(a) memset(a,'\0',sizeof(a))

char word_array[105][25];								//依照題目建立陣列 

void swap(char *s1,char *s2){							//字串交換 
  char temp[25];
  clear(temp);
  strcpy(temp,s1);
  strcpy(s1,s2);
  strcpy(s2,temp);
}

char insert(char *src){									//檢查佇列內是否有重複的字串  有則回傳0  沒有則插入佇列並回傳1 
  int i;
  for(i=0;i<105 && word_array[i][0] != '\0';i++){
    if(!strcmp(src,word_array[i])) return 0;
  }
  strcpy(word_array[i],src);
  return 1;
}

//使用泡沫排序法O(n^2) 
void b_sort(int head,int tail){
  int n_swap;                                            //交換檢查 若全序列無交換則排序完成 
  int i,j;
  for(i=head;i<tail;i++){
    n_swap=0;
    for(j=head;j<tail-1-i;j++){
      if(strcmp(word_array[j],word_array[j+1])>0){
        swap(word_array[j],word_array[j+1]);
        n_swap++;
      }
    }
    if(!n_swap) break;
  }
}

void (*used_sort)(int,int) = b_sort;

 int main(void){
   char buffer[25];
   int i;
	 char c;
	 int flag = 0;
	 int count = 0;
   clear(word_array);
	 while(1){
		 for(i=0;i<25;){                          //#1 去掉標點與空白尋找不重複詞串 
			 c = getchar();
			 if(isalpha(c)){
				 buffer[i] = tolower(c);
         flag = 1;
         i++;
			 }else{
         if(flag) {
           buffer[i] = '\0';
           count+=insert(buffer);				//#1 將獲得的詞串插入不重複佇列  並計算插入成功次數 
           flag = 0;
         } 
         break;
        }
		}										//#1end 
       if(c=='\n') {							//換行符字串結束 
         used_sort(0,count);					//並進行排序 
         break;
       }
     }
     for(i = 0;i<count;i++){					//將排序過的不重複佇列(好像已經不是佇列了)循序輸出 
       puts(word_array[i]);
    }
   return 0;
 }

