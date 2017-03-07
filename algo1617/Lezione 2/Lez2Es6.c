#include <stdlib.h>
#include <stdio.h>

char* my_strcat(int la, char* a, int lb, char* b) {
    char *s = calloc(la + lb + 1, sizeof(char));
    int i, j;
    for(i = 0; i < la; i++) {
        s[i] = a[i];
    }
    for(j = 0; j < lb; j++) {
        s[i + j] = b[j];
    }
    return s;
}

int main(void) {
    unsigned char a[1000];
    unsigned char b[1000];
    int la, lb;
    scanf("%d", &la);
    scanf("%s", a);
    scanf("%d", &lb);
    scanf("%s", b);
    printf("%s", my_strcat(la, a, lb, b));
    return 0;
}