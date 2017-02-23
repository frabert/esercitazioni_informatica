#include <stdio.h>

int sommaDispari(int n) {
    if(n == 0) return 1;
    return (2*n + 1) + sommaDispari(n - 1);
}

int main(void) {
    int n;
    scanf("%d", &n);
    
    printf("%d", sommaDispari(n - 1));
    
    return 0;
}