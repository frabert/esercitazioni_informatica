#include <stdio.h>
#include <stdlib.h>

typedef struct elem_struct {
    int val;
    struct elem_struct *next;
} elem;

void addTail(elem** list, int v) {
    elem* e = malloc(sizeof(elem));
    e->val = v;
    e->next = NULL;
    elem* cur = *list;
    if(*list == NULL) {
        *list = e;
    } else {
        while(cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = e;
    }
}

void addHead(elem** list, int v) {
    elem* e = malloc(sizeof(elem));
    e->val = v;
    e->next = *list;
    *list = e;
}

void rem(elem** list, int v) {
    if(*list == NULL) {
        return;
    }
    if ((*list)->val == v) {
        elem* e = (*list)->next;
        free(*list);
        *list = e;
        return;
    }
    elem* cur = *list;
    elem* next = cur->next;
    
    while(cur != NULL && next != NULL) {
        if(next->val == v) {
            elem* newNext = next->next;
            free(next);
            cur->next = newNext;
            return;
        }
        cur = next;
        next = cur->next;
    }
}

int main(void) {
    int input;
    elem* list = NULL;
    scanf("%d", &input);
    while(input != 0) {
        if(input < 0) {
            rem(&list, -input);
        } else if(input % 2 == 0) {
            addHead(&list, input);
        } else {
            addTail(&list, input);
        }
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