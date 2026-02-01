// Arvin Baghal Asl
// 403105793

#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    int table[MAX_SIZE][MAX_SIZE];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &table[i][j]);
        }
    }

    int q;
    scanf("%d", &q);
    int x1, y1, x2, y2;
    for (int k=0; k<q; k++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int check_list[10000] = {0};
        int ans = 0;
        for (int i=x1-1; i<x2; i++) {
            for (int j=y1-1; j<y2; j++) {
                if(check_list[table[i][j]-1] == 0) {
                    check_list[table[i][j]-1] = 1;
                    ans++;
                }
            }
        }

        printf("%d ", ans);
    }

    return 0;
}