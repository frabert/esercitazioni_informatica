#include <stdio.h>

float media(int a[], int dim) {
    int sum = 0;
    int n = 0;
    if(a[dim - 1] < 0) {
        for(int i = 0; i < dim; i++) {
            if(a[i] < 0) {
                sum += a[i];
                n++;
            }
        }
    } else {
        for(int i = 0; i < dim; i++) {
            if(a[i] > 0) {
                sum += a[i];
                n++;
            }
        }
    }
    return (float)sum / n;
}

int main() {
    int a[10];
    for(int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    printf("%.2f", media(a, 10));
    return 0;
}