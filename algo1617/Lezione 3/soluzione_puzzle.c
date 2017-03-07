#include <stdio.h>
#include <stdlib.h>

/*
 * Soluzione ottimale in tempo O(n) e spazio O(1)
 * Sfrutto la somma di Gauss per vedere se manca un elemento dall'array
 */
int check(int* a, int n) {
  int somma = 0;
  int gauss = ((n + 1) * (n + 2)) / 2;
  int mancante;
  int i;
  for(i = 0; i < n; i++) {
    somma += a[i];
  }
  mancante = gauss - somma;
  return mancante;
}

int main(void) {
  int n, *a;
  int i;
  scanf("%d", &n);
  a = malloc(sizeof(int) * n);
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  printf("%d\n", check(a, n));
  return 0;
}
