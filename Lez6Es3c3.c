#include <stdio.h>
#include <stdlib.h>

int* dinAlloc(int n) {
    int* array = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        array[i] = 5 * (i + 1);
    }
    return array;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* array = dinAlloc(n);
    for(int i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }
    free(array);
    return 0;
}