#include <stdio.h>

void stampaRiga(char bordo, char dentro, int n) {
    int i;
    printf("%c", bordo);
    for(i = 0; i < n - 2; i++){
        printf("%c", dentro);
    }
    if(n != 1)
        printf("%c", bordo);
}

int main(void) {
    int h,l,i;
    scanf("%d", &h);
    scanf("%d", &l);
    stampaRiga('*', '*', l);
    printf("\n");
    for(i = 0; i < h - 2; i++){
        stampaRiga('*', ' ', l);
        printf("\n");
    }
    if(h != 1)
        stampaRiga('*', '*', l);
}