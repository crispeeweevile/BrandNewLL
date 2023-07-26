#include "linkedsys.h"
#include "general_utils.h"

Data *new_data(int iMoney, int iItems, int iDebt) {
    Data *nData = smalloc(sizeof(Data));
    nData->money = iMoney;
    nData->items = iItems;
    nData->debt = iDebt;

    return nData;
}

fError free_data(Data **data) {
    if (!data || !(*data)) return FNULLARG;
    free(*data);
    (*data) = NULL;
    data = NULL;
    return FSUCCESS;
}


LList *new_llist(Data *data) {

}

fError free_llist(LList **list) {

}

Node *insert_at_tail(LList **list, Node *node) {

}


Node *new_node(Data *data) {
    Node *nNode = smalloc(sizeof(Node));
    nNode->data = data;
    nNode->next = NULL;
    nNode->prev = NULL;

    return nNode;
}

fError free_node(Node **node, bool bFreeData) {
    if (!node || !(*node)) return FNULLARG;
    if (bFreeData) {
        if (free_data((&(*node)->data)) != FSUCCESS) {
            fputs("Failed to free data from node!", stderr);
        }
    }

    (*node)->next = NULL;
    (*node)->prev = NULL;
    (*node)->data = NULL;
    free((*node));
    (*node) = NULL;
    node = NULL;
    return FSUCCESS;
}

Data **get_data(Node *node) {
    return (&(node->data));
}

Node *goto_next(LList **list) {

}

Node *goto_prev(LList **list) {

}

Node *goto_first(LList **list) {

}

Node *goto_last(LList **list) {

}
