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
    LList *nLL = smalloc(sizeof(LList));
    Node *nNode = new_node(data);
    nLL->current = nNode;
    nLL->head = nNode;
    nLL->tail = nNode;

    return nLL;
}

fError free_llist(LList **list, bool bFreeData) {

}

Node *insert_at_tail(LList **list, Node *node) {
    if (!list || !(*list)) return FNULLARG;
    if (!node) return FNULLARG;

    (*list)->tail->next = node;
    node->prev = (*list)->tail;

    return node;
}


Node *new_node(Data *data) {
    if (!data) return FNULLARG;
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
            // presumably, if it fails, the data is already free. (so not a big deal?)
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
    if (!node) return FNULLARG;
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
