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

/*�H����²�Ʊ`�ξާ@(������N�X����������ƻP�ѼƧY����ڮĪG)*/
/*���o�Ŷ�*/ 
#define getSpace(t,n)		(t*)malloc(sizeof(t)*n)
/*list�гy�P��l��*/ 
#define create_list()		getSpace(tNumStorHead,1)
#define list_init(a)		do{a->head=create_node();node_init(a->head);a->tail=create_node();node_init(a->tail);a->counts=0;}while(0)
/*�`�I�гy�P��l��*/ 
#define create_node()		getSpace(tNumStorage,1)
#define node_init(a)		do{a->next=NULL;}while(0)
/*�û����Ja��b����*/ 
#define insert_after_(a,b)	do{a->next=b->next;b->next = a;}while(0)

/*�D�ث��w���c*/ 
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

/*��K�ާ@�������ܼƧ@���Ȧs*/ 
int buffer_num;
char buffer_c;

/*�D�ث��w���*/ 
void sorting (tNumStorHead *list, int input);
void printList(tNumStorHead *list);
tNumStorHead *merge (tNumStorHead * list1, tNumStorHead * list2);
/*************/

int main(void){
	/*�гy�ê�l��list*/
	tNumStorHead* list1 = create_list();
	tNumStorHead* list2 = create_list();
	list_init(list1);
	list_init(list2);
	/******************/
	
	/*��ENTER�����J���@�ؤ覡*/
	printf("Please enter numbers in list1: ");
	/*�ΪŦr����l��buffer�r��*/ 
	buffer_c = '\0';
	while(1){
		/*�H�j��C����Ū���@�Ʀr�@�r��  �ñN���o���Ʀr�z�Lsorting���Jlist��*/ 
		scanf("%d%c",&buffer_num,&buffer_c);
		sorting(list1,buffer_num);
		if(buffer_c=='\n') break;
	}
	
	/*�P�W  �إ߲ĤG��list*/ 
	printf("Please enter numbers in list2: ");
	buffer_c = '\0';
	while(1){
		scanf("%d%c",&buffer_num,&buffer_c);
		sorting(list2,buffer_num);
		if(buffer_c=='\n') break;
	}
	
	/*��X*/ 
	printf("sorted list1: ");
	printList(list1);
	printf("sorted list2: ");
	printList(list2);
	printf("merged list: ");
	printList(merge(list1,list2));
	return 0;
}

/*�ھ��D�N�C���[�J�s�ƭȮ�  �αN�ƭȴ��J��list���T�ƧǦ�m����*/ 
void sorting (tNumStorHead *list, int input){
	/*list���Ůɵ������*/ 
	if(!list) return ;
	/*��l�ƫ����ܼ�*/ 
	tNumStorage *buffer = NULL;
	tNumStorage *ptr = NULL;
	buffer = create_node();
	node_init(buffer);
	buffer->number = input;
	/***************/
	
	/*�Y���Ĥ@���h����Phead�Mtail���X�pô*/ 
	if(list->head->next==NULL){
		list->head->next = buffer;
		buffer->next = list->tail;
	}else{
		/*���J�ƧǪk O(n)*/ 
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
	/*�C�����J������p�ƾ�+1*/
	list->counts++;
}

/*���wlist�`�ǦL�X*/ 
void printList(tNumStorHead *list){
	tNumStorage *ptr = NULL;
	for(ptr=list->head->next;ptr!=list->tail;ptr=ptr->next)
		printf("%d ",ptr->number);
	puts("");
}

/*�N��list�X�֩�ĤT��list*/
/*���B�ϥΪ��O���W��merge��k �ɶ������׬�O(m+n)  �Y�����Hsorting�X�֫h�ɶ������׬�O(u^2) (u= n+m)*/
/*���B�N�`�I���s�إ�  ��O�B�z������ä��v�T���list1�Plist2*/ 
tNumStorHead *merge (tNumStorHead * list1, tNumStorHead * list2){
	/*index�ܼ�*/ 
	int i;
	/*��l�ƫ���*/ 
	tNumStorHead* list_merge = create_list();
	list_init(list_merge);
	tNumStorage *ptr1 = list1->head->next;
	tNumStorage *ptr2 = list2->head->next;
	tNumStorage *merge_ptr = list_merge->head;
	list_merge->counts = list1->counts+list2->counts;
	/************/ 
	
	/*�w���`�ƶq�����p �ϥ�for�j��²�ƭp��*/ 
	for(i=0;i<list_merge->counts;i++){
		/*�C���إߤ@�ӷs�`�I�å��Plist���s��(�۷��C�����X�R1�Ӹ`�I)*/ 
		merge_ptr->next = create_node();
		node_init(merge_ptr->next);
		merge_ptr = merge_ptr->next;
		/*************************************************************/ 
		
		/*�Ylist1���ƿ�J �h����Nlist2�Ѿl�����̧ǿ�J*/ 
		if(ptr1==list1->tail){
			merge_ptr->number = ptr2->number;
			ptr2=ptr2->next;
			continue;
		/*�Ylist2���ƿ�J �h����Nlist1�Ѿl�����̧ǿ�J*/
		}else if(ptr2==list2->tail){
			merge_ptr->number = ptr1->number;
			ptr1=ptr1->next;
			continue;
		/*����list�Ҧ��Ѿl�h����j�p�� �h�p�̿�J  �ñN���ЫᲾ*/
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
	/*���ݥHtail�]�˧��� �æ^�Ǧ�list����*/ 
	merge_ptr->next = list_merge->tail;
	return list_merge;
}
