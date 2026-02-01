// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#define start int main()

unsigned long long int euclids_algorithm(unsigned long long int a, unsigned long long int b) {
    if(a%b == 0) {
        return b;
    }
    else {
        unsigned long long int temp = b;
        b = a%b;
        a = temp;
        euclids_algorithm(a,b);
    }
}

start { 
    unsigned long long int a, b;
    scanf("%llu %llu", &a, &b);
    if (a < b) {
        unsigned long long int temp = a;
        a = b;
        b = temp;
    }

    printf("%llu", euclids_algorithm(a,b));

    return 0;
}