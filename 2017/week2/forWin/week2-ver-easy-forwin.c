/*
 *week2
 *input-1	  ���Ƥ��W�L100���峹
 *output-1	��X�N�峹���Ҧ������ƪ���
 *			    �ë��ӲĤ@�Ӧr�����r���ǦC�X(�j�p�g����)
 *�C�ӳ�����W�L20�r
 *�t�׬�W(2(n^2))���Ѫk: �a�|�k�èϥΪw�j�Ƨ�(O(n^2))  
 *
 *�i��n�r�u�O�_�i�H�ϥΪ����
 *C++�s�b�H���¾𬰩���set�e��
 *�{���y���۱a�s�b�ֳt�ƧǪk
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

#define clear(a) memset(a,'\0',sizeof(a))

char word_array[105][25];								//�̷��D�ثإ߰}�C 

void swap(char *s1,char *s2){							//�r��洫 
  char temp[25];
  clear(temp);
  strcpy(temp,s1);
  strcpy(s1,s2);
  strcpy(s2,temp);
}

char insert(char *src){									//�ˬd��C���O�_�����ƪ��r��  ���h�^��0  �S���h���J��C�æ^��1 
  int i;
  for(i=0;i<105 && word_array[i][0] != '\0';i++){
    if(!strcmp(src,word_array[i])) return 0;
  }
  strcpy(word_array[i],src);
  return 1;
}

//�ϥΪw�j�ƧǪkO(n^2) 
void b_sort(int head,int tail){
  int n_swap;                                            //�洫�ˬd �Y���ǦC�L�洫�h�Ƨǧ��� 
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
		 for(i=0;i<25;){                          //#1 �h�����I�P�ťմM�䤣���Ƶ��� 
			 c = getchar();
			 if(isalpha(c)){
				 buffer[i] = tolower(c);
         flag = 1;
         i++;
			 }else{
         if(flag) {
           buffer[i] = '\0';
           count+=insert(buffer);				//#1 �N��o�����괡�J�����Ʀ�C  �íp�ⴡ�J���\���� 
           flag = 0;
         } 
         break;
        }
		}										//#1end 
       if(c=='\n') {							//����Ŧr�굲�� 
         used_sort(0,count);					//�öi��Ƨ� 
         break;
       }
     }
     for(i = 0;i<count;i++){					//�N�ƧǹL�������Ʀ�C(�n���w�g���O��C�F)�`�ǿ�X 
       puts(word_array[i]);
    }
   return 0;
 }

