// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

int main() {
    int x1,y1,r1;
    int x2,y2,r2;
    scanf("%d %d %d", &x1, &y1, &r1);
    scanf("%d %d %d", &x2, &y2, &r2);

    float distance = sqrt(pow(x2-x1,2) + pow(y2-y1,2));

    int abs;
    if (r1 > r2) {
        abs = r1 - r2;
    }
    else {
        abs = r2 - r1;
    }



    if (distance == r1+r2 || distance == abs) {
        printf("%d", 1);
    }
    else if ((distance < r1+r2) && (distance > abs)) {
        printf("%d", 2);
    }
    else {
        printf("%d", 0);
    }

    return 0;
}