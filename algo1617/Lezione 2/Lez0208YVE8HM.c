#include <stdlib.h>
#include <stdio.h>

int my_strcmp(char* s1, char* s2) {
    int i = 0;
    while(s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0) {
        i++;
    }
    if(s1[i] > s2[i]) {
        return 1;
    } else if(s1[i] < s2[i]) {
        return -1;
    } else {
        return 0;
    }
}

int main(void) {
    unsigned char a[1000];
    unsigned char b[1000];
    int res;
    scanf("%s", a);
    scanf("%s", b);
    res = my_strcmp(a, b);
    if(res <= 0) {
        printf("%d", res);
    } else {
        printf("+1");
    }
    return 0;
}