#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "sll_lib.h"

int main(void)
{
    list_t *pSllList = (list_t *)malloc(sizeof(list_t));
  
    if(!pSllList)
    {
        
        return ENOMEM;
    }

    insert_node_at_head(pSllList, 10);
    insert_node_at_tail(pSllList, 20);
    insert_node_at_tail(pSllList, 30);
    insert_node_at_tail(pSllList, 40);
    insert_node_at_tail(pSllList, 50);
    print_sll_nodes(pSllList);

    free_sll_nodes(pSllList);
    print_sll_nodes(pSllList);

    insert_node_at_head(pSllList, 50);
    insert_node_at_head(pSllList, 40);
    insert_node_at_head(pSllList, 30);
    insert_node_at_position(pSllList, 25, 0);
    print_sll_nodes(pSllList);
    insert_node_at_node_with_match_data(pSllList, 20, 25);
    print_sll_nodes(pSllList);
    insert_node_at_head(pSllList, 10);
    print_sll_nodes(pSllList);

    return 0;
}
