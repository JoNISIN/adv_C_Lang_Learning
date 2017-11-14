#define list

#define getSpace(t,n) ((t*)malloc(sizeof(t)*n)) 
#define newNode() getSpace(tNode,1)
#define node_init(a,n) do{a->prev = a->next = NULL; a->num = n;}while(0)
#define node_insert_(t1,t2,a)		do{																		\
										a->next = t2; a->prev = t1; 										\
										if(a->prev) t1->next = a; 											\
										if(a->next) t2->prev = a;											\
									}while(0)

#define go_node_(p,n) while(--n)p = p->next

#define node_dele(l,a) 				do{																		\
										if(a->next)a->next->prev = a->prev;									\
										else l->tail = a->prev;												\
										if(a->prev)a->prev->next = a->next;									\
										else l->head = a->next;												\
										a->prev = a->next = NULL;											\
										free(a);															\
									}while(0)



#define list_info_update(l,c)		do{																		\
										if(l ->head)														\
										if(l ->head->prev) l->head=l->head->prev;							\
										if(l ->tail)														\
    									if(l ->tail->next) l->tail=l->tail->next;							\
    									l->c;																\
									}while(0)
									
typedef struct node
{
    int num;
    struct node *next;
    struct node *prev;
}tNode;

typedef struct list_head
{
    int count;
    tNode *head;
    tNode *tail;
}tListHead;
			
#ifndef main_
#include "main.h"
#endif
					
void addNodeToList(tListHead*, int,int,int);
void deleteNodeFromList(tListHead*, int);
