#include <stdio.h>

int main(void) {
    int n, i;
    scanf("%d", &n);
    while(n >= 1) {
        for(i = 0; i < n; i++) {
            printf("*");
        }
        printf("\n");
        n -= 2;
    }
}