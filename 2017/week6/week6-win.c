/*
 *­n¦³¤@­Ó sorting ªº function„³ void sorting (tNumStorHead *list, int input)
 *±N©ÒÅª¨ìªº¼Æ¦rª½±µ±Æ§Ç¦n¨ì¥Ø¼Ðªºlist¤¤
 *­n¦³¤@­Óprint listªºfunction „³ void printList(tNumStorHead *list)
 *­n¦³¤@­ÓMergeªºfunction ¦^¶Ç merge ¦nªºlist „³      tNumStorHead *merge (tNumStorHead * list1, tNumStorHead * list2)
 *¦bmerge¤¤¨Ì¾Úlist1¥H¤Îlist2ªº¨Ó¾ã¨Ö¥X¤@­Ó·sªºmerged_list
 *³Ì«á¦^¶Çmerged_list¦Ümain function¡A¤]´N¬O»¡main function¤¤°õ¦æ merged_list = merge(list1, list2);
 *±µµÛMain function¤¤©I¥s printList(merged_list);
 *µ{¦¡¤¤¤£¯à¥X²{¥ô¦ó¤@­Ó[ ] ªº²Å¸¹ „³ ¤]´N¬O»¡©Ò¦³ªºµ{¦¡ªº°õ¦æ³£¨Ì¾Úlinked list¨Ó°µ¹B¦æ¡A¤£¯à¨Ì¿àarrayªº¹B§@ (¨ä¹ê°ò¥»¤W¤]¥Î¤£¨ì)
 *
 *©Ò¥H¦b¦¹¨Ï¥Î§¹¥þ¤£¥Î¨ìÃB¥~buffer°}¦Cªº¼gªk (ÁöµM¦s¦bBUG ¦ý¬Oinput¤£·|¨è·Nµ¹¨Ò¥~) 
 *©Ò¨Ï¥Îµ²ºc¤]§¹¥þ¤£¨Ï¥ÎÀRºA«Å§i 
 */
#include<stdio.h>
#include<stdlib.h>

/*¥H¥¨¶°Â²¤Æ±`¥Î¾Þ§@(¥¨¶°«á¥N½Xª½±µ´À´«¨ç¼Æ»P°Ñ¼Æ§Y¬°¹ê»Ú®ÄªG)*/
/*¨ú±oªÅ¶¡*/ 
#define getSpace(t,n)		(t*)malloc(sizeof(t)*n)
/*list³Ð³y»Pªì©l¤Æ*/ 
#define create_list()		getSpace(tNumStorHead,1)
#define list_init(a)		do{a->head=create_node();node_init(a->head);a->tail=create_node();node_init(a->tail);a->counts=0;}while(0)
/*¸`ÂI³Ð³y»Pªì©l¤Æ*/ 
#define create_node()		getSpace(tNumStorage,1)
#define node_init(a)		do{a->next=NULL;}while(0)
/*¥Ã»·´¡¤Ja©ób¤§«á*/ 
#define insert_after_(a,b)	do{a->next=b->next;b->next = a;}while(0)

/*ÃD¥Ø«ü©wµ²ºc*/ 
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

/*¤è«K¾Þ§@ªº¥þ°ìÅÜ¼Æ§@¬°¼È¦s*/ 
int buffer_num;
char buffer_c;

/*ÃD¥Ø«ü©w¨ç¼Æ*/ 
void sorting (tNumStorHead *list, int input);
void printList(tNumStorHead *list);
tNumStorHead *merge (tNumStorHead * list1, tNumStorHead * list2);
/*************/

int main(void){
	/*³Ð³y¨Ãªì©l¤Ælist*/
	tNumStorHead* list1 = create_list();
	tNumStorHead* list2 = create_list();
	list_init(list1);
	list_init(list2);
	/******************/
	
	/*¥ÎENTER¤¤¤î¿é¤Jªº¤@ºØ¤è¦¡*/
	printf("Please enter numbers in list1: ");
	/*¥ÎªÅ¦r¤¸ªì©l¤Æbuffer¦r¤¸*/ 
	buffer_c = '\0';
	while(1){
		/*¥H°j°é¨C¦¸³£Åª¨ú¤@¼Æ¦r¤@¦r¤¸  ¨Ã±N¨ú±oªº¼Æ¦r³z¹Lsorting´¡¤Jlist¤¤*/ 
		scanf("%d%c",&buffer_num,&buffer_c);
		sorting(list1,buffer_num);
		if(buffer_c=='\n') break;
	}
	
	/*¦P¤W  «Ø¥ß²Ä¤G­Ólist*/ 
	printf("Please enter numbers in list2: ");
	buffer_c = '\0';
	while(1){
		scanf("%d%c",&buffer_num,&buffer_c);
		sorting(list2,buffer_num);
		if(buffer_c=='\n') break;
	}
	
	/*¿é¥X*/ 
	printf("sorted list1: ");
	printList(list1);
	printf("sorted list2: ");
	printList(list2);
	printf("merged list: ");
	printList(merge(list1,list2));
	return 0;
}

/*®Ú¾ÚÃD·N¨C¦¸¥[¤J·s¼Æ­È®É  ¤Î±N¼Æ­È´¡¤J©ólist¥¿½T±Æ§Ç¦ì¸m¤§¤¤*/ 
void sorting (tNumStorHead *list, int input){
	/*list¬°ªÅ®Éµ²§ô¨ç¼Æ*/ 
	if(!list) return ;
	/*ªì©l¤Æ«ü¼ÐÅÜ¼Æ*/ 
	tNumStorage *buffer = NULL;
	tNumStorage *ptr = NULL;
	buffer = create_node();
	node_init(buffer);
	buffer->number = input;
	/***************/
	
	/*­Y¬°²Ä¤@¶µ«hÅý¨ä»Phead©Mtail°µ¥XÁpÃ´*/ 
	if(list->head->next==NULL){
		list->head->next = buffer;
		buffer->next = list->tail;
	}else{
		/*´¡¤J±Æ§Çªk O(n)*/ 
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
	/*¨C¦¸´¡¤Jµ²§ô«á­p¼Æ¾¹+1*/
	list->counts++;
}

/*«ü©wlist´`§Ç¦L¥X*/ 
void printList(tNumStorHead *list){
	tNumStorage *ptr = NULL;
	for(ptr=list->head->next;ptr!=list->tail;ptr=ptr->next)
		printf("%d ",ptr->number);
	puts("");
}

/*±N¨âlist¦X¨Ö©ó²Ä¤T­Ólist*/
/*¦¹³B¨Ï¥Îªº¬O¥¿³Wªºmergeºâªk ®É¶¡½ÆÂø«×¬°O(m+n)  ­Yª½±µ¥Hsorting¦X¨Ö«h®É¶¡½ÆÂø«×¬°O(u^2) (u= n+m)*/
/*¦¹³B±N¸`ÂI­«·s«Ø¥ß  ©ó¬O³B²z§¹²¦«á¨Ã¤£¼vÅT­ì¥ýlist1»Plist2*/ 
tNumStorHead *merge (tNumStorHead * list1, tNumStorHead * list2){
	/*indexÅÜ¼Æ*/ 
	int i;
	/*ªì©l¤Æ«ü¼Ð*/ 
	tNumStorHead* list_merge = create_list();
	list_init(list_merge);
	tNumStorage *ptr1 = list1->head->next;
	tNumStorage *ptr2 = list2->head->next;
	tNumStorage *merge_ptr = list_merge->head;
	list_merge->counts = list1->counts+list2->counts;
	/************/ 
	
	/*¤wª¾Á`¼Æ¶qªº±¡ªp ¨Ï¥Îfor°j°éÂ²¤Æ­p¼Æ*/ 
	for(i=0;i<list_merge->counts;i++){
		/*¨C¦¸«Ø¥ß¤@­Ó·s¸`ÂI¨Ã¥ý»Plist°µ³sµ²(¬Û·í©ó¨C¦¸³£ÂX¥R1­Ó¸`ÂI)*/ 
		merge_ptr->next = create_node();
		node_init(merge_ptr->next);
		merge_ptr = merge_ptr->next;
		/*************************************************************/ 
		
		/*­Ylist1¥þ¼Æ¿é¤J «h¤§«á±Nlist2³Ñ¾l¥þ³¡¨Ì§Ç¿é¤J*/ 
		if(ptr1==list1->tail){
			merge_ptr->number = ptr2->number;
			ptr2=ptr2->next;
			continue;
		/*­Ylist2¥þ¼Æ¿é¤J «h¤§«á±Nlist1³Ñ¾l¥þ³¡¨Ì§Ç¿é¤J*/
		}else if(ptr2==list2->tail){
			merge_ptr->number = ptr1->number;
			ptr1=ptr1->next;
			continue;
		/*¨âÃälist¬Ò¦³³Ñ¾l«h¤ñ¸û¤j¤p«á «h¤pªÌ¿é¤J  ¨Ã±N«ü¼Ð«á²¾*/
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
	/*¥½ºÝ¥Htail¥]¸Ë§¹²¦ ¨Ã¦^¶Ç¦¹list«ü¼Ð*/ 
	merge_ptr->next = list_merge->tail;
	return list_merge;
}
