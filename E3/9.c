// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 1000

int main() {
    long long int n, q, p, m;
    scanf("%lld %lld %lld %lld", &n, &q, &p, &m);

    long long int Locks[26];
    for (int i=0; i<26; i++) {
        scanf("%lld", &Locks[i]);
    }

    char S[MAX_SIZE];
    for (int i=0; i<n; i++) {
        scanf(" %c", &S[i]);
    }
    
    long long int l, r, hash;
    for (int i=0; i<q; i++) {
        long long int sum = 0;
        scanf("%lld %lld %lld", &l, &r, &hash);

        long long int power = 1;
        if (l <= r) {
            for (int j=l-1; j<r; j++) {
                sum += (((Locks[S[j]-97]%m)*power)%m);
                power *= p;
                power = power%m;
                if (sum >= m) {
                    sum = sum%m;
                }
            }
        }
        else {
            for (int j=l-1; j>=r-1; j--) {
                sum += (((Locks[S[j]-97]%m)*power)%m);
                power *= p;
                power = power%m;
                if (sum >= m) {
                    sum = sum%m;
                }
            }
        }

        if (sum == hash) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}