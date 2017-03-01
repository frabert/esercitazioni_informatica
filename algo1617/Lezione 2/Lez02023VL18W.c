#include <stdio.h>
#include <stdlib.h>

void reset(int array[], int len) {
    for(len--;len >= 0; len--) {
        array[len] = 0;
    }
}

void add(int array[], int len, int val) {
    if(val < len) {
        array[val]++;
    }
}
 
int main(void) {
    int val, a[10], i;
    reset(a, 10);
    scanf("%d", &val);
    while(val != -1) {
        add(a, 10, val);
        scanf("%d", &val);
    }
    
    for(i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}