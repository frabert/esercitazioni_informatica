#include <stdio.h>
#include <stdlib.h>

char* product(char* str, int k) {
    char *newstr = malloc(sizeof(char) * 1000 * k);
    int i, len;
    i = 0;
    while(str[i] != 0) {
        newstr[i] = str[i];
        i++;
    }
    len = i;
    
    for(; i < len * k; i++) {
        newstr[i] = str[i % len];
    }
    return newstr;
}
 
int main(void) {
    char s[10000];
    int k;
    scanf("%s", s);
    scanf("%d", &k);
    printf("%s", product(s, k));
    return 0;
}