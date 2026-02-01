// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

int size_of_num(long long int n) {
    int size = 0;
    while (n > 0) {
        size++;
        n /= 10;
    }
    return size;
}

long long int a_to_decimal(long long int n, int a) {
    long long int sum = 0;
    long long int copy_n = n;
    for(int i=0; i<size_of_num(n); i++) {
        sum += (copy_n%10)*pow(a,i);
        copy_n /= 10;
    }
    return sum;
}

long long int decimal_to_b(long long int decimal, int b) {
    long long int num = 0;
    int i = 0;
    while(decimal > 0) {
        num += (decimal%b)*pow(10,i);
        decimal /= b; i++;
    }
    return num;
}




int main() {
    long long int n;
    int a; int b;
    scanf("%lld %d", &n, &a);
    scanf("%d", &b);

    if(n == 0) {
        printf("%d", 6);
    }

    else {
        long long int res = decimal_to_b(a_to_decimal(n,a),b);
        int segments = 0;
        for(int i=size_of_num(res); i>0; i--) {
            switch (res%10) {
            case 0:
                segments += 6;
                break;
            case 1:
                segments += 2;
                break;
            case 2:
                segments += 5;
                break;
            case 3:
                segments += 5;
                break;
            case 4:
                segments += 4;
                break;
            case 5:
                segments += 5;
                break;
            case 6:
                segments += 6;
                break;
            case 7:
                segments += 3;
                break;
            case 8:
                segments += 7;
                break;
            case 9:
                segments += 6;
                break;
            }
            res /= 10;
        }
        
        printf("%d", segments);
    }

    return 0;
}