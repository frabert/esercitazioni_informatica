#include <stdio.h>

int main(void) {
    int a[10];
    int i, res;
    res = -1;
    for(i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    for(i = 1; i < 9 && res == -1; i++) {
        if(a[i] == a[i+1] - a[i-1]) {
            res = i;
        }
    }
    printf("%d", res);
}