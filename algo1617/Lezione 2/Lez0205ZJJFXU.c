#include <stdlib.h>
#include <stdio.h>

char* my_strcat(char* a, char* b) {
    char *s = calloc(2000, sizeof(char));
    int i, j;
    i = 0; j = 0;
    while(a[i] != 0) {
        s[i] = a[i];
        i++;
    }
    while(b[j] != 0) {
        s[i + j] = b[j];
        j++;
    }
    return s;
}

int main(void) {
    unsigned char a[1000];
    unsigned char b[1000];
    scanf("%s", a);
    scanf("%s", b);
    printf("%s", my_strcat(a, b));
    return 0;
}