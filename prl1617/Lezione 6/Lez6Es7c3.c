#include <stdio.h>
#include <stdlib.h>

void stampaMatrice(int** a, int h, int w) {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d\n", a[i][w - 1]);
    }
}

int** leggiMatrice(int h, int w) {
    int** mat = malloc(sizeof(int*) * h);
    for(int i = 0; i < h; i++) {
        mat[i] = malloc(sizeof(int) * w);
        for(int j = 0; j < w; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    return mat;
}

int** creaMatrice(int h, int w) {
    int** mat = malloc(sizeof(int*) * h);
    for(int i = 0; i < h; i++) {
        mat[i] = malloc(sizeof(int) * w);
    }
    return mat;
}

int main(void) {
    int n, m, t;
    int **a, **b, **c;
    scanf("%d%d%d", &n, &m, &t);
    
    a = leggiMatrice(n, m);
    b = leggiMatrice(m, t);
    c = creaMatrice(n, t);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < t; j++) {
            int temp = 0;
            for(int r = 0; r < m; r++) {
                temp += a[i][r] * b[r][j];
            }
            c[i][j] = temp;
        }
    }
    
    stampaMatrice(c, n, t);
    
    return 0;
}