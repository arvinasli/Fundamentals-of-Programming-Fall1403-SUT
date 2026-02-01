// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <stdlib.h>

void tensor_allocator(void** cell, int index, int dim, int dim_size[]) {
    for(int i=0; i<dim_size[index]; i++) {
        if(index==dim-1) {
            int num;
            scanf("%d", &num);
            *(int*) (cell+i) = num;
        }
        else {
            *(cell+i) = malloc(dim_size[index+1]*sizeof(void *));
            tensor_allocator(*(cell+i), index+1, dim, dim_size);
        }
    }
}

void tensor_printer(void **matrix, int index, int dim, int dim_size[], int *arr) {
    if(index == dim) {
        return;
    }
    for(int i=0; i<dim_size[index]; i++) {
        arr[index] +=1;
        if(index==dim-1) {
            void **target = matrix;
            printf("(");
            for(int k=0; k<dim; k++) {
                if(k!=dim-1) {
                    target = *(target+(arr[k]-1));
                }
                if(k==0) {
                    printf("%d",arr[k]);
                }
                else {
                    printf(",%d",arr[k]);
                }
            }
            printf("): %d\n", *(target+(arr[dim-1]-1)));
        }
        tensor_printer(matrix, index+1, dim, dim_size, arr);
    }
    arr[index]=0;
}

void linear_operation(void **matrix1, void **matrix2, int index, int dim, int dim_size[], int *arr, int target, int a, int b) {
    if(index == dim) {
        return;
    }
    for(int i=0; i<dim_size[index]; i++) {
        arr[index] +=1;
        if(index==dim-1) {
            void **target1 = matrix1;
            void **target2 = matrix2;
            for(int k=0; k<dim-1; k++) {
                target1 = *(target1+(arr[k]-1));
                target2 = *(target2+(arr[k]-1));
            }
            if(target == 1) {
                *(int *)(target1+(arr[dim-1]-1)) = ((((a%100) * *(int *)(target1+(arr[dim-1]-1)))%100) + (((b%100) * *(int *)(target2+(arr[dim-1]-1)))%100))%100;
            }
            else {
                *(int *)(target2+(arr[dim-1]-1)) = ((((a%100) * *(int *)(target1+(arr[dim-1]-1)))%100) + (((b%100) * *(int *)(target2+(arr[dim-1]-1)))%100))%100;
            }
        }
        linear_operation(matrix1, matrix2, index+1, dim, dim_size, arr, target, a, b);
    }
    arr[index]=0;
}

void reshape(void** cell, int index, int dim, int dim_size[]) {
    if(index==dim-1) {
        return;
    }
    for(int i=0; i<dim_size[index]; i++) {
        *(cell+i) = malloc(dim_size[index+1]*sizeof(void *));
        reshape(*(cell+i), index+1, dim, dim_size);
    }
}

void tensor_assign(void **new_matrix, void **matrix, int index, int new_dim, int new_dim_size[], int dim, int dim_size[], int *arr, int linear_size) {
    if(index == new_dim) {
        return;
    }
    for(int i=0; i<new_dim_size[index]; i++) {
        arr[index] +=1;
        if(index==new_dim-1) {
            void **new_target = new_matrix;
            int order = 0;
            int copy_linear_size = linear_size;
            for(int k=0; k<new_dim-1; k++) {
                new_target = *(new_target+(arr[k]-1));
                copy_linear_size/=new_dim_size[k];
                order += (arr[k]-1)*copy_linear_size;
            }
            order += (arr[new_dim-1]-1);

            void **target = matrix;
            copy_linear_size = linear_size;
            for(int k=0; k<dim-1; k++) {
                copy_linear_size/=dim_size[k];
                target = *(target+(order/copy_linear_size));
                order = order%copy_linear_size;
            }

            *(int *)(new_target+(arr[new_dim-1]-1)) = *(int *)(target+order);
        }
        tensor_assign(new_matrix, matrix, index+1, new_dim, new_dim_size, dim, dim_size, arr, linear_size);
    }
    arr[index]=0;
}

int main() {
    int dim;
    scanf("%d", &dim);

    int *dim_size = (int *) malloc(20*sizeof(int));
    int linear_size = 1;
    for(int i=0; i<dim; i++) {
        scanf("%d", &dim_size[i]);
        linear_size *= dim_size[i];
    }

    void **matrix1 = (void **) malloc(10000*sizeof(void *));
    void **matrix2 = (void **) malloc(10000*sizeof(void *));
    tensor_allocator(matrix1, 0, dim, dim_size);
    tensor_allocator(matrix2, 0, dim, dim_size);
    
    int *arr = (int *) calloc(20,sizeof(int));
    int n;
    scanf ("%d", &n);
    char operator;

    int new_dim = dim;
    int *new_dim_size = (int *) malloc(20*sizeof(int));
    for(int i=0; i<new_dim; i++) {
       new_dim_size[i] = dim_size[i];
    }
    int count_transpose = 0;

    for(int i=0; i<n; i++) {
        scanf(" %c", &operator);
        if(operator == 'L') {
            int target,a,b;
            scanf("%d %d %d", &target, &a, &b);
            linear_operation(matrix1, matrix2, 0, dim, dim_size, arr, target, a, b);
        }
        else if(operator == 'T') {
            if(new_dim != 1) {
                count_transpose++;
            }
        }
        else if(operator == 'R') {
            count_transpose = 0;

            scanf("%d", &new_dim);
            for(int k=0; k<new_dim; k++) {
                scanf("%d", (new_dim_size+k));
            }
        }
    }

    if(count_transpose%2 == 1) {
        int temp = *new_dim_size;
        *new_dim_size = *(new_dim_size+1); 
        *(new_dim_size+1) = temp;
    }

    void **new_matrix1 = (void **) malloc(10000*sizeof(void *));
    void **new_matrix2 = (void **) malloc(10000*sizeof(void *));
    reshape(new_matrix1, 0, new_dim, new_dim_size);
    reshape(new_matrix2, 0, new_dim, new_dim_size);
    tensor_assign(new_matrix1, matrix1, 0, new_dim, new_dim_size, dim, dim_size, arr, linear_size);
    tensor_assign(new_matrix2, matrix2, 0, new_dim, new_dim_size, dim, dim_size, arr, linear_size);

    printf("Matrix 1:\n");
    tensor_printer(new_matrix1, 0, new_dim, new_dim_size, arr);
    printf("Matrix 2:\n");
    tensor_printer(new_matrix2, 0, new_dim, new_dim_size, arr);
    return 0;
}