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
    
}


LList *new_llist(Data *data) {

}

fError free_llist(LList **list) {

}

Node *insert_at_tail(LList **list, Node *node) {

}


Node *new_node(Data *data) {

}

fError free_node(Node **node) {

}

Node *goto_next(LList **list) {

}

Node *goto_prev(LList **list) {

}

Node *goto_first(LList **list) {

}

Node *goto_last(LList **list) {

}
