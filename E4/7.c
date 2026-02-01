// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

int ans[18];
int ans_l = 0;
int boolean = 0;

int size_of(long long int num) {
    if(num==0) {
        return 1;
    }
    int size = 0;
    while (num > 0) {
        num /= 10;
        size++;
    }
    return size;
}

void back_tracking(long long int num, int size, int m, int arr[]) {
    if(size==0) {
        boolean=1;
        return;
    }
    for (int i=0; i<m; i++) {
        int divisor = pow(10,size_of(arr[i]));
        if ((num-arr[i])%divisor == 0) {
            num -= arr[i];
            num /= divisor;
            size -= size_of(arr[i]);
            ans[ans_l] = i;
            ans_l++;
            back_tracking(num,size,m,arr);
            if(boolean==1) {
                break;
            }
            else {
                ans_l--;
                size += size_of(arr[i]);
                num *= divisor;
                num += arr[i];
            }
        }
    }
}

int main() {
    long long int n; int m;
    int keys[1000];

    scanf("%lld %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &keys[i]);
    }

    back_tracking(n,size_of(n),m,keys);

    if(!boolean) {
        printf("%d", -1);
    }
    else {
        for(int i=ans_l-1; i>=0; i--) {
            printf("%d ",ans[i]);
        }
    }

    return 0;
}