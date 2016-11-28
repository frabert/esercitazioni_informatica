#include <stdio.h>

float approx_pi(int n) {
    int tmp = 1;
    float sum = 0;
    for(int i = 0; i < n; i++) {
        int div = 2*i + 1;
        sum += tmp * (4.0 / div);
        tmp *= -1;
    }
    return sum;
}

int main() {
    int z;
    scanf("%d", &z);
    printf("%.6f", approx_pi(z));
    return 0;
}