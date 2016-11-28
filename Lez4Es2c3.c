#include <stdio.h>

int main(void) {
    int x;
    int tmp = 1;
    scanf("%d", &x);
    while(x > 0) {
        tmp = tmp * x;
        x--;
    }
    printf("%d\n", tmp);
}