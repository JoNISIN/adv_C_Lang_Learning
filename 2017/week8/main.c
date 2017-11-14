#include "main.h"

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

void processDel(tListHead *listHead)
{
    int loc, i;
    
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

    deleteNodeFromList(listHead , loc);
    printList(listHead);
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
    
    addNodeToList(listHead , num, loc,choose);
    printList(listHead);
}

int main(void)
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
    return 0;
}
