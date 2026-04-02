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

int insert_node_at_head(node_t **ppHead, int data)
{
    node_t *pNode = create_node(data);
    node_t *pTemp = NULL;

    if(!pNode)
        return ENOMEM;

    if(!*ppHead)
    {
        *ppHead = pNode;
        return 0;
    }

    pTemp = *ppHead;
    pNode->pNext = pTemp;
    pTemp->pPrev = pNode;
    *ppHead = pNode;

    return 0;
}

int add_node_to_dll(node_t **ppHead, int data)
{
    node_t *pNode = create_node(data);
    node_t *pTemp = NULL;
    
    if(!pNode)
        return ENOMEM;

    // If the new node is the first node. Point the head of the DLL to new node
    if(!*ppHead)
    {    
        *ppHead = pNode;
        return 0;
    }    

    pTemp = *ppHead;
    while(pTemp->pNext)
        pTemp = pTemp->pNext;
    pTemp->pNext = pNode;
    pNode->pPrev = pTemp;

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

    node_t *pTemp = *ppHead;
    while(pTemp && pTemp->data != data){
        pTemp = pTemp->pNext;
	}	

    //Reached the end of the list without a match

    if(!pTemp)
    {
        printf("Data not found in the Linked List\n");
        errno = ENOENT;

        return -1;
    }

    // Data is found. Logic to unlink the node with the matched data and delete it.
    if(*ppHead == pTemp) {
        *ppHead = pTemp->pNext;
    }

	if(pTemp->pNext != NULL)
		pTemp->pNext->pPrev = pTemp->pPrev;
	if(pTemp->pPrev != NULL)    
		pTemp->pPrev->pNext = pTemp->pNext;
    
	free(pTemp);
    
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
    node_t *pCurrent = *ppHead;
    node_t *pNext = NULL;

    while(pCurrent)
    {
        pNext = pCurrent->pNext;
        free(pCurrent);
        pCurrent = pNext;
    }

    *ppHead = NULL;
}

int reverse_dll(node_t **ppHead)
{
    node_t *pNewHead = NULL;
    node_t *pTemp = NULL;

    pTemp = *ppHead;
    while(pTemp)
    {
        insert_node_at_head(&pNewHead, pTemp->data);
        pTemp = pTemp->pNext;
    }
    free_dll_nodes(ppHead);
    *ppHead = pNewHead;

    return 0;
}

node_t *reverse_dll_recursive(node_t *pCurrent)
{
    node_t *pTemp = NULL;

    // Base Case: If the list if empty return NULL
    if(!pCurrent)
        return NULL;

    // Swap the previous and next pointers of the current node
    pTemp = pCurrent->pNext;
    pCurrent->pNext = pCurrent->pPrev;
    pCurrent->pPrev = pTemp;
    
    // If we reached the end of the original DLL
    if(pTemp == NULL)
        return pCurrent;

    return reverse_dll_recursive(pTemp);
}

/** 
 * @brief Safely reverses a DLL of any size using a loop
 * @param ppHead Pointer to the head pointer of the list
 */

int reverse_dll_iterative(node_t **ppHead)
{
    node_t *pCurrent = *ppHead;
    node_t *pTemp = NULL;

    if(!ppHead || !*ppHead) {

        errno = EINVAL;
        return -1;
    }   

    while(pCurrent)
    {
        // Swap the pointers

        pTemp = pCurrent->pNext;
        pCurrent->pNext = pCurrent->pPrev;
        pCurrent->pPrev = pTemp;

        // Move to the next node in the original order.
        // The next node in the original order is now pCurrent->pPrev as we just swapped

        pTemp = pCurrent;
        pCurrent = pCurrent->pPrev;
    }

    // After the loop, pTemp points to the old tail, which is the new head
    if(pTemp)
        *ppHead = pTemp;

    return 0;
}
