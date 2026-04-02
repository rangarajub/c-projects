#ifndef DLL_LIB_H
#define DLL_LIB_H

#include <stdio.h>
#include <stdlib.h>

// Double Linked List Node Structure
typedef struct node{
    int data;
    struct node *pPrev;
    struct node *pNext;
}node_t;

// Public API

node_t *create_node(int data);
int add_node_to_dll(node_t **ppHead, int data);
int insert_node_at_head(node_t **ppHead, int data);
int del_node_from_dll(node_t **ppHead, int data);
void print_dll_nodes(node_t *pHead);
void free_dll_nodes(node_t **ppHead);
int reverse_dll(node_t **ppHead);
node_t *reverse_dll_recursive(node_t *pCurrent);
int reverse_dll_iterative(node_t **ppHead);
#endif
