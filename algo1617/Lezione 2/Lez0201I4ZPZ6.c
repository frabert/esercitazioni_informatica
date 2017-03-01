#include <stdio.h>
#include <stdlib.h>

int* FindVal(int a[], int len, int val) {
    int trovato = 0;
    int i = 0;
    while(!trovato && i < len) {
        if(a[i] == val) {
            trovato = 1;
        } else {
            i++;
        }
    }
    
    if(trovato) {
        return &a[i];
    } else {
        return NULL;
    }
}

int main(void) {
    int i, val, a[10], *res;
    for(i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &val);
    
    res = FindVal(a, 10, val);
    
    if(res == NULL) {
        printf("non trovato");
    } else {
        printf("trovato");
    }
    
    return 0;
}