#include <stdlib.h>
#include <stdio.h>

int intersectOrdered(int *a, int na, int *b, int nb) {
    int i = 0, j = 0, num = 0;
    while(i < na && j < nb) {
        if(a[i] == b[j]) {
            i++;
            j++;
            num++;
        } else if(a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    return num;
}

int main(void) {
    int *a, na, *b, nb;
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
    
    printf("%d", intersectOrdered(a, na, b, nb));
    return 0;
}
