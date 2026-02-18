// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int a;
    int b;
} imaginary;

int str_to_num(char *str) {
    int num = 0;
    if(*str == '-') {
        for(int i=1; i<strlen(str); i++) {
            num = num*10 + (str[i] -'0');
        }
        return -num;
    }
    for(int i=0; i<strlen(str); i++) {
        num = num*10 + (str[i] -'0');
    }
    return num;
}

void print_imaginary(imaginary number) {
    printf("(%d, %d)\n", number.a, number.b);
}

int check_quadrant(int l, imaginary number) {
    if(l ==1 && number.a>0 && number.b>0) { return 1; }
    else if(l ==2 && number.a<0 && number.b>0) { return 1; }
    else if(l ==3 && number.a<0 && number.b<0) { return 1; }
    else if(l ==4 && number.a>0 && number.b<0) { return 1; }
    return 0;
}

int main() {
    int n,t,q;
    scanf("%d %d %d", &n, &t, &q);
    
    int *ex = (int *) calloc(2000,sizeof(int)); int count = 0;
    imaginary *arr = (imaginary *) malloc(2000*sizeof(imaginary));
    
    int index; int a; int b;
    
    for(int i=0; i<t; i++) {
        scanf("%d %d %d", &index, &a, &b);
        arr[index-1].a = a;
        arr[index-1].b = b;
        ex[index-1] = 1;
        count++;
    }
    
    getchar();
    char command[100];
    for(int i=0; i<q; i++) {
        fgets(command, 100, stdin);
        command[strcspn(command,"\n")] = 0;
        char *token = strtok(command," ");
        if(strcmp(token,"delete") == 0) {
            token = strtok(NULL," ");
            index = str_to_num(token);
            if(ex[index-1] == 1) {
                count--;
                ex[index-1] = 0;
                print_imaginary(arr[index-1]);
            }
            else {
                printf("no number in %d!\n", index);
            }
        }

        else if(strcmp(token,"add") == 0) {
            token = strtok(NULL," ");
            index = str_to_num(token);
            token = strtok(NULL," "); a = str_to_num(token); token = strtok(NULL," "); b = str_to_num(token);
            if(ex[index-1] == 0) {
                count++;
                ex[index-1] = 1;
                arr[index-1].a = a; arr[index-1].b = b;
                printf("added successfully!\n");
            }
            else {
                printf("number currently exists in %d!\n", index);
            }
        }

        else if(strcmp(token,"number") == 0) {
            printf("%d\n",count);
        }

        else if(strcmp(token,"operation") == 0) {
            token = strtok(NULL," "); int l = str_to_num(token); token = strtok(NULL," "); char operation = token[0]; token = strtok(NULL," "); int m = str_to_num(token);
            token = strtok(NULL," "); token = strtok(NULL," "); index = str_to_num(token);
            if(ex[l-1] == 0 || ex[m-1] == 0 || ex[index-1] == 1) {
                if(ex[l-1] == 0 || ex[m-1] == 0) { printf("not enough operands!\n"); }
                else if(ex[index-1] == 1) { printf("destination currently full!\n"); }
            }
            else {
                count++;
                ex[index-1] = 1;
                switch (operation) {
                case '+':
                    arr[index-1].a = arr[l-1].a + arr[m-1].a; arr[index-1].b = arr[l-1].b + arr[m-1].b;
                    break;
                case '-':
                    arr[index-1].a = arr[l-1].a - arr[m-1].a; arr[index-1].b = arr[l-1].b - arr[m-1].b;
                    break;
                case '*':
                    arr[index-1].a = arr[l-1].a*arr[m-1].a - arr[l-1].b*arr[m-1].b; arr[index-1].b = arr[l-1].a*arr[m-1].b + arr[l-1].b*arr[m-1].a;
                    break;
                }
                print_imaginary(arr[index-1]);
            }
        }

        else if(strcmp(token,"count") == 0) {
            int ans = 0;
            token = strtok(NULL," "); token = strtok(NULL," "); int l = str_to_num(token);
            for(int j=0; j<n; j++) {
                if(ex[j] && check_quadrant(l,arr[j])) {
                    ans++;
                }
            }
            printf("%d\n",ans);
        }

        else if(strcmp(token,"quadrant") == 0) {
            token = strtok(NULL," "); token = strtok(NULL," "); index = str_to_num(token);
            if(ex[index-1] == 1) {
                if(arr[index-1].a>0 && arr[index-1].b>0) { printf("1\n"); }
                else if(arr[index-1].a<0 && arr[index-1].b>0) { printf("2\n"); }
                else if(arr[index-1].a<0 && arr[index-1].b<0) { printf("3\n"); }
                else if(arr[index-1].a>0 && arr[index-1].b<0) { printf("4\n"); }
                else { printf("in no quadrant!\n"); }
            }
            else {
                printf("no number in %d!\n", index);
            }
        }

        else if(strcmp(token,"conjugate") == 0) {
            token = strtok(NULL," "); index = str_to_num(token);
            if(ex[index-1] == 1) {
                arr[index-1].b *= (-1);
                print_imaginary(arr[index-1]);
            }
            else {
                printf("no number in %d!\n", index);
            }
        }

        else if(strcmp(token,"rotate") == 0) {
            token = strtok(NULL," "); index = str_to_num(token); token = strtok(NULL," ");
            if(ex[index-1] == 1) {
                int temp = arr[index-1].a;
                if(strcmp(token,"clockwise") == 0) {
                    arr[index-1].a = arr[index-1].b;
                    arr[index-1].b = (-1) * temp;
                }
                else {
                    arr[index-1].a = (-1) * arr[index-1].b;
                    arr[index-1].b = temp;
                }
                print_imaginary(arr[index-1]);
            }
            else {
                printf("no number in %d!\n", index);
            }
        }
       
    }
    
    
    return 0;
}