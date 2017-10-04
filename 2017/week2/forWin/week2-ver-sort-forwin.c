/*
 *input	 	���Ƥ��W�L100���峹 
 *output	��X�N�峹���Ҧ������ƪ���
 *			    �ë��ӲĤ@�Ӧr�����r���ǦC�X(�j�p�g����)
 *�C�ӳ�����W�L20�r
 *�t�׬�O(n log n)���Ѫk: �ƧǪk  ���X��
 *
 *�ϥαƧǪk(�ϥΧֳt�Ƨ�)
 *
 *�i��n�r�u�O�q�_�i�H�ϥΪ����:
 *1.C++�s�b�H���¾𬰩���set�e��
 *2.�{���y���۱a�s�b�ֳt�ƧǪk
 */

/*
 *��Ʃݮi�ϥ�:
 *strcmp(src,dst)
 *strcpy(dst,src)
 *memset()
 */

 /*�ϥαƧǪk*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define clear(a) memset(a,'\0',sizeof(a))   //��l�ư}�C

char word_array[105][25];                   //�ھ��D�س]�m�}�C�B�s�r��

void swap(char *s1,char *s2){               //�Ω�Ƨǥ洫�r��
  char temp[25];                            //����k�ϥ�strcpy() �ɶ������׬�O(����*3(�I�s3��strcpy))
  clear(temp);
  strcpy(temp,s1);
  strcpy(s1,s2);
  strcpy(s2,temp);
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
      for(;strcmp(word_array[std],word_array[l])>0 && l<tail ;l++);       //strcmp() ��O(n)���r��r���������
      for(;strcmp(word_array[std],word_array[r])<=0 && head<r ;r--);
      if(l>=r) {
        break;
      }
      swap(word_array[l],word_array[r]);
    }
    swap(word_array[std],word_array[r]);
    q_sort(head,r-1);
    q_sort(r+1,tail);
  }
}

void (*used_sort)(int,int) = q_sort;          //�i��������L�ƧǪk
                                              //�ƧǪk�M�w�ɶ�������
 int main(void){
   char buffer[25];
   int i;
	 char c;
	 int flag = 0;
	 int count = 0;
   clear(word_array);
	 while(1){
		 for(i=0;i<25;){                                  //#1   �L�o���I�Ÿ��P�Ů���o�����r��
			 c = getchar();
			 if(isalpha(c)){
				 word_array[count][i] = tolower(c);
         flag = 1;
         i++;
			 }else{
         if(flag) {
           word_array[count][i] = '\0';               //�r����'\0'����i�H���ݭn�ϥ�memset�������m�}�C
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

   for(i = 0;i<count;i++){                           //#2  �r��w�ƧǮɥi�H�HO(n)���ɶ������׹L�o���Ʀr��
     if(strcmp(buffer,word_array[i])){
       clear(buffer);
       strcpy(buffer,word_array[i]);
       puts(buffer);
     }                                              //#2end
   }
   return 0;
 }

