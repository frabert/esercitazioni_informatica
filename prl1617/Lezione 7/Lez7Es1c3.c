#include <stdio.h>
#include <stdlib.h>

struct gatto {
    int id;
    int eta;
    float peso;
    int cibo;
};

typedef struct gatto gatto_t;

void leggiGatto(gatto_t* g) {
    scanf("%d%d%f%d", &(g->id), &(g->eta), &(g->peso), &(g->cibo));
}

float calcolaPesoMedio(gatto_t* l, int n) {
    float m = 0;
    for(int i = 0; i < n; i++) {
        m += l[i].peso;
    }
    return m / n;
}

void stampaInfo(gatto_t g) {
    printf("%d ", g.id);
    switch(g.cibo) {
        case 0:
        printf("crocchette\n");
        break;
        case 1:
        printf("scatolette\n");
        break;
        case 2:
        printf("tonno\n");
        break;
    }
}

int main(void) {
    int n;
    gatto_t* gatti;
    scanf("%d", &n);
    gatti = malloc(sizeof(gatto_t) * n);
    
    for(int i = 0; i < n; i++) {
        leggiGatto(&gatti[i]);
    }
    
    float pesoMedio = calcolaPesoMedio(gatti, n);
    for(int i = 0; i < n; i++) {
        if(gatti[i].eta < 4 && gatti[i].peso >= pesoMedio) {
            stampaInfo(gatti[i]);
        }
    }
    
    free(gatti);
    
    return 0;
}