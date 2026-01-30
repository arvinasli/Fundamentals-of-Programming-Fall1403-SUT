// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, d;
    scanf("%f %f %f %f", &a, &b, &c, &d);


    float delta = 4*pow(b,2) - 12*a*c;

    if (delta > 0) {
        float ans1 = ((-2*b) - sqrt(delta)) / (6*a);
        float ans2 = ((-2*b) + sqrt(delta)) / (6*a);    
        if (ans1 < ans2) {
            printf("%.2f, %.2f", ans1, ans2);
        }
        else {
            printf("%.2f, %.2f", ans2, ans1);
        }
    }
    else {
        printf("No Local Extrema Points");
    }

    return 0;
}