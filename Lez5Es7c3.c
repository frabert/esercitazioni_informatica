#include <stdio.h>

int count_larger(int x, int a[], int dim) {
    int tmp = 0;
    for(int i = 0; i < dim; i++)
        if(a[i] > x) tmp++;
    return tmp;
}

int main() {
    int z;
    int a[5];
    scanf("%d", &z);
    for(int i = 0; i < 5; i++)
        scanf("%d", &a[i]);
    printf("%d", count_larger(z, a, 5));
    return 0;
}