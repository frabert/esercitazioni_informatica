#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node_struct {
    int val;
    struct ll_node_struct *prec;
} ll_node;

ll_node* push (ll_node *head, int v) {
    ll_node* e = malloc(sizeof(ll_node));
    e->val = v;
    e->prec = head;
    return e;
}

ll_node* pop(ll_node *head) {
    if(head != NULL) {
        ll_node* prec = head->prec;
        free(head);
        return prec;
    } else {
        return NULL;
    }
}

void print(ll_node *head) {
    while(head != NULL) {
        printf("%d\n", head->val);
        head = head->prec;
    }
}

int main(void) {
    int input;
    ll_node* list = NULL;
    scanf("%d", &input);
    while(input >= 0) {
        if(input > 0) {
            list = push(list, input);
        } else {
            list = pop(list);
        }
        scanf("%d", &input);
    }
    print(list);
    return 0;
}