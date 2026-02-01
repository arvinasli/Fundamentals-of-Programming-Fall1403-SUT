// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <stdlib.h>

char* find_array(void* data, int* password) {
    int i = 0; int len = 0;
    char *ans = (char *) calloc(1000,sizeof(char));
    int *binary_str = (int *) calloc(8000,sizeof(int));
    unsigned char *num = (unsigned char *) (data);

    while (*(password+i) != 0) {
        if(*(password+i) > 0) {
            int index = *(password+i)-1;

            if ((*(num+(index/8)) & (1 << (7 - index%8))) == (1 << (7 - index%8))) {
                *(binary_str+len) = 1;
            }
            else {
                *(binary_str+len) = 0;
            }
            len++;
        }
        else if(*(password+i) < 0) {
            int index = -*(password+i)-1;

            for(int j=7; j>=0; j--) {
                if ((*(num+index) & (1 << j)) == (1 << j)) {
                    *(binary_str+len) = 1;
                }
                else {
                    *(binary_str+len) = 0;
                }
                len++;
            }
        }
        i++;
    }

    int ans_index = 0;
    int k=0;
    while(len > 0) {
        for(int j=7; j>=0; j--, len--) {
            if(len == 0) {
                break;
            }
            *(ans+ans_index) += *(binary_str+k) * (1 << j);
            k++;
        }
        ans_index++;
    }
    *(ans+ans_index+1) = '\0';
    return ans;
}