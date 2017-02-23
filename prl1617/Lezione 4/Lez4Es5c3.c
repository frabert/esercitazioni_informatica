#include <stdio.h>

int fib(int n) {
    int tmp1, tmp2, i;
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        tmp1 = 0;
        tmp2 = 1;
        for (i = 1; i < n; i++) {
            int tmp3 = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = tmp3;
        }
        return tmp2;
    }
}

int main(void) {
  int n;
  int f = 0;
  int i = 0;
  scanf("%d", &n);
  do {
    printf("%d\n", f);
    f = fib(++i);
  } while(f <= n);
}
