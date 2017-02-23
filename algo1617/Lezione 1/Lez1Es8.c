#include <stdio.h>

void minmax(int *a, int n, int *min, int *max) {
    int i;
    *min = 0;
    *max = 1;
    
    for(i = 0; i < n; i++) {
        if(a[i] > a[*max]) {
            *max = i;
        } else if(a[i] < a[*min]) {
            *min = i;
        }
    }
}

int main(void) {
    int a[10];
    int min, max;
    int i;
    for(i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    
    minmax(a, 10, &min, &max);
    
    printf("%d\n%d\n", min, a[min]);
    printf("%d\n%d\n", max, a[max]);
    
    return 0;
}