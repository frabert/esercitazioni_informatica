#include <stdlib.h>
#include <stdio.h>

int intersect(int *a, int na, int *b, int nb) {
    int i, j, num = 0, found;
    for(i = 0; i < na; i++) {
        j = 0;
        found = 0;
        while(j < nb && !found) {
            if(a[i] == b[j]) { num++; found = 1; }
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
    
    printf("%d", intersect(a, na, b, nb));
    return 0;
}
