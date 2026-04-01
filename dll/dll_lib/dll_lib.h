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
int del_node_from_dll(node_t **ppHead, int data);
void print_dll_nodes(node_t *pHead);
void free_dll_nodes(node_t **ppHead);

#endif
