#include <stdlib.h>
#include <stdio.h>

int* freq(unsigned char* c) {
    int i, *a;
    a = calloc(256, sizeof(int));
    i = 0;
    while(c[i] != 0) {
      a[c[i]]++;
      i++;
    }
    return a;
}

int anagramma(unsigned char *a, unsigned char *b) {
    int *fa, *fb, i;
    fa = freq(a);
    fb = freq(b);
    for(i = 0; i < 256; i++) {
        if(fa[i] != fb[i]) {
          return 0;
        }
    }
    return 1;
}

int main(void) {
    unsigned char a[1000];
    unsigned char b[1000];
    scanf("%s", a);
    scanf("%s", b);
    printf("%d", anagramma(a, b));
    return 0;
}
