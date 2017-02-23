#include <stdio.h>

void diff_abs(float* a, float* b) {
    float tmpa = *a;
    *a = *a - *b;
    *b = *b - tmpa;
}

int main(void) {
    float a, b;
    scanf("%f%f", &a, &b);
    diff_abs(&a, &b);
    printf("%.2f\n%.2f", a, b);
    return 0;
}