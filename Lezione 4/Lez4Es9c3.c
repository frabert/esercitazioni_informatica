#include <stdio.h>

void leggiVettore(int *a, int n) {
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void stampaVettore(int *a, int n) {
    int i;
    printf("[");
    for(i = 0; i < n - 1; i++) {
        printf("%d,", a[i]);
    }
    printf("%d]\n", a[i]);
}

int main(void) {
    int a[5];
    int b[5];
    int c[5];
    int i;
    leggiVettore(a, 5);
    leggiVettore(b, 5);
    stampaVettore(a, 5);
    stampaVettore(b, 5);
    
    for(i = 0; i < 5; i++) {
        c[i] = a[i] + b[i];
    }
    stampaVettore(c, 5);
}