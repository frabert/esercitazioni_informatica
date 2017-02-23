#include <stdio.h>

void multipli(int n, int m) {
    for(int i = 1; i <= n; i++) {
        if(i % m == 0) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    multipli(n, m);
    return 0;
}