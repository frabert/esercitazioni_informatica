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

int find(elem* list, int v) {
    while(list != NULL) {
        if(list->val == v) return 1;
        else list = list->next;
    }
    return 0;
}

void intersect(elem* a, elem* b, elem** res) {
    while(a != NULL) {
        if(find(b, a->val) && !find(*res, a->val)) {
            add(res, a->val);
        }
        a = a->next;
    }
}



int main(void) {
    int input;
    elem* list1 = NULL;
    elem* list2 = NULL;
    elem* list3 = NULL;
    scanf("%d", &input);
    while(input > 0) {
        add(&list1, input);
        scanf("%d", &input);
    }
    scanf("%d", &input);
    while(input > 0) {
        add(&list2, input);
        scanf("%d", &input);
    }
    
    intersect(list1, list2, &list3);
    
    while(list3 != NULL) {
        printf("%d\n", list3->val);
        elem* next = list3->next;
        free(list3);
        list3 = next;
    }
    return 0;
}