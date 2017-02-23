#include <stdio.h>
int main(void) {
    int w = 3;
    int h = 10;
    int i,j;
    for(i = 0; i < w; i++)
    {
        printf("*");
    }
    printf("\n");
    for(i = 0; i < h - 2; i++) {
        printf("*");
        for(j=0;j<w - 2;j++){
            printf("X");
        }
        printf("*\n");
    }
    for(i=0;i<w;i++){
        printf("*");
    }
    return 0;
}