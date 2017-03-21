#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *a, int n) {
    int i, j, tmp;
    j = 0;
    for(i = 1; i < n; i++) {
        j = i;
        while(j > 0 && a[j-1] > a[j]) {
            tmp = a[j];
            a[j] = a[j-1];
            a[j-1] = tmp;
            j--;
        }
    }
}
 
int main(void) {
    int *a, n;
    int i;
    scanf("%d", &n);
    a = malloc(sizeof(int) * n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    insertionSort(a, n);
    for(i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}