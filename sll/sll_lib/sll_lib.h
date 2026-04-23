#ifndef SLL_LIB_H
#define SLL_LIB_H

#include <stdio.h>
#include <stdlib.h>

// Node of Single Linked List
typedef struct node {
    int data;
    struct node *pNext;
}node_t;

// List Manager Node
typedef struct list {
    node_t *pHead;
    node_t *pTail;
    int size;
}list_t;

// Public API
int insert_node_at_head(list_t *pList, int data);
int insert_node_at_position(list_t *pList, int data, int position);
int insert_node_at_node_with_match_data(list_t *pList, int data, int match_data);
int insert_node_at_tail(list_t *pList, int data);

int delete_node_at_head(list_t *pList);
int delete_node_with_match_data_from_sll(list_t *pList, int match_data);
int delete_node_from_position(list_t *pList, int position);
int delete_node_at_tail(list_t *pList);

void print_sll_nodes(list_t *pList);
void free_sll_nodes(list_t *pList);

#endif // SLL_LIB_H