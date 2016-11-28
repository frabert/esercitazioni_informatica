#include <stdio.h>

int main(void) {
    int s, m, h;
    scanf("%d", &s);
    h = s / 3600;
    s = s - (h * 3600);
    m = s / 60;
    s = s - (m * 60);
    printf("%d h %d min %d s", h, m, s);
    return 0;
}