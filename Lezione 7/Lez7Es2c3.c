#include <stdio.h>
#include <stdlib.h>

struct studente {
    int mat;
    int eta;
    int sesso;
};
typedef struct studente studente_t;

void leggiStudente(studente_t* s) {
    scanf("%d%d%d", &s->mat, &s->eta, &s->sesso);
}

void calcolaMedia(studente_t* l, int n, int sesso, float* mean, int* count) {
    *count = 0;
    *mean = 0;
    
    int c = 0;
    float m = 0;
    
    for(int i = 0; i < n; i++) {
        if(l[i].sesso == sesso) {
            c++;
            m += (float)l[i].eta;
        }
    }
    if(c != 0) {
        *mean = m / c;
        *count = c;
    }
}

void calcolaVarianza(studente_t* l, int n, int sesso, float mean, int count, float* var) {
    *var = 0;
    float v = 0;
    if(count == 0 || count == 1) {
        return;
    }
    for(int i = 0; i < n; i++) {
        if(l[i].sesso == sesso) {
            int eta = l[i].eta;
            v += (eta - mean) * (eta - mean);
        }
    }
    *var = v / (count - 1);
}

int main(void) {
    int n, m;
    studente_t* studenti;
    scanf("%d", &n);
    
    studenti = malloc(sizeof(studente_t) * n);
    
    for(int i = 0; i < n; i++) {
        leggiStudente(&studenti[i]);
    }
    scanf("%d", &m);
    
    int nM, nF;
    float mediaM, mediaF, varM, varF;
    
    calcolaMedia(studenti, n, 0, &mediaM, &nM);
    calcolaMedia(studenti, n, 1, &mediaF, &nF);
    calcolaVarianza(studenti, n, 0, mediaM, nM, &varM);
    calcolaVarianza(studenti, n, 1, mediaF, nF, &varF);
    
    printf("%.2f\n%.2f\n", mediaM, varM);
    printf("%.2f\n%.2f\n", mediaF, varF);
    
    int e = -1, s = -1;
    for(int i = 0; i < n; i++) {
        if(studenti[i].mat == m) {
            e = studenti[i].eta;
            s = studenti[i].sesso;
        }
    }
    
    printf("%d\n", e);
    if(s == 0) {
        printf("M\n");
    } else if(s == 1) {
        printf("F\n");
    } else {
        printf("%d\n", s);
    }
    
    return 0;
}