#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int distribuzione(int a[], int sx, int px, int dx) {
    int pivot = a[px];
    int i = sx - 1, j, tmp;
    tmp = a[dx];
    a[dx] = a[px];
    a[px] = tmp;
    px = dx;

    for (j = sx; j < dx; j++) {
        if (a[j] <= pivot) {
            i++;
            tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        }
    }
    i++;
    tmp = a[i];
    a[i] = pivot;
    a[px] = tmp;
    return i;
}

int distribuzione_stramba(int a[], int sx, int dx) {
    int i = sx - 1, j, tmp;
    for (j = sx; j < dx + 1; j++) {
        if (a[j] % 2 == 0) {
            i++;
            tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        }
    }
    return i + 1;
}

void quicksort(int a[], int sx, int dx) {
    int perno, pivot;
    if (sx < dx) {
        pivot = (rand() % (dx - sx + 1)) + sx;

        perno = distribuzione(a, sx, pivot, dx);
        quicksort(a, sx, perno - 1);
        quicksort(a, perno + 1, dx);
    }
}

void quicksort_strambo(int a[], int sx, int dx) {
    int perno, pivot;
    if (sx < dx) {
        perno = distribuzione_stramba(a, sx, dx);

        quicksort(a, sx, perno - 1);
        quicksort(a, perno, dx);
    }
}

int legge(int **a, int *len) {

    int i;
    scanf("%d", len);
    if (*len <= 0) return 1;

    *a = (int *)malloc(*len * sizeof(int));
    if (*a == NULL) return 1;

    for (i = 0; i < *len; i++)
        scanf("%d", (*a) + i);

    return 0;

}

int main() {

    int i, n, *A;

    if (legge(&A, &n)) return 1;

    srand(time(NULL));
    quicksort_strambo(A, 0, n - 1);

    /* Stampa l'array ordinato */
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
