#include <stdio.h>

void ordered_swap(int* a, int* b, int* c) {
    int ordered = 0;
    while(!ordered) {
        ordered = 1;
        if(*a > *b) {
            int tmpa = *a;
            *a = *b;
            *b = tmpa;
            ordered = 0;
        }
        if(*b > *c) {
            int tmpb = *b;
            *b = *c;
            *c = tmpb;
            ordered = 0;
        }
    }
}

int main(void) {
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    ordered_swap(&a, &b, &c);
    printf("%d\n%d\n%d", a, b, c);
    return 0;
}