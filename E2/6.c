// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

int main() {
    const double PI = 3.14159265358979323846;

    int n;
    scanf("%d", &n);

    if (n == 1) {
        double a;
        scanf("%lf", &a);
        printf("Perimeter: %.2lf\n", 4*a);
        printf("Area: %.2lf", a*a);
    }

    else if (n == 2) {
        double a,b;
        scanf("%lf %lf", &a, &b);
        printf("Perimeter: %.2lf\n", 2*(a+b));
        printf("Area: %.2lf", a*b);
    }

    else if (n == 3) {
        double r;
        scanf("%lf", &r);
        printf("Perimeter: %.2lf\n", 2*PI*r);
        printf("Area: %.2lf", PI*r*r);
    }

    else if (n == 4) {
        double a,b,c;
        scanf("%lf %lf %lf", &a, &b, &c);
        printf("Perimeter: %.2lf\n", a+b+c);
        double P = (a+b+c)/2;
        double S = sqrt(P*(P-a)*(P-b)*(P-c));
        printf("Area: %.2lf\n", S);

        if ((a >= b) && (a >= c)) {
            if (a*a == (b*b + c*c)) {
                printf("Type: Right");
            }
            else if (a*a > b*b + c*c) {
                printf("Type: Obtuse");
            }
            else {
                printf("Type: Acute");
            }
        }
        else if ((b >= a) && (b >= c)) {
            if (b*b == (a*a + c*c)) {
                printf("Type: Right");
            }
            else if (b*b > a*a + c*c) {
                printf("Type: Obtuse");
            }
            else {
                printf("Type: Acute");
            }
        }
        else if ((c >= a) && (c >= b)) {
            if (c*c == (a*a + b*b)) {
                printf("Type: Right");
            }
            else if (c*c > a*a + b*b) {
                printf("Type: Obtuse");
            }
            else {
                printf("Type: Acute");
            }
        }
    }

    return 0;
}