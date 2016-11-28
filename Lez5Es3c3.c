#include <stdio.h>

float sum_pow(int n, float x) {
    float sum = 0;
    for(int i = 0; i <= n; i++) {
        float base = 1;
        for(int j = 0; j < i; j++)
            base = base * x;
        sum += base;
    }
    return sum;
}

int main() {
    int n;
    float x;
    scanf("%d%f", &n, &x);
    printf("%.2f", sum_pow(n, x));
    return 0;
}