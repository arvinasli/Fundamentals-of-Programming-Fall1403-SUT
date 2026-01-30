// Arvin Baghal Asl
// 403105793

#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    if (((a >= b) && (b >= c)) || ((c >= b) && (b >= a))) {
        b = b + a;
        a = b - a;
        b = b - a;
    }
    else if (((a >= c) && (c >= b)) || ((b >= c) && (c >= a))) {
        c = c + a;
        a = c - a;
        c = c - a;
    }

    printf("%d", a);

    return 0;
}