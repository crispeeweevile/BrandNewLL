#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "general_utils.h"
#include "linkedsys.h"

int main(int argc, char *argv[]) {
    // This is the main file, it might look a little weird
    // but it's used for testing purposes, at least for now.
    Node *nNode;
    Data **lData;
    nNode = new_node(new_data(5, 6, 2));
    lData = get_data(nNode);

    printf("nNode_dStruct: %p; lData: %p\n", nNode->data, *lData);
    printf("nmoney: %d; nitems: %d; ndebt: %d\n", nNode->data->money, nNode->data->items, nNode->data->debt);
    printf("lmoney: %d; litems: %d; ldebt: %d\n", (*lData)->money, (*lData)->items, (*lData)->debt);

    free_node(&nNode, true);
    printf("nNode_dStruct: %p; lData: %p\n", nNode, *lData);
    if (!(*lData)) {
        printf("*lData was actually null\n");
    } else printf("lmoney: %d; litems: %d; ldebt: %d\n", (*lData)->money, (*lData)->items, (*lData)->debt);
    

    if (nNode == NULL) {
        printf("Yay! you freed them!\n");
    }
    
    return 0;
}
