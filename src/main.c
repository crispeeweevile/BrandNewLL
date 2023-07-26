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
        LList *tList = new_llist(new_data(5, 77, 0));
        printf("v1cur: %p; head: %p; tail: %p\n", (*tList->current), (*tList->head), (*tList->tail));
        Node *abc = new_node(new_data(1, 0, 22));
        Node *bc = new_node(new_data(0, 7, 2));
        Node *cd = new_node(new_data(4, 2, 0));
        insert_at_tail(&tList, abc);
        printf("v2cur: %p; head: %p; tail: %p\n", (*tList->current), (*tList->head), (*tList->tail));
        insert_at_tail(&tList, bc);
        printf("v3cur: %p; head: %p; tail: %p\n", (*tList->current), (*tList->head), (*tList->tail));
        insert_at_tail(&tList, cd);
        printf("v4cur: %p; head: %p; tail: %p\n", (*tList->current), (*tList->head), (*tList->tail));
        //exit(1);

        //*
        //printf("tListPTR: %p\n", tList);
        //printf("tListCurDP: %p\n", (tList->current));
        printf("tListCurPTR: %p\n", (*tList->current));
        printf("tListCurNextPTR: %p\n", (*tList->current)->next);
        //printf("tLCN, M: %d; I: %d; D: %d\n", (*tList->current)->next->data->money, (*tList->current)->next->data->items, (*tList->current)->next->data->debt);
        printf("tListCurNextNextPTR: %p\n", (*tList->current)->next->next);
        //*/

        printf("tListCur: %p; tListCurP: %p; tListCurN: %p\n", (*tList->current), (*tList->current)->prev, (*tList->current)->next);
        
        if (!tList) printf("tList");
        if (!(tList->current)) printf("currentDP");
        if (!(*tList->current)) printf("currentPTR");
        if (!((*tList->current)->next)) printf("currentNextPTR");

        while ((*tList->current)->next)
        {
            printf("oh shit\n");
            Node *cur = (*tList->current);
            printf("Money: %d; Items: %d; Debt: %d\n", cur->data->money, cur->data->items, cur->data->debt);
            ((tList)->current) = (&(*tList->current)->next);
            printf("fukr\n");
            
        }
        
    }

    return 0;
}
