/*
 *�n���@�� sorting �� function�� void sorting (tNumStorHead *list, int input)
 *�N��Ū�쪺�Ʀr�����ƧǦn��ؼЪ�list��
 *�n���@��print list��function �� void printList(tNumStorHead *list)
 *�n���@��Merge��function �^�� merge �n��list ��      tNumStorHead *merge (tNumStorHead * list1, tNumStorHead * list2)
 *�bmerge���̾�list1�H��list2���Ӿ�֥X�@�ӷs��merged_list
 *�̫�^��merged_list��main function�A�]�N�O��main function������ merged_list = merge(list1, list2);
 *����Main function���I�s printList(merged_list);
 *�{��������X�{����@��[ ] ���Ÿ� �� �]�N�O���Ҧ����{�������泣�̾�linked list�Ӱ��B��A����̿�array���B�@ (���򥻤W�]�Τ���)
 *
 *�ҥH�b���ϥΧ������Ψ��B�~buffer�}�C���g�k (���M�s�bBUG ���Oinput���|��N���ҥ~) 
 *�Ҩϥε��c�]�������ϥ��R�A�ŧi 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define getSpace(t,n) (t*)malloc(sizeof(t)*n)
#define create_list()  getSpace(tNumStorHead,1)
#define list_init(a)   do{a->head=create_node();node_init(a->head);a->tail=create_node();node_init(a->tail);a->counts=0;}while(0)
#define create_node()  getSpace(tNumStorage,1)
#define node_init(a)   do{a->next=NULL;}while(0)

#define insert_after_(a,b)	   do{a->next=b->next;b->next = a;}while(0)

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

int buffer_num;
char buffer_c;

void sorting (tNumStorHead *list, int input);
void printList(tNumStorHead *list);
tNumStorHead *merge (tNumStorHead * list1, tNumStorHead * list2);

int main(void){
	
	tNumStorHead* list1 = create_list();
	tNumStorHead* list2 = create_list();
	list_init(list1);
	list_init(list2);
	buffer_c = '\0';
	while(1){
		scanf("%d%c",&buffer_num,&buffer_c);
		sorting(list1,buffer_num);
		if(buffer_c=='\n') break;
	}
	buffer_c = '\0';
	while(1){
		scanf("%d%c",&buffer_num,&buffer_c);
		sorting(list2,buffer_num);
		if(buffer_c=='\n') break;
	}
	printList(list1);
	printList(list2);
	printList(merge(list1,list2));
	return 0;
}

void sorting (tNumStorHead *list, int input){
	if(!list) return ;
	tNumStorage *buffer = NULL;
	tNumStorage *ptr = NULL;
	buffer = create_node();
	node_init(buffer);
	buffer->number = input;
	if(list->head->next==NULL){
		list->head->next = buffer;
		buffer->next = list->tail;
	}else{
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
	list->counts++;
}

void printList(tNumStorHead *list){
	tNumStorage *ptr = NULL;
	for(ptr=list->head->next;ptr!=list->tail;ptr=ptr->next)
		printf("%d ",ptr->number);
	puts("");
}

tNumStorHead *merge (tNumStorHead * list1, tNumStorHead * list2){
	int i;
	tNumStorHead* list_merge = create_list();
	list_init(list_merge);
	tNumStorage *ptr1 = list1->head->next;
	tNumStorage *ptr2 = list2->head->next;
	tNumStorage *merge_ptr = list_merge->head;
	list_merge->counts = list1->counts+list2->counts;
	for(i=0;i<list_merge->counts;i++){
		merge_ptr->next = create_node();
		node_init(merge_ptr->next);
		merge_ptr = merge_ptr->next;
		if(ptr1==list1->tail){
			merge_ptr->number = ptr2->number;
			ptr2=ptr2->next;
			continue;
		}else if(ptr2==list2->tail){
			merge_ptr->number = ptr1->number;
			ptr1=ptr1->next;
			continue;
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
	merge_ptr->next = list_merge->tail;
	return list_merge;
}
