#include <stdlib.h>
#include <stdio.h>

char* my_strcpy(char* src, char* dest) {
    int i = 0;
    do {
        dest[i] = src[i];
        i++;
    } while(src[i] != 0);
    return dest;
}

int main(void) {
    char a[1000];
    char *b;
    b = malloc(sizeof(char) * 1000);
    scanf("%s", a);
    b = my_strcpy(a, b);
    printf("%s", b);
    
    return 0;
}