#include <stdio.h>

int main(void) {
    int a[10];
    int i, res;
    res = -1;
    for(i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    
    for(i = 0; i < 10; i++) {
        res = a[i];
        if((res >= 0) && (res % 2 == 0))
        {
            printf("%d\n", res);
        } else if(res < 0 && i < 9 && a[i+1] >= 0) {
            printf("%d\n", res);
        }
    }
}