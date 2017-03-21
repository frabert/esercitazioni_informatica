#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binSearch(char** a, char* str, int start, int end) {
    int middle, cmp;
    if(start == end) {
        return (strcmp(a[start], str) == 0 ? start : -1);
    } else {
        middle = (start + end) / 2;
        cmp = strcmp(a[middle], str);
        if(cmp > 0) {
            return binSearch(a, str, start, middle);
        } else if(cmp < 0) {
            return binSearch(a, str, middle + 1, end);
        } else {
            return middle;
        }
    }
}
 
int main(void) {
    char** a;
    char str[100];
    int n, i, k;
    scanf("%d", &n);
    a = malloc(sizeof(char*) * n);
    for(i = 0; i < n; i++) {
        a[i] = malloc(sizeof(char) * 100);
        scanf("%s", a[i]);
    }
    
    scanf("%d", &k);
    while(k > 0) {
        scanf("%s", str);
        printf("%d\n", binSearch(a, str, 0, n));
        scanf("%d", &k);
    }
    return 0;
}