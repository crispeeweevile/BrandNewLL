#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "general_utils.h"
#include "linkedsys.h"

int main(int argc, char *argv[]) {
    // This is the main file, it might look a little weird
    // but it's used for testing purposes, at least for now.
    /*{
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
    }*/

    {
        Node *abc = new_node(new_data(1, 0, 22));
        Node *bc = new_node(new_data(0, 7, 2));
        Node *cd = new_node(new_data(4, 2, 0));
        LList *tList = new_llist(new_data(5, 77, 0));
        insert_at_tail(&tList, abc);
        insert_at_tail(&tList, bc);
        insert_at_tail(&tList, cd);
        //goto_last(&tList);
        
        int tlLength = 0;
        fError aErr = get_length(&tList, &tlLength);
        if (aErr == FSUCCESS) {
            for (int i=0; i < tlLength; i++) {
                printf("xMoney: %d; xItems: %d; xDebt: %d\n", tList->current->data->money, tList->current->data->items, tList->current->data->debt);
                if (next_exists(&tList)) {
                    goto_next(&tList);
                } else {printf("No next!\n"); break;}
            }
        }

        goto_first(&tList);
        free_llist(&tList, true);

        printf("dad says it might be going bye bye here\n");
        printf("Cur: %p; Hed: %p; Tal: %p\n", tList->current, tList->head, tList->tail);
        printf("DataP: %p; NP: %p; PP: %p\n", tList->tail->data, tList->tail->next, tList->tail->prev);
        printf("dM: %d; dI: %d; dD: %d\n", tList->tail->data->money, tList->tail->data->items, tList->tail->data->debt);

        printf("good\n");
    }

    return 0;
}
