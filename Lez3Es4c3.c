#include <stdio.h>

int main(void) {
    int n1=0;
    int n2=0;
    int n3=0;
    int max;
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    max = n1;
    if(n2>max) {
        max = n2;
    }
    
    if(n3 > max) {
        max = n3;
    }
    printf("%d", max);
}