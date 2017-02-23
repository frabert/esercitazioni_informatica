#include <stdio.h>

int main(void) {
    int somma = 0, n;
    do {
        scanf("%d", &n);
        somma += n;
    } while(n != 0);
    printf("%d", somma);
    return 0;
}