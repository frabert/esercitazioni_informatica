#include <stdio.h>

int main(void) {
    int n, i, primo = 1;
    scanf("%d", &n);
    i = 2;
    while(i < n && primo) {
        if(n % i == 0) {
            primo = 0;
        }
        i++;
    }
    printf("%d", primo);
    return 0;
}