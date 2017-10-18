#include<stdio.h>
#include<stdlib.h>

#define getSpace(a,b) (a*)malloc(sizeof(a)*b);
#define swap(a,b) do{a=a+b;b=a-b;a=a-b;}while(0)

typedef struct num_list{
	int counts;
	int *plist;
}tNumList;

void bubbleSort(tNumList *list);
void merge (tNumList *list1, tNumList *list2);

int main(void){
	int i;
	
	tNumList *list1 , *list2;
	list1 = getSpace(tNumList,1);
	list2 = getSpace(tNumList,1);
	
	scanf("%d",&(list1->counts));
	list1->plist = getSpace(int,list1->counts);
	for(i=0;i<list1->counts;i++) scanf("%d",&(list1->plist[i]));
	
	scanf("%d",&(list2->counts));
	list2->plist = getSpace(int,list2->counts);
	for(i=0;i<list2->counts;i++) scanf("%d",&(list2->plist[i]));
	
	bubbleSort(list1);
	bubbleSort(list2);
	
	merge(list1,list2);
	
	return 0;
}

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
	for(i=0;i<list->counts;i++) printf("%d ",list->plist[i]);
	puts("");
}

void merge (tNumList *list1, tNumList *list2){
	/*非正規寫法可以直接用bubbleSort進行merge 此處使用正規寫法進行merge*/
	int i;
	int len = list1->counts+list2->counts;
	int  p1 = 0 , p2 = 0;
	int *m_list = getSpace(int,len);
	for(i=0;i<len;i++){
		if(!(list1->counts - p1)) {
			while(list2->counts - p2) m_list[i++]= list2->plist[p2++];
			break;
		}
		if(!(list2->counts - p2)){
			while(list1->counts - p1) m_list[i++]= list1->plist[p1++];
			break;
		}
		m_list[i] = ((list1->plist[p1]<list2->plist[p2])?list1->plist[p1++]:list2->plist[p2++]);
	}
	for(i=0;i<len;i++) printf("%d ",m_list[i]);
	puts("");
}
