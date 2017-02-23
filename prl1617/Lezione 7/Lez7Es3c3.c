#include <stdio.h>
#include <stdlib.h>

struct esercizio {
    int lezione;
    int id;
    int numStud;
    int* matStud;
};
typedef struct esercizio esercizio_t;

int contieneMat(int* l, int n, int x) {
    for(int i = 0; i < n; i++) {
        if(l[i] == x) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, m;
    esercizio_t* esercizi;
    scanf("%d", &n);
    esercizi = malloc(sizeof(esercizio_t) * n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &esercizi[i].lezione, &esercizi[i].id, &esercizi[i].numStud);
        esercizi[i].matStud = malloc(sizeof(int) * esercizi[i].numStud);
        for(int j = 0; j < esercizi[i].numStud; j++) {
            scanf("%d", &esercizi[i].matStud[j]);
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < n; i++) {
        if(contieneMat(esercizi[i].matStud, esercizi[i].numStud, m)) {
            printf("%d.%d\n", esercizi[i].lezione, esercizi[i].id);
        }
    }
    return 0;
}