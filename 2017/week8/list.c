#include "list.h"

void addNodeToList(tListHead *listHead , int num,int loc,int choose){
	tNode *pNode,*pLoc;
	int i;
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
}
void deleteNodeFromList(tListHead *listHead , int loc){
	tNode *pTar;
	pTar = listHead->head;
    
    go_node_(pTar,loc);
    node_dele(listHead,pTar);
    
    list_info_update(listHead,count--);
}
