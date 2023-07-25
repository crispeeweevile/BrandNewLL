typedef struct Data {
    int money;
    int items;
    int debt;
} Data;

typedef struct Node {
    Data *data;
    Node *prev;
    Node *next;
} Node;