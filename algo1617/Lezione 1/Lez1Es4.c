#include <stdio.h>

int main(void) {
    int n, i;
    int* a;
    scanf("%d", &n);
    a = malloc(sizeof(int) * n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for(i = 0; i < n / 2; i++) {
        int tmp = a[i];
        a[i] = a[n - (i + 1)];
        a[n - (i + 1)] = tmp;
    }
    
    for(i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}