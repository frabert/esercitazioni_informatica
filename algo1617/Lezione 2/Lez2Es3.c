#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *s) {
    int i = 0;
    while(s[i] != 0) i++;
    return i;
}
 
int main(void) {
    char s[10000];
    scanf("%s", s);
    printf("%d", my_strlen(s));
    return 0;
}