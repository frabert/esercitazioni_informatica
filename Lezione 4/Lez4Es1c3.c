#include <stdio.h>

int main(void) {
    int a[10];
    int i, b;
    for(i = 0; i<10; i++) {
        scanf("%d", &a[i]);
    }
    
    for(i = 1; i <= 10; i++) {
        b = a[10 - i];
        if(b % 2 == 0) {
            b = b/2;
        }
        printf("%d\n", b);
    }
}