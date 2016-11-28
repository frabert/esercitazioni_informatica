#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int* a = malloc(sizeof(int) * 5);
    for(int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &n);
    a = realloc(a, sizeof(int) * (5 + n));
    for(int i = 5; i < 5 + n; i++) {
        int sum = 0;
        for(int j = 0; j < i; j++) {
            sum = sum + a[j];
        }
        a[i] = sum;
    }
    
    for(int i = 0; i < 5 + n; i++) {
        printf("%d\n", a[i]);
    }
    
    return 0;
}