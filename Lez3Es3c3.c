#include <stdio.h>

int main(void) {
    float n1,n2,n3;
    scanf("%f", &n1);
    scanf("%f", &n2);
    scanf("%f", &n3);
    printf("%.3f", (n1+n2+n3)/3);
    return 0;
}