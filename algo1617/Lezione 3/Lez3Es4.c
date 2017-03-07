#include <stdlib.h>
#include <stdio.h>

int* orderedSum(int *a, int na, int *b, int nb) {
    int *res = malloc(sizeof(int) * (na + nb));
    int i = 0, j = 0, k = 0;
    while(k < (na + nb)) {
        if(i < na && j < nb) {
            if(a[i] < b[j]) {
                res[k] = a[i];
                i++;
            } else {
                res[k] = b[j];
                j++;
            }
        } else if(i < na) {
            res[k] = a[i];
            i++;
        } else {
            res[k] = b[j];
            j++;
        }
        k++;
    }
    
    return res;
}

int main(void) {
    int *a, na, *b, nb, *c;
    int i;
    scanf("%d", &na);
    a = malloc(sizeof(int) * na);
    for(i = 0; i < na; i++) {
        scanf("%d", &a[i]);
    }
    
    scanf("%d", &nb);
    b = malloc(sizeof(int) * nb);
    for(i = 0; i < nb; i++) {
        scanf("%d", &b[i]);
    }
    
    c = orderedSum(a, na, b, nb);
    for(i = 0; i < na + nb; i++) {
        printf("%d\n", c[i]);
    }
    return 0;
}
