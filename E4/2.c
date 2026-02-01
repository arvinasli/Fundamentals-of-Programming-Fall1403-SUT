// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

int matrix[2][2] = {{0,1},{2,3}};

int element_generator(int n, int i, int j) {
    if(n==1) {
        return matrix[i][j];
    }
    if(i<pow(2,(n-1)) && j<pow(2,(n-1))) {
        return element_generator(n-1,i,j);
    }
    else if(i<pow(2,(n-1)) && j>=pow(2,(n-1))) {
        int half = pow(2,(n-1));
        j = (half-1) - (j%half);
        return (element_generator(n-1,i,j)+1);
    }
    else if(i>=pow(2,(n-1)) && j<pow(2,(n-1))) {
        int half = pow(2,(n-1));
        i = (half-1) - (i%half);
        return (element_generator(n-1,i,j)-1);
    }
    else if(i>=pow(2,(n-1)) && j>=pow(2,(n-1))) {
        int half = pow(2,(n-1));
        i = (half-1) - (i%half);
        j = (half-1) - (j%half);
        return element_generator(n-1,i,j);
    }
}



int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    int i,j;
    for(int k=0; k<m; k++) {
        scanf("%d %d", &i, &j);
        printf("%d ", element_generator(n,i,j));
    }

    return 0;
}