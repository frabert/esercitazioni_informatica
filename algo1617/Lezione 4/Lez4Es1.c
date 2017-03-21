#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *a, int n) {
    int i, j = 0;
    int imin;
    int tmp;
    while(j < n) {
        imin = j;
        for(i = j; i < n; i++) {
            if(a[i] < a[imin]) {
                imin = i;
            }
        }
        tmp = a[j];
        a[j] = a[imin];
        a[imin] = tmp;
        j++;
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
    selectionSort(a, n);
    for(i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}