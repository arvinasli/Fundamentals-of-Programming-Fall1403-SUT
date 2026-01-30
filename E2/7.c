// Arvin Baghal Asl
// 403105793

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if ((999<n) && (n<10000)) {
        int A = n/1000;
        int B = n/100 - 10*A;
        int C = n%100;
        if (A+B == C) {
            printf("%d+%d=%d", A, B, C);
        }
        else {
            printf("No Equation Found");
        }
    }

    else if ((9999<n) && (n<100000)) {
        int A = n/10000;
        int B = n/100 - 100*A;
        int C = n%100;
        if (A+B == C) {
            printf("%d+%d=%d", A, B, C);
        }
        else {
            A = n/1000;
            B = n/100 - 10*A;
            C = n%100;
            if (A+B == C) {
                printf("%d+%d=%d", A, B, C);
            }
            else {
                printf("No Equation Found");
            }
        }
    }

    else if ((99999<n) && (n<1000000)) {
        int A = n/10000;
        int B = n/100 - 100*A;
        int C = n%100;
        if (A+B == C) {
            printf("%d+%d=%d", A, B, C);
        }
        else {
            A = n/100000;
            B = n/1000 - 100*A;
            C = n%1000;
            if (A+B == C) {
                printf("%d+%d=%d", A, B, C);
            }
            else {
                A = n/10000;
                B = n/1000 - 10*A;
                C = n%1000;
                if (A+B == C) {
                    printf("%d+%d=%d", A, B, C);
                }
                else {
                    printf("No Equation Found");
                }
            }
        }
    }

    return 0;
}