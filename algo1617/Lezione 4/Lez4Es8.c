#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*
!!!!!!!!!!!! D A  F A R E !!!!!!!!!!!!
sx e dx sono le posizioni del primo e dell'ultimo elemento dell'array mentre
px è la posizione dell'elemento perno.
La funzione deve restituire la posizione del perno dopo che gli elementi sono
stati partizionati.
*/
int distribuzione(int a[], int sx, int px, int dx, int *pn) {
    int pivot = a[px];
    int i = sx - 1, j, tmp;
    tmp = a[dx];
    a[dx] = a[px];
    a[px] = tmp;
    px = dx;
    *pn = 1;

    for (j = sx; j < dx; j++) {
        if(a[j] == pivot) *pn++;
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

void quicksort(int a[], int sx, int dx) {

    int perno, pivot, pn;
    if (sx < dx) {
        /* DA IMPLEMENTARE: scelta del pivot. Scegliere una posizione a caso tra sx e dx inclusi. */
        pivot = (rand() % (dx - sx + 1)) + sx;

        perno = distribuzione(a, sx, pivot, dx, &pn); /* separa gli elementi minori di a[pivot]
                                                 da quelli maggiori o uguali */
                                                 /* Ordina ricorsivamente le due metà */
        quicksort(a, sx, perno - pn);
        quicksort(a, perno + 1, dx);

    }

}

/* Lettura di un array di interi da input.
Il primo elemento è la lunghezza dell'array */
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
    quicksort(A, 0, n - 1);

    /* Stampa l'array ordinato */
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
