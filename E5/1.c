// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int **triangle = (int **) malloc(n*sizeof(int *));
    for(int i=0; i<n; i++) {
        *(triangle+i) = (int *) malloc((i+1)*sizeof(int));
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            scanf("%d", (*(triangle+i)+j));
        }
    }

    char character;
    while(1) {
        scanf(" %c",&character);
        if(character == '#') {
            break;
        }

        else if(character == 'a') {
            int number; scanf("%d", &number);
            int *a = (int *) malloc(number*sizeof(int));
            for(int i=0; i<number; i++) {
                scanf("%d",a+i);
            }
            int *b = (int *) malloc((n-number+1)*sizeof(int));
            for(int i=0; i<(n-number+1); i++) {
                scanf("%d",b+i);
            }
            if(number>n+1 || number<1) {
                printf("Invalid row number\n");
                continue;
            }
            n++;
            triangle = (int **) realloc(triangle,n*sizeof(int *));
            *(triangle+n-1) = (int *) malloc(n*sizeof(int));
            for(int i=n-1; i>=number; i--) {
                for(int j=0; j<=i; j++) {
                    *(*(triangle+i)+j) = *(*(triangle+i-1)+j);
                }
                *(*(triangle+i)+i) = *(b+i-number);
            }
            for(int j=0; j<number; j++) {
                *(*(triangle+number-1)+j) = *(a+j);
            }
            free(a); free(b);
        }

        else if(character == 'd') {
            int number; scanf("%d", &number);
            if(number>n || number<1) {
                printf("Invalid row number\n");
                continue;
            }
            n--;
            for(int i=number-1; i<n; i++) {
                for(int j=0; j<=i; j++) {
                    *(*(triangle+i)+j) = *(*(triangle+i+1)+j);
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            printf("%d ", *(*(triangle+i)+j));
        }
        printf("\n");
    }

    for(int i=0; i<n; i++) {
        free(*(triangle+i));
    }
    free(triangle);

    return 0;
}