#include <stdio.h>
#include <stdlib.h>

void stampaMatrice(int** a, int w, int h) {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d\n", a[i][w - 1]);
    }
}

int main(void) {
    int* a = malloc(sizeof(int));
    int** mat;
    int n = 0;
    int input;
    
    scanf("%d", &input);
    while(input != -1) {
        n++;
        a = realloc(a, sizeof(int) * n);
        a[n - 1] = input;
        scanf("%d", &input);
    }
    
    mat = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++) {
        mat[i] = malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++) {
            mat[i][j] = a[i] * a[j];
        }
    }
    
    stampaMatrice(mat, n, n);
    
    return 0;
}