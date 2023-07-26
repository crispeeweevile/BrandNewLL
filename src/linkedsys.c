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
    (nLL->current) = nNode;
    (nLL->head) = nNode;
    (nLL->tail) = nNode;

    return nLL;
}

fError free_llist(LList **list, bool bFreeData) {
    if (!list || !(*list)) return FNULLARG;
    Node *fNode = goto_first(list);
    if (!fNode) {printf("Failed to goto_first while freeing list!\n"); return FFAILURE;}
    // goto_next so previous is not NULL
    if (!goto_next(list)) {printf("Failed to goto_next while freeing list!\n"); return FFAILURE;}

    while (prev_exists(list)) {
        Node *prevN = ((*list)->current)->prev;
        if (!prevN) printf("ex45\n");
        free_node(&prevN, true);
        goto_next(list);
    }
    

    if ((*list)->current) {
        if (free_node((&(*list)->current), bFreeData) != FSUCCESS) {printf("Failed to free last node\n"); return FFAILURE;};
        (*list)->current = NULL;
        (*list)->head = NULL;
        (*list)->tail = NULL;
    }
    if ((*list)->head) {
        if (free_node((&(*list)->current), bFreeData) != FSUCCESS) {printf("Failed to free last node\n"); return FFAILURE;};
        (*list)->current = NULL;
        (*list)->head = NULL;
        (*list)->tail = NULL;
    }

    if ((!(*list)->current) && (!(*list)->head) && (!(*list)->tail)) {
        free((*list));
        (*list) = NULL;
        list = NULL;
    }    

    return FSUCCESS;
}

Node *insert_at_tail(LList **list, Node *node) {
    if (!list || !(*list)) return NULL;
    if (!node) return NULL;

    //printf("iat, tailNext: %p; node: %p\n", (*(**list).tail).next, node);

    (*(**list).tail).next = node;
    node->prev = ((**list).tail);
    //printf("iat2, tailNext: %p; node: %p\n", (*(**list).tail).next, node);
    ((**list).tail) = node;

    return node;
}


Node *new_node(Data *data) {
    if (!data) return METHOD_FAIL;
    Node *nNode = smalloc(sizeof(Node));
    nNode->data = data;
    nNode->next = NULL;
    nNode->prev = NULL;

    return nNode;
}

fError free_node(Node **node, bool bFreeData) {
    if (!node || !(*node)) return FNULLARG;
    printf("nonnullnode\n");
    if (bFreeData) {
        if (free_data((&((*node)->data))) != FSUCCESS) {
            // presumably, if it fails, the data is already free. (so not a big deal?)
            fputs("Failed to free data from node!\n", stderr);
        }
    }
    printf("datashuldbfreed\n");
    (*node)->next = NULL;
    (*node)->prev = NULL;
    (*node)->data = NULL;
    printf("nulldpointies\n");
    free((*node));
    printf("free\n");
    (*node) = NULL;
    node = NULL;
    printf("nulldnod\n");
    return FSUCCESS;
}

Data **get_data(Node *node) {
    if (!node) return METHOD_FAIL;
    return (&(node->data));
}

Node *goto_next(LList **list) {
    if (!list || !(*list)) return METHOD_FAIL;
    if (!(*list)->current) return METHOD_FAIL;

    if (next_exists(list)) {
        ((*list)->current) = (((*list)->current)->next);
        return ((*list)->current);
    }

    return METHOD_FAIL;
}

Node *next_exists(LList **list) {
    if (!list || !(*list)) return METHOD_FAIL;
    if (!(*list)->current) return METHOD_FAIL;

    if (((*list)->current)->next) {
        return ((*list)->current)->next;
    } 
    
    return NULL;
}

Node *goto_prev(LList **list) {
    if (!list || !(*list)) return METHOD_FAIL;
    if (!(*list)->current) return METHOD_FAIL;

    if (prev_exists(list)) {
        ((*list)->current) = (((*list)->current)->prev);
        return ((*list)->current);
    }

    return METHOD_FAIL;
}

Node *prev_exists(LList **list) {
    if (!list || !(*list)) return METHOD_FAIL;
    if (!(*list)->current) return METHOD_FAIL;

    if (((*list)->current)->prev) {
        return ((*list)->current)->prev;
    } 
    
    return NULL;
}

Node *goto_first(LList **list) {
    if (!list || !(*list)) return METHOD_FAIL;
    if (!(*list)->current) return METHOD_FAIL;

    if ((*list)->head) {
        ((*list)->current) = (((*list)->head));
        return ((*list)->current);
    }

    return METHOD_FAIL;
}

Node *goto_last(LList **list) {
    if (!list || !(*list)) return METHOD_FAIL;
    if (!(*list)->current) return METHOD_FAIL;

    if ((*list)->tail) {
        ((*list)->current) = (((*list)->tail));
        return ((*list)->current);
    }

    return METHOD_FAIL;
}

fError get_length(LList **list, int *len) {
    if (!list || !(*list) || !len) return FNULLARG;
    if (!(*list)->current) return FBADARG;

    Node *placeholder = (*list)->current;
    while (placeholder->prev) {
        placeholder = placeholder->prev;
    }
    if (placeholder->prev) return FFAILURE;

    int count = 1;
    while (placeholder->next) {
        count++;
        placeholder = placeholder->next;
    }
    if (placeholder->next) return FFAILURE;
    (*len) = count;

    return FSUCCESS;
}
