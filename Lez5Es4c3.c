#include <stdio.h>

int max(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int min(int a, int b) {
    if(a < b) {
        return a;
    } else {
        return b;
    }
}

int MCD(int n, int m) {
    int tmp = 1;
    for(int i = 1; i < max(n, m); i++) {
        if(n % i == 0 && m % i == 0 && i > tmp) {
            tmp = i;
        }
    }
    return tmp;
}

int mcm(int n, int m) {
    return (n * m)/MCD(n, m);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n%d", MCD(n, m), mcm(n, m));
    return 0;
}