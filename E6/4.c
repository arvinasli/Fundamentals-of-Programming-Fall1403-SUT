// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char m[200000];
    getchar();
    fgets(m, 200000, stdin);
    m[strcspn(m,"\n")] = '\0';
    int bool = 1;

    int arr[200000] = {0};
    int index = 0;
    for(int i=0; i<strlen(m); i++) {
        int len = 0;
        int copy_i = i;
        while(1) {
            if(m[copy_i] == ' ' || copy_i == strlen(m)) {
                break;
            }
            else if(m[copy_i]==92 && m[copy_i+1]=='n') {
                copy_i++;
                break;
            }
            copy_i++;
            len++;
        }
        if(len>n) {
            printf("can not be aligned");
            bool = 0;
            break;
        }
        i = copy_i;
    }

    if(bool) {
        for(int i=0; i<strlen(m); i++) {
            int len = 0;
            int copy_i = i;
            while(1) {
                if(copy_i == strlen(m)) {
                    if(len!=0) {
                        arr[index] = len;
                        index++;
                    }
                    break;
                }
                else if(m[copy_i] == ' ') {
                    if(len==0) {
                        arr[index] = 1;
                        index++;
                    }
                    else {
                        arr[index] = len;
                        arr[index+1] = 1;
                        index+=2;
                    }
                    break;
                }
                else if(m[copy_i]==92 && m[copy_i+1]=='n') {
                    if(len==0) {
                        arr[index] = 0;
                        index++;
                    }
                    else {
                        arr[index] = len;
                        arr[index+1] = 0;
                        index+=2;
                    }
                    copy_i++;
                    break;
                }
                copy_i++;
                len++;
            }

            i = copy_i;
        }

        int total_sum = 0;
        int sum = 0;
        for(int i=0; i<index; i++) {
            sum += arr[i];

            if(arr[i]==0) {
                if(sum==n) {
                    printf("\n");
                }
                total_sum+=2;
                sum = 0;
                printf("\n");
            }
            if(sum > n) {
                printf("\n");
                sum = 0;
                i--;
            }
            else {
                for(int j=0; j<arr[i]; j++) {
                    printf("%c", m[total_sum+j]);
                }
                total_sum+=arr[i];
            }
        }
    }

    
    return 0;
}