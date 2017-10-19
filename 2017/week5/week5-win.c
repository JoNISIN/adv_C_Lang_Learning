#include<stdio.h>
#include<stdlib.h>

#define getSpace(a,b) (a*)malloc(sizeof(a)*b);
#define swap(a,b) do{a=a+b;b=a-b;a=a-b;}while(0)  //�Q�Υ����P�ƾǤ覡�i��洫

typedef struct num_list{
	int counts;
	int *plist;
}tNumList;

void bubbleSort(tNumList *list);
void merge (tNumList *list1, tNumList *list2);

int main(void){
	int i;
	/*���ҨϥΫ��Шèϥ�malloc�t�~�إߪŶ�*/
	tNumList *list1 , *list2;
	list1 = getSpace(tNumList,1);
	list2 = getSpace(tNumList,1);
	/*�Q�ε��c����counts���������ƦC���� �ëإߵ����ƦC�� �����ƦC*/
	printf("Please enter how many numbers in list1: ");
	scanf("%d",&(list1->counts));
	list1->plist = getSpace(int,list1->counts);
	for(i=0;i<list1->counts;i++) scanf("%d",&(list1->plist[i]));
	
	printf("Please enter how many numbers in list2: ");
	scanf("%d",&(list2->counts));
	list2->plist = getSpace(int,list2->counts);
	for(i=0;i<list2->counts;i++) scanf("%d",&(list2->plist[i]));
	/*�a��X���w�j�Ƨ�*/
	printf("sorted list1: ");
	bubbleSort(list1);
	printf("sorted list2: ");
	bubbleSort(list2);
	/*�a��X���X�֨��*/
	printf("merged list: ");
	merge(list1,list2);

	return 0;
}
/*�Q��swao_c�T�w�ƧǪ��p�i���u�ƹL���w�j�ƧǪk*/
void bubbleSort(tNumList *list){
	int i,j,swap_c;
	for(i=0;i<list->counts;i++){
		swap_c = 0;
		for(j=0;j<(list->counts-i-1);j++){
			if(list->plist[j] > list->plist[j+1]){
				swap(list->plist[j],list->plist[j+1]);
				swap_c = 1;
			}
		}
		if(!swap_c) break;
	}
	for(i=0;i<list->counts;i++) printf("%d ",list->plist[i]);	//��X���G
	puts("");
}

void merge (tNumList *list1, tNumList *list2){
	/*��²���k���ϥ�bubbleSort()����Ҧ��ƭȭ��s�Ƨ� ���Ҭ��ϥΥ��`merge��k*/
	int i;
	int len = list1->counts+list2->counts;
	int  p1 = 0 , p2 = 0;
	int *m_list = getSpace(int,len);
	for(i=0;i<len;i++){			//�`�@�n��Jlen�Ӽƭ�
		if(!(list1->counts - p1)) {	//���if���O����ӼƦC���O���Q������J�����p  �Q������J��  �N�t�@�ӼƦC�������ӱƧǳv�ƶ�J�ƦC��
			while(list2->counts - p2) m_list[i++]= list2->plist[p2++];
			break;
		}
		if(!(list2->counts - p2)){
			while(list1->counts - p1) m_list[i++]= list1->plist[p1++];
			break;
		}
		m_list[i] = ((list1->plist[p1]<list2->plist[p2])?list1->plist[p1++]:list2->plist[p2++]); 	//����ƦC�̱ƧǶ��Ǥ���j�p �p�̥��i�J�s�ƦC  ���Ƥ������̤p�ƭ�  ����@�觹���Q��J
	}
	for(i=0;i<len;i++) printf("%d ",m_list[i]);		//��X���G
	puts("");
}

