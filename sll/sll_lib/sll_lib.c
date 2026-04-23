#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "sll_lib.h"

static node_t *create_node(int data)
{
    node_t *pNode = (node_t *)malloc(sizeof(node_t));
    if(!pNode)
        return NULL;

    pNode->data = data;
    pNode->pNext = NULL;

    return pNode;
}

int insert_node_at_head(list_t *pList, int data)
{
    if(!pList)
        return -1;
    else if(pList->size == 0)
    {
        node_t *pNode = create_node(data);
        if(!pNode)
            return -1;

        pList->pHead = pNode;
        pList->pTail = pNode;
        pList->size++;
    }
    else
    {
        node_t *pNode = create_node(data);
        if(!pNode)
            return -1;

        pNode->pNext = pList->pHead;
        pList->pHead = pNode;
        pList->size++;
    }

    return 0;
}

int insert_node_at_tail(list_t *pList, int data)
{
    if(!pList)
        return -1;
    else if(pList->size == 0)
    {
        node_t *pNode = create_node(data);
        if(!pNode)
            return -1;

        pList->pHead = pNode;
        pList->pTail = pNode;
        pList->size++;
    }
    else
    {
        node_t *pNode = create_node(data);
        if(!pNode)
            return -1;

        pList->pTail->pNext = pNode;
        pList->pTail = pNode;
        pList->size++;
    }

    return 0;
}

int insert_node_at_position(list_t *pList, int data, int position)
{
    if(!pList)
        return -1;
    else if(position < 0 || position > pList->size)
        return -1;
    else if(position == 0)
        return insert_node_at_head(pList, data);
    else if(position == pList->size)
        return insert_node_at_tail(pList, data);
    else
    {
        node_t *pNode = create_node(data);
        if(!pNode)
            return -1;

        node_t *pCurrent = pList->pHead;
        for(int i = 0; i < position - 1; i++)
            pCurrent = pCurrent->pNext;

        pNode->pNext = pCurrent->pNext;
        pCurrent->pNext = pNode;
        pList->size++;
    }

    return 0;
}

int insert_node_at_node_with_match_data(list_t *pList, int data, int match_data)
{
    if(!pList)
        return -1;

    node_t *pCurrent = pList->pHead;
    while(pCurrent->data != match_data)
    {
        if(pCurrent->pNext == NULL) {
            printf("Node with Match Data %d not found in the list\n", match_data);
            return -1;
        }    
        pCurrent = pCurrent->pNext;
    }

    if(pCurrent->data == match_data)
    {
        node_t *pNode = create_node(data);
        if(!pNode)
            return -1;

        pNode->data = data;
        pNode->pNext = pCurrent->pNext;
        pCurrent->pNext = pNode;
        if(pCurrent == pList->pTail)
            pList->pTail = pNode;
        if(pCurrent == pList->pHead)
            pList->pHead = pNode;
        pList->size++;
    }

    return 0;
}

int delete_node_at_head(list_t *pList)
{
    if(!pList || pList->size == 0)
        return -1;
    
    if(pList->size == 1)
    {
        free(pList->pHead);
        pList->pHead = NULL;
        pList->pTail = NULL;
        pList->size--;
    }
    else
    {
        node_t *pTemp = pList->pHead;
        pList->pHead = pList->pHead->pNext;
        free(pTemp);
        pTemp = NULL;
        pList->size--;
    }

    return 0;
}

int delete_node_at_tail(list_t *pList)
{
    if(!pList || pList->size == 0)
        return -1;
    else if(pList->size == 1)
    {
        free(pList->pHead);
        pList->pHead = NULL;
        pList->pTail = NULL;
        pList->size--;
    }
    else
    {
        node_t *pCurrent = pList->pHead;
        while(pCurrent->pNext != pList->pTail)
            pCurrent = pCurrent->pNext;

        free(pList->pTail);
        pList->pTail = pCurrent;
        pList->pTail->pNext = NULL;
        pList->size--;
    }

    return 0;
}

int delete_node_with_match_data_from_sll(list_t *pList, int match_data)
{
    if(!pList || pList->size == 0)
        return -1;
    if(pList->pHead->data == match_data)
        return delete_node_at_head(pList);
    if(pList->pTail->data == match_data)
        return delete_node_at_tail(pList);
    if(pList->size == 1)
    {
        if(pList->pHead->data == match_data)
        {
            free(pList->pHead);
            pList->pHead = NULL;
            pList->pTail = NULL;
            pList->size--;
            return 0;
        }
        else
            return -1;
    }
    else {
        node_t *pCurrent = pList->pHead;
        while(pCurrent->pNext != NULL)
        {
            if(pCurrent->pNext->data == match_data)
            {
                node_t *pTemp = pCurrent->pNext;
                pCurrent->pNext = pCurrent->pNext->pNext;
                free(pTemp);
                pTemp = NULL;
                pList->size--;
                return 0;
            }
            pCurrent = pCurrent->pNext;
        }
    }

    return -1;
}

int delete_node_from_position(list_t *pList, int position)
{
    if(!pList || pList->size == 0)
        return -1;
    else if(position < 0 || position >= pList->size)
        return -1;
    else if(position == 0)
        return delete_node_at_head(pList);
    else if(position == pList->size - 1)
        return delete_node_at_tail(pList);
    else
    {
        node_t *pCurrent = pList->pHead;
        for(int i = 0; i < position - 1; i++)
            pCurrent = pCurrent->pNext;

        node_t *pTemp = pCurrent->pNext;
        pCurrent->pNext = pCurrent->pNext->pNext;
        free(pTemp);
        pTemp = NULL;
        pList->size--;
    }

    return 0;
}

void print_sll_nodes(list_t *pList)
{
    if(!pList || pList->size == 0)
    {
        printf("NULL\n");
        return;
    }
    if(pList->size == 1)
    {
        printf("%d -> NULL\n", pList->pHead->data);
        return;
    }
    else
    {
        node_t *pCurrent = pList->pHead;
        while(pCurrent != NULL)
        {
            printf("%d -> ", pCurrent->data);
            pCurrent = pCurrent->pNext;
        }
        printf("NULL\n");
    }
}

void free_sll_nodes(list_t *pList)
{
    if(!pList || pList->size == 0)
        return;
    else if(pList->size == 1)
    {
        free(pList->pHead);
        pList->pHead = NULL;
        pList->pTail = NULL;
        pList->size--;
    }
    else
    {
        node_t *pCurrent = pList->pHead;
        while(pCurrent != NULL)
        {
            node_t *pTemp = pCurrent;
            pCurrent = pCurrent->pNext;
            free(pTemp);
            pTemp = NULL;
        }
        pList->pHead = NULL;
        pList->pTail = NULL;
        pList->size = 0;
    }
}
