#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a[4][3];
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    int col = -1;
    
    for(int i = 0; i < 3; i++) {
        int valid = 1;
        for(int j = 0; j < 4; j++) {
            if(a[j][i] % 3 != 0) {
                valid = 0;
            }
        }
        if(valid) col = i;
    }
    
    printf("%d", col);
    
    return 0;
}