#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(char** a, int n) {
    int i, j;
    char* tmp;
    j = 0;
    for(i = 1; i < n; i++) {
        j = i;
        while(j > 0 && strcmp(a[j-1], a[j]) > 0) {
            tmp = a[j];
            a[j] = a[j-1];
            a[j-1] = tmp;
            j--;
        }
    }
}
 
int main(void) {
    char** a;
    int n, i;
    scanf("%d", &n);
    a = malloc(sizeof(char*) * n);
    for(i = 0; i < n; i++) {
        a[i] = malloc(sizeof(char) * 100);
        scanf("%s", a[i]);
    }
    insertionSort(a, n);
    for(i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }
    return 0;
}