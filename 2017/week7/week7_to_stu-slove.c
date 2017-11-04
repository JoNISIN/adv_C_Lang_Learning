#include <stdio.h>
#include <stdlib.h>

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

void printList(tListHead *listHead)
{
    tNode *pNode;

    printf("\n");
    printf("count: %d \n", listHead->count);
    pNode=listHead->head;
    printf (" From head --> ");
    while (pNode != NULL)
    {
        printf("%d ", pNode->num);
        pNode = pNode->next;
    }   
    pNode=listHead->tail;
    printf ("\n From tail --> ");
    while (pNode != NULL)
    {
        printf("%d ", pNode->num);
        pNode = pNode->prev;
    }   
    printf("\n");
}

void processAdd(tListHead *listHead)
{
	  int num, loc, choose, i;
	  tNode *pNode, *pLoc;
	  
    printf (" Add a number: ");
    scanf ("%d", &num);
    if (listHead->count > 0)
    {
        do
        {
            printf ("  Specify a target location: ");
            scanf ("%d", &loc);
            if (loc > listHead->count || loc < 1)
            {
                printf ("    Exceed current list size %d or <= 0\n", listHead->count);
            }
            else
            {
                break;
            }
        } while(1);
        do
        {
            printf ("  1. Before or 2. After the location %d: ", loc);
            scanf ("%d", &choose);
            if (choose > 2 || choose < 1)
            {
                printf ("    No such choose\n");
            }
            else
            {
                break;
            }
        } while(1);    
    }
    
    if(!listHead->count){
    	pNode = newNode();
    	node_init(pNode,num);
    	listHead->head = listHead->tail = pNode ;
    }else{
    	i = 1;
    	pLoc = listHead->head;
    	go_node_(pLoc,loc);
    	pNode = newNode();
    	node_init(pNode,num);
    	switch(choose){
    		case 1:
    			node_insert_(pLoc->prev,pLoc,pNode);
    			break;
    		case 2:
    			node_insert_(pLoc,pLoc->next,pNode);
    			break;
    	}
    }
    list_info_update(listHead,count++);
    printList(listHead);
}

void processDel(tListHead *listHead)
{
    int loc, i;
    tNode *pTar;
    
    if (listHead->count == 0)
    {
        printf ("  Nothing to delete.\n");
        return;
    }
    
    do
    {
        printf ("  Specify a target location: ");
        scanf ("%d", &loc);
        if (loc > listHead->count || loc < 1)
        {
            printf ("    Exceed current list size %d or <= 0\n", listHead->count);
        }
        else
        {
            break;
        }
    } while(1);
    
    pTar = listHead->head;
    
    go_node_(pTar,loc);
    node_dele(listHead,pTar);
    
    list_info_update(listHead,count--);
    printList(listHead);
}

int main (void)
{
	  int choose;
    tListHead *listHead;
    
    listHead = (tListHead *) malloc (sizeof(tListHead));
    listHead->head = NULL;
    listHead->tail = NULL;
    listHead->count = 0;
    
	  while (1)
	  {
        printf ("1. Add a number or 2. Delete a number: ");
        scanf ("%d", &choose);
        if (choose == 1)
        {
            processAdd(listHead);
        }
        else if (choose == 2)
        {
            processDel(listHead);
        }
        else
        {
            printf ("  No such choose !\n");
            continue;
        }        	
        printf ("\n");
    }
}
