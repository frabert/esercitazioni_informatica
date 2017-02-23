#include <stdio.h>

void tswap(int *x, int *y, int *z) {
    int tx = *x;
    int ty = *y;
    *x = *z;
    *y = tx;
    *z = ty;
}

int main(void) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    tswap(&n, &m, &k);
    printf("%d\n%d\n%d", n, m, k);
    
    return 0;
}