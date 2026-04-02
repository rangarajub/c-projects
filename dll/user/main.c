#include <stdio.h>
#include <stdlib.h>
#include "dll_lib.h"

int main(void)
{
    node_t *pHead = NULL;
    add_node_to_dll(&pHead, 10);
    add_node_to_dll(&pHead, 20);
    add_node_to_dll(&pHead, 50);
    add_node_to_dll(&pHead, 30);
    add_node_to_dll(&pHead, 15);
    print_dll_nodes(pHead);
    del_node_from_dll(&pHead, 30);
    print_dll_nodes(pHead);
    reverse_dll(&pHead);
    print_dll_nodes(pHead);
    pHead = reverse_dll_recursive(pHead);
    print_dll_nodes(pHead);
    reverse_dll_iterative(&pHead);
    print_dll_nodes(pHead);
    free_dll_nodes(&pHead);
    print_dll_nodes(pHead);

    return 0;
}
