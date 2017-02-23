#include <stdio.h>
#include <stdlib.h>

typedef struct elem_struct {
    int val;
    struct elem_struct *next;
} elem;

void add(elem** list, int v) {
    elem* e = malloc(sizeof(elem));
    elem* prec = NULL;
    elem* cur = *list;
    int found = 0;
    e->val = v;
    e->next = NULL;
    while(cur != NULL && !found) {
        if(cur->val >= v) found=1;
        else {
            prec = cur;
            cur = cur->next;
        }
    }
    if(found) {
        e->next = cur;
        if(prec != NULL) {
            prec->next = e;
        } else {
            *list = e;
        }
    } else {
        if(cur != NULL) {
            cur->next = e;
        } else {
            if(prec == NULL) {
                *list = e;
            } else {
                prec->next = e;
            }
        }
    }
}

int main(void) {
    int input;
    elem* list = NULL;
    scanf("%d", &input);
    while(input > 0) {
        add(&list, input);
        scanf("%d", &input);
    }
    while(list != NULL) {
        printf("%d\n", list->val);
        elem* next = list->next;
        free(list);
        list = next;
    }
    return 0;
}