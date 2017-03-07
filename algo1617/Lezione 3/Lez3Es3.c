#include <stdlib.h>
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxSum(int *a, int n) {
    int sum = 0, tempSum, i;
    int sumMax = 0;
    for (i = 0; i < n; i++) {
        tempSum = sum;
        tempSum += a[i];
        if (tempSum < 0) {
            sum = 0;
        } else {
            sum = tempSum;
            sumMax = max(sum, sumMax);
        }
    }
    return sumMax;
}

int main(void) {
    int *a, na;
    int i;
    scanf("%d", &na);
    a = malloc(sizeof(int) * na);
    for(i = 0; i < na; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("%d", maxSum(a, na));
    return 0;
}
