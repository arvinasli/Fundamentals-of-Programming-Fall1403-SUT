// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *c = (char *) malloc(1000*sizeof(char));
    int sum_int = 0;
    long long int sum_long = 0;
    float sum_float = 0;

    int *int_ptr;
    long long int *long_ptr;
    float *float_ptr;
    
    for(int i=0; ;i++) {
        scanf("%c",c+i);
        if(*(c+i)=='!') {
            scanf("%c",c+i+1); scanf("%c",c+i+2);
            break;
        }

        //load int
        if(*(c+i)==49) {
            char *str = (char *) malloc(4*sizeof(char));
            scanf("%4s",str);
            int_ptr = (int *) str;
            sum_int = *int_ptr;
            free(str);
        }
        //add int
        if(*(c+i)==65) {
            char *str = (char *) malloc(4*sizeof(char));
            scanf("%4s",str);
            int_ptr = (int *) str;
            sum_int += *int_ptr;
            free(str);
        }
        //print int
        if(*(c+i)==81) {
            printf("%d\n",sum_int);
        }

        //load long
        if(*(c+i)==50) {
            char *str = (char *) malloc(8*sizeof(char));
            scanf("%8s",str);
            long_ptr = (long long int *) str;
            sum_long = *long_ptr;
            free(str);
        }
        //add long
        if(*(c+i)==66) {
            char *str = (char *) malloc(8*sizeof(char));
            scanf("%8s",str);
            long_ptr = (long long int *) str;
            sum_long += *long_ptr;
            free(str);
        }
        //print long
        if(*(c+i)==82) {
            printf("%lld\n",sum_long);
        }

        //load float
        if(*(c+i)==52) {
            char *str = (char *) malloc(4*sizeof(char));
            scanf("%4s",str);
            float_ptr = (float *) str;
            sum_float = *float_ptr;
            free(str);
        }
        //add float
        if(*(c+i)==68) {
            char *str = (char *) malloc(4*sizeof(char));
            scanf("%4s",str);
            float_ptr = (float *) str;
            sum_float += *float_ptr;
            free(str);
        }
        //print float
        if(*(c+i)==84) {
            printf("%.3f\n",sum_float);
        }
        i++;
    }

    free(c);
    return 0;
}