#include "dll_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


node_t *create_node(int data)
{
    node_t *pNode = (node_t *)malloc(sizeof(node_t));
    if(!pNode)
        return NULL;

    pNode->data = data;
    pNode->pPrev = NULL;
    pNode->pNext = NULL;

    return pNode;
}

int add_node_to_dll(node_t **ppHead, int data)
{
    node_t *pNode = create_node(data);
    node_t *temp = NULL;
    
    if(!pNode)
        return ENOMEM;

    // If the new node is the first node. Point the head of the DLL to new node
    if(!*ppHead)
    {    
        *ppHead = pNode;
        return 0;
    }    

    temp = *ppHead;
    while(temp->pNext)
        temp = temp->pNext;
    temp->pNext = pNode;
    pNode->pPrev = temp;

    return 0;
}

int del_node_from_dll(node_t **ppHead, int data)
{

    if(!ppHead)
    {
        errno = EINVAL;
        return -1;
    }

    if(!*ppHead)
    {
        printf("Empty Linked List\n");
        errno = ENOENT;

        return -1;
    }    

    node_t *temp = *ppHead;
    while(temp && temp->data != data){
        temp = temp->pNext;
	}	

    //Reached the end of the list without a match

    if(!temp)
    {
        printf("Data not found in the Linked List\n");
        errno = ENOENT;

        return -1;
    }

    // Data is found. Logic to unlink the node with the matched data and delete it.
    if(*ppHead == temp) {
        *ppHead = temp->pNext;
    }

	if(temp->pNext != NULL)
		temp->pNext->pPrev = temp->pPrev;
	if(temp->pPrev != NULL)    
		temp->pPrev->pNext = temp->pNext;
    
	free(temp);
    
	return 0;
}

/***********************************************
 * Function to print the data in the Linked List    
***********************************************/

void print_dll_nodes(node_t *pHead)
{
    while(pHead)
    {
        printf("%d <-> ", pHead->data);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

void free_dll_nodes(node_t **ppHead)
{
    node_t *curr = *ppHead;
    node_t *next = NULL;

    while(curr)
    {
        next = curr->pNext;
        free(curr);
        curr = next;
    }

    *ppHead = NULL;
}

