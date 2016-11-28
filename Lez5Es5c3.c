#include <stdio.h>

float approx_sqrt(int z) {
    if(z == 0) return 1;
    
    return (approx_sqrt(z - 1) + (float)z/approx_sqrt(z - 1)) / 2;
}

int main() {
    int z;
    scanf("%d", &z);
    printf("%.4f", approx_sqrt(z));
    return 0;
}