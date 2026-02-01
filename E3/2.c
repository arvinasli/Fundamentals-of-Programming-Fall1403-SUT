// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10000

int main() {
    int n;
    scanf("%d", &n);

    long long int num;
    int arr[MAX_SIZE];
    int yekan[MAX_SIZE];

    for (int i=0; i<n; i++) {
        scanf("%lld", &num);
        yekan[i] = num%10;
        arr[i] = num/10;
    }

    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=2; j<=10; j++) {
            sum += (arr[i]%10) * j;
            arr[i] /= 10;
        }

        if ((sum%11) < 2) {
            if (yekan[i] == (sum%11)) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
        else {
            if (yekan[i] == 11-(sum%11)) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
    }

    return 0;
}