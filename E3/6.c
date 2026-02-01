// Arvin Baghal Asl
// 403105793

#include <stdio.h>

#define MAX_SIZE 100000

int main() {
    int n;
    scanf("%d", &n);

    long long int arr[MAX_SIZE];

    for (int i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
    }

    int boolean_variable = 0;
    long long int sum = 0;
    for (int i=n-1; i>1; i--) {
        if (arr[i-2] > arr[i] - arr[i-1]) {
            boolean_variable = 1;
            sum = arr[i]+arr[i-1]+arr[i-2];
            printf("%lld", sum);
            break;
        }
    }

    if (!boolean_variable) {
        printf("%d", -1);
    }
    
    return 0;
}