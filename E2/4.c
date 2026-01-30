// Arvin Baghal Asl
// 403105793

#include <stdio.h>

int main() {
    int base_x, base_y, base_o, x, y;
    scanf("%d %d %d", &base_x, &base_y, &base_o);

    if (base_x == 16) {
        scanf("%x", &x);
    }
    else if (base_x == 8) {
        scanf("%o", &x);
    }
    else if (base_x == 10) {
        scanf("%d", &x);
    }

    if (base_y == 16) {
        scanf("%x", &y);
    }
    else if (base_y == 8) {
        scanf("%o", &y);
    }
    else if (base_y == 10) {
        scanf("%d", &y);
    }

    int sum = x + y;
    if (base_o == 16) {
        printf("%x", sum);
    }
    else if (base_o == 8) {
        printf("%o", sum);
    }
    else if (base_o == 10) {
        printf("%d", sum);
    }

    return 0;
}