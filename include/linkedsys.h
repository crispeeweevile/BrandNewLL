#include <stdbool.h>
#define METHOD_FAIL NULL;

typedef enum efError {
    FSUCCESS = 0, // general success
    FFAILURE = -1, // encompasses all errors
    FBADARG  = -2, // encompasses all bad arg errors
    FNULLARG = -3, // only on null arg errors
} fError;

typedef struct sData {
    int money;
    int items;
    int debt;
} Data;

typedef struct sNode {
    Data *data;
    struct sNode *prev;
    struct sNode *next;
} Node;

typedef struct sLList {
    Node *current;
    Node *head;
    Node *tail;
} LList;

Data *new_data(int iMoney, int iItems, int iDebt);
fError free_data(Data **data);

LList *new_llist(Data *data);
fError free_llist(LList **list, bool bFreeData);
Node *insert_at_tail(LList **list, Node *node);

Node *new_node(Data *data);
fError free_node(Node **node, bool bFreeData);
Data **get_data(Node *node);
Node *goto_next(LList **list);
Node *goto_prev(LList **list);
Node *goto_first(LList **list);
Node *goto_last(LList **list);
