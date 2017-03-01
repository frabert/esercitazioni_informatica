#include <stdlib.h>
#include <stdio.h>

char* my_strcat(char* a, char* b) {
    int i, j;
    i = 0;
    j = 0;
    while(a[i] != 0) {
        i++;
    }
    while(b[j] != 0) {
        a[i + j] = b[j];
        j++;
    }
    return a;
}

int main(void) {
    unsigned char a[1000];
    unsigned char b[1000];
    scanf("%s", a);
    scanf("%s", b);
    printf("%s", my_strcat(a, b));
    return 0;
}