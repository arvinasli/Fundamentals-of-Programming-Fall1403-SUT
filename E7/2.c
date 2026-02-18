// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct russianDoll {
    int id;
    int child_count;
    struct russianDoll **children;
} russianDoll;

russianDoll *create_russianDoll(int id) {
    russianDoll *new_russianDoll = (russianDoll *) malloc(sizeof(russianDoll));
    new_russianDoll->id = id;
    new_russianDoll->child_count = 0;
    new_russianDoll->children = NULL;
    return new_russianDoll;
}

void put(russianDoll *firstdoll, russianDoll *seconddoll) {
    if (firstdoll->child_count == 0) {
        firstdoll->children = (russianDoll **) malloc(sizeof(russianDoll *));
    }
    else {
        firstdoll->children = (russianDoll **) realloc(firstdoll->children, (firstdoll->child_count+1)*sizeof(russianDoll *));
    }
    firstdoll->children[firstdoll->child_count] = seconddoll;
    firstdoll->child_count += 1;
}

void count(int *c, russianDoll *doll) {
    if(doll->child_count == 0) {
        return;
    }
    for(int i=0; i<doll->child_count; i++) {
        *c += 1;
        count(c,doll->children[i]);
    }
}

void empty(russianDoll **arr, int index, int *main_count) {
    if(arr[index]->child_count == 0) {
        return;
    }
    for(int j=*main_count-index-1; j>0; j--) {
        arr[index+arr[index]->child_count+j] = arr[index+j];
    }
    int *sort = malloc(arr[index]->child_count*sizeof(int));
    for(int j=0; j<arr[index]->child_count; j++) {
        sort[j] =j;
    }

    for (int i=0; i<arr[index]->child_count-1; i++) {
        for (int j=i+1; j < arr[index]->child_count; j++) {
            if (arr[index]->children[sort[i]]->id > arr[index]->children[sort[j]]->id) {
                int temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }      
        }
    }

    for(int j=0; j<arr[index]->child_count; j++) {
        arr[index+j+1]=arr[index]->children[sort[j]];
    }
    free(sort);
    *main_count += arr[index]->child_count;
    arr[index]->child_count = 0;
    arr[index]->children = NULL;
}

void trim_arr(russianDoll **arr, int n) {
    for(int i=0; i<n; i++) {
        if(arr[i] == NULL) {
            int shift = 0;
            int copy_i = i;
            while(copy_i<n && arr[copy_i] == NULL) {
                copy_i++;
                shift++;
            }
            for(int j=i; j<n-shift; j++) {
                arr[j] = arr[j+shift];
            }
            i += shift;
            n -= shift; 
        }
    }
}

int main() {
    int n,q;
    scanf("%d %d", &n, &q);
    
    int main_count = n;
    russianDoll **arr = (russianDoll **) malloc(n*sizeof(russianDoll *));
    for(int i=0; i<n; i++) {
        arr[i] = create_russianDoll(i+1);
    }

    char query[100];
    for(int i=0; i<q; i++) {
        scanf("%s",query);
        if(strcmp(query,"put") == 0) {
            int k; int target; scanf("%d %d", &k, &target);
            int index;
            for(int j=0; j<k; j++) {
                scanf("%d", &index);
                put(arr[target-1],arr[index-1]);
                arr[index-1] = NULL;
                main_count -= 1;
            }
            trim_arr(arr, n);
        }
        else if(strcmp(query,"empty") == 0) {
            int index; scanf("%d",&index);
            empty(arr,index-1,&main_count);
        }
        else if(strcmp(query,"main_dolls_count") == 0) {
            printf("%d\n",main_count);
        }
        else if(strcmp(query,"count") == 0) {
            int index; scanf("%d",&index);
            int *c = malloc(sizeof(int)); *c = 0;
            count(c,arr[index-1]);
            printf("%d\n",(*c)+1);
            free(c);
        }
        else if(strcmp(query,"get_id") == 0) {
            int index; scanf("%d",&index);
            printf("%d\n",arr[index-1]->id);
        }
    }
    
    return 0;
}