#include<stdio.h>
#include<stdlib.h>

#define getSpace(a,b) (a*)malloc(sizeof(a)*b);
#define swap(a,b) do{a=a+b;b=a-b;a=a-b;}while(0)  //利用巨集與數學方式進行交換

typedef struct num_list{
	int counts;
	int *plist;
}tNumList;

void bubbleSort(tNumList *list);
void merge (tNumList *list1, tNumList *list2);

int main(void){
	int i;
	/*此例使用指標並使用malloc另外建立空間*/
	tNumList *list1 , *list2;
	list1 = getSpace(tNumList,1);
	list2 = getSpace(tNumList,1);
	/*利用結構中的counts元素接收數列長度 並建立等長數列後 接收數列*/
	printf("Please enter how many numbers in list1: ");
	scanf("%d",&(list1->counts));
	list1->plist = getSpace(int,list1->counts);
	for(i=0;i<list1->counts;i++) scanf("%d",&(list1->plist[i]));
	
	printf("Please enter how many numbers in list2: ");
	scanf("%d",&(list2->counts));
	list2->plist = getSpace(int,list2->counts);
	for(i=0;i<list2->counts;i++) scanf("%d",&(list2->plist[i]));
	/*帶輸出的泡沫排序*/
	printf("sorted list1: ");
	bubbleSort(list1);
	printf("sorted list2: ");
	bubbleSort(list2);
	/*帶輸出的合併函數*/
	printf("merged list: ");
	merge(list1,list2);

	return 0;
}
/*利用swao_c確定排序狀況進行優化過的泡沫排序法*/
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
	for(i=0;i<list->counts;i++) printf("%d ",list->plist[i]);	//輸出結果
	puts("");
}

void merge (tNumList *list1, tNumList *list2){
	/*最簡單方法為使用bubbleSort()抓取所有數值重新排序 此例為使用正常merge方法*/
	int i;
	int len = list1->counts+list2->counts;
	int  p1 = 0 , p2 = 0;
	int *m_list = getSpace(int,len);
	for(i=0;i<len;i++){			//總共要輸入len個數值
		if(!(list1->counts - p1)) {	//兩個if分別為兩個數列分別先被完全輸入的狀況  被完全輸入後  將另一個數列直接按照排序逐數塞入數列中
			while(list2->counts - p2) m_list[i++]= list2->plist[p2++];
			break;
		}
		if(!(list2->counts - p2)){
			while(list1->counts - p1) m_list[i++]= list1->plist[p1++];
			break;
		}
		m_list[i] = ((list1->plist[p1]<list2->plist[p2])?list1->plist[p1++]:list2->plist[p2++]); 	//兩邊數列依排序順序比較大小 小者先進入新數列  重複比較兩邊最小數值  直到一方完全被輸入
	}
	for(i=0;i<len;i++) printf("%d ",m_list[i]);		//輸出結果
	puts("");
}

