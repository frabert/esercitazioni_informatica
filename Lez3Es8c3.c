#include <stdio.h>
int main(void) {
    float a, b, res;
    int fa, fb;
    char c;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf(" %c", &c);
    fa = (int)a;
    fb = (int)b;
    if(c == '+') {
        res = a+b;
    } else if(c== '-') {
        res = a-b;
    } else if(c=='*') {
        res = a*b;
    } else if(c=='/') {
        res = a/b;
    } else if(c == '%') {
        res = fa%fb;
    }
    printf("%.1f",res);
    return 0;
}