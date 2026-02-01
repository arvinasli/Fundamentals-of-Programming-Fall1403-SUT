// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX_SIZE];

    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i=0; i<n; i++) {
        int num = arr[i];
        int digits = 0;
        while (num >= 1) {
            digits++;
            num /= 10;
        }

        num = arr[i];
        int sum = 0;
        while (num >= 1) {
            sum += pow(num%10,digits);
            num /= 10;
        }

        if (arr[i] == sum) {
            printf("%d is Armstrong\n", arr[i]);
        }
        else {
            printf("%d is Not Armstrong\n", arr[i]);
        }
    }

    return 0;
}