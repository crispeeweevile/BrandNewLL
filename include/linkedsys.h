#include <stdbool.h>
#define METHOD_FAIL NULL;

typedef enum fError {
    FSUCCESS=0, // general success
    FFAILURE=-1, // encompasses all errors
    FBADARG=-2, // encompasses all bad arg errors
    FNULLARG=-3, // only on null arg errors
} fError;

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

Data *new_data(int iMoney, int iItems, int iDebt);

