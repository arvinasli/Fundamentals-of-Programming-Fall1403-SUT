// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *matrix = (int *) malloc(625*sizeof(int));

    for(int i=0; i<n*n; i++) {
        scanf("%d", (matrix+i));
    }

    int **print_area = (int **) malloc(1*sizeof(int *));
    *print_area = (int *) malloc(1*sizeof(int));
    **print_area = *matrix;

    for(int i=1; i<=n; i++) {
        for(int k=0; k<i; k++) {
            for(int l=0; l<i; l++) {
                printf("%d ",*(*(print_area+k)+l));
            }
            printf("\n");
        }
        printf("----\n");

        print_area = (int **) realloc(print_area,(i+1)*sizeof(int *));
        for(int j=0; j<i; j++) {
            *(print_area+j) = (int *) realloc(*(print_area+j),(i+1)*sizeof(int));
        }
        *(print_area+i) = (int *) malloc((i+1)*sizeof(int));

        for(int k=0; k<i; k++) {
            *(*(print_area+k)+i)=*(matrix+i*i+k);
        }
        for(int l=0; l<i+1; l++) {
            *(*(print_area+i)+l)=*(matrix+i*(i+1)+l);
        }
    }
    
    return 0;
}