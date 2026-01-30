// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    int count_n = n - (n >> 1) - (n >> 2) - (n >> 3) - (n >> 4) - (n >> 5) - (n >> 6) - (n >> 7);
    int count_m = m - (m >> 1) - (m >> 2) - (m >> 3) - (m >> 4) - (m >> 5) - (m >> 6) - (m >> 7);
    int ans = n + pow(-1,count_n+count_m)*m;
    printf("%d", ans);
    return 0;
}