// Arvin Baghal Asl
// 403105793

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int eshterak = a & b;
    int count_a=0, count_b=0, count_eshterak=0;

    for (int i=0; i<32; i++) {
        if ((a & (1 << i)) == (1 << i)) {
            count_a++;
        }
        if ((b & (1 << i)) == (1 << i)) {
            count_b++;
        }
        if ((eshterak & (1 << i)) == (1 << i)) {
            count_eshterak++;
        }
    }

    int res = count_a + count_b - 2*count_eshterak;

    int ans[3];
    scanf("%d %d %d", &ans[0], &ans[1], &ans[2]);

    for (int i=0; i<3; i++) {
        if (ans[i] < res) {
            printf("NO\n");
        }
        else if ((ans[i] - res)%2 == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    
    return 0;
}