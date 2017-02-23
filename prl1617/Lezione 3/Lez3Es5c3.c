#include <stdio.h>

int main(void) {
    int n1=0;
    scanf("%d", &n1);
    if(n1 % 2 == 0) {
        printf("1");
    } else {
        printf("0");
    }
    return 0;
}