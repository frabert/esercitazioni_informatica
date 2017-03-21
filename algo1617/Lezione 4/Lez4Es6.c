#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
!!!!!!!!!!!! D A  F A R E !!!!!!!!!!!!
sx e dx sono le posizioni del primo e dell'ultimo elemento dell'array mentre
px è la posizione dell'elemento perno.
La funzione deve restituire la posizione del perno dopo che gli elementi sono
stati partizionati.
*/
int distribuzione(char** a, int sx, int px, int dx) {
    char* pivot = a[px];
    int i = sx - 1, j;
    char* tmp;
    tmp = a[dx];
    a[dx] = a[px];
    a[px] = tmp;
    px = dx;

    for (j = sx; j < dx; j++) {
        if (strcmp(a[j], pivot) <= 0) {
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

void quicksort(char** a, int sx, int dx) {

    int perno, pivot;
    if (sx < dx) {
        /* DA IMPLEMENTARE: scelta del pivot. Scegliere una posizione a caso tra sx e dx inclusi. */
        pivot = (rand() % (dx - sx + 1)) + sx;

        perno = distribuzione(a, sx, pivot, dx); /* separa gli elementi minori di a[pivot]
                                                 da quelli maggiori o uguali */
                                                 /* Ordina ricorsivamente le due metà */
        quicksort(a, sx, perno - 1);
        quicksort(a, perno + 1, dx);

    }

}

int main(void) {
    int n;
    int i;
    char** strings;
    
    scanf("%d", &n);
    strings = malloc(sizeof(char*) * n);
    for(i = 0; i < n; i++) {
        strings[i] = malloc(sizeof(char) * 100);
        scanf("%s", strings[i]);
    }
    
    quicksort(strings, 0, n - 1);
    
    for(i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }
}