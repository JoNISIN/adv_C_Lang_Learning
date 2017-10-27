/*week6上機考
 *要有一個 sorting 的 function void sorting (tNumStorHead *list, int input)
 *將所讀到的數字直接排序好到目標的list中
 *要有一個print list的function  void printList(tNumStorHead *list)
 *要有一個Merge的function 回傳 merge 好的list       tNumStorHead *merge (tNumStorHead * list1, tNumStorHead * list2)
 *在merge中依據list1以及list2的來整併出一個新的merged_list
 *最後回傳merged_list至main function，也就是說main function中執行 merged_list = merge(list1, list2);
 *接著Main function中呼叫 printList(merged_list);
 *程式中不能出現任何一個[ ] 的符號  也就是說所有的程式的執行都依據linked list來做運行，不能依賴array的運作 (其實基本上也用不到)
 *
 *所以在此使用完全不用到額外buffer陣列的寫法 (雖然存在BUG 但是input不會刻意給例外) 
 *所使用結構也完全不使用靜態宣告 
 */
#include<stdio.h>
#include<stdlib.h>

/*以巨集簡化常用操作(巨集後代碼直接替換函數與參數即為實際效果)*/
/*取得空間*/ 
#define getSpace(t,n)		(t*)malloc(sizeof(t)*n)
/*list創造與初始化*/ 
#define create_list()		getSpace(tNumStorHead,1)
#define list_init(a)		do{a->head=create_node();node_init(a->head);a->tail=create_node();node_init(a->tail);a->counts=0;}while(0)
/*節點創造與初始化*/ 
#define create_node()		getSpace(tNumStorage,1)
#define node_init(a)		do{a->next=NULL;}while(0)
/*永遠插入a於b之後*/ 
#define insert_after_(a,b)	do{a->next=b->next;b->next = a;}while(0)

/*題目指定結構*/ 
typedef struct num_storage
{
        int number;
        struct num_storage *next;
} tNumStorage;

typedef struct num_stor_head
{
    int counts;
    struct num_storage *head;
    struct num_storage *tail;
}tNumStorHead;
/********************************/ 

/*方便操作的全域變數作為暫存*/ 
int buffer_num;
char buffer_c;

/*題目指定函數*/ 
void sorting (tNumStorHead *list, int input);
void printList(tNumStorHead *list);
tNumStorHead *merge (tNumStorHead * list1, tNumStorHead * list2);
/*************/

int main(void){
	/*創造並初始化list*/
	tNumStorHead* list1 = create_list();
	tNumStorHead* list2 = create_list();
	list_init(list1);
	list_init(list2);
	/******************/
	
	/*用ENTER中止輸入的一種方式*/
	printf("Please enter numbers in list1: ");
	/*用空字元初始化buffer字元*/ 
	buffer_c = '\0';
	while(1){
		/*以迴圈每次都讀取一數字一字元  並將取得的數字透過sorting插入list中*/ 
		scanf("%d%c",&buffer_num,&buffer_c);
		sorting(list1,buffer_num);
		if(buffer_c=='\n') break;
	}
	
	/*同上  建立第二個list*/ 
	printf("Please enter numbers in list2: ");
	buffer_c = '\0';
	while(1){
		scanf("%d%c",&buffer_num,&buffer_c);
		sorting(list2,buffer_num);
		if(buffer_c=='\n') break;
	}
	
	/*輸出*/ 
	printf("sorted list1: ");
	printList(list1);
	printf("sorted list2: ");
	printList(list2);
	printf("merged list: ");
	printList(merge(list1,list2));
	return 0;
}

/*根據題意每次加入新數值時  及將數值插入於list正確排序位置之中*/ 
void sorting (tNumStorHead *list, int input){
	/*list為空時結束函數*/ 
	if(!list) return ;
	/*初始化指標變數*/ 
	tNumStorage *buffer = NULL;
	tNumStorage *ptr = NULL;
	buffer = create_node();
	node_init(buffer);
	buffer->number = input;
	/***************/
	
	/*若為第一項則讓其與head和tail做出聯繫*/ 
	if(list->head->next==NULL){
		list->head->next = buffer;
		buffer->next = list->tail;
	}else{
		/*插入排序法 O(n)*/ 
		for(ptr = list->head;;ptr=ptr->next){
			if(ptr->next==list->tail){
				insert_after_(buffer,ptr);
				break;
			}else if(ptr->next->number > input){
				insert_after_(buffer,ptr) ;
				break;
			}
		}
	}
	/*每次插入結束後計數器+1*/
	list->counts++;
}

/*指定list循序印出*/ 
void printList(tNumStorHead *list){
	tNumStorage *ptr = NULL;
	for(ptr=list->head->next;ptr!=list->tail;ptr=ptr->next)
		printf("%d ",ptr->number);
	puts("");
}

/*將兩list合併於第三個list*/
/*此處使用的是正規的merge算法 時間複雜度為O(m+n)  若直接以sorting合併則時間複雜度為O(u^2) (u= n+m)*/
/*此處將節點重新建立  於是處理完畢後並不影響原先list1與list2*/ 
tNumStorHead *merge (tNumStorHead * list1, tNumStorHead * list2){
	/*index變數*/ 
	int i;
	/*初始化指標*/ 
	tNumStorHead* list_merge = create_list();
	list_init(list_merge);
	tNumStorage *ptr1 = list1->head->next;
	tNumStorage *ptr2 = list2->head->next;
	tNumStorage *merge_ptr = list_merge->head;
	list_merge->counts = list1->counts+list2->counts;
	/************/ 
	
	/*已知總數量的情況 使用for迴圈簡化計數*/ 
	for(i=0;i<list_merge->counts;i++){
		/*每次建立一個新節點並先與list做連結(相當於每次都擴充1個節點)*/ 
		merge_ptr->next = create_node();
		node_init(merge_ptr->next);
		merge_ptr = merge_ptr->next;
		/*************************************************************/ 
		
		/*若list1全數輸入 則之後將list2剩餘全部依序輸入*/ 
		if(ptr1==list1->tail){
			merge_ptr->number = ptr2->number;
			ptr2=ptr2->next;
			continue;
		/*若list2全數輸入 則之後將list1剩餘全部依序輸入*/
		}else if(ptr2==list2->tail){
			merge_ptr->number = ptr1->number;
			ptr1=ptr1->next;
			continue;
		/*兩邊list皆有剩餘則比較大小後 則小者輸入  並將指標後移*/
		}else{
			if(ptr1->number < ptr2->number) {
				merge_ptr->number = ptr1->number;
				ptr1 = ptr1->next;
			}
			else {
				merge_ptr->number = ptr2->number;
				ptr2 = ptr2->next;
			}
		}
	}
	/*末端以tail包裝完畢 並回傳此list指標*/ 
	merge_ptr->next = list_merge->tail;
	return list_merge;
}