#include <stdio.h>
#include <stdlib.h>
#include "dll_lib.h"

int main(void)
{
    node_t *pHead = NULL;
    add_node_to_dll(&pHead, 1);
    add_node_to_dll(&pHead, 2);
    add_node_to_dll(&pHead, 3);

    print_dll_nodes(pHead);
    del_node_from_dll(&pHead, 3);
    print_dll_nodes(pHead);
    free_dll_nodes(&pHead);
    print_dll_nodes(pHead);
}
