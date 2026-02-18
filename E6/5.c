// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int file_check(char str[]) {
    for(int i=0; i<strlen(str); i++) {
        if(str[i]=='.') {
            return 1;
        }
    }
    return 0;
}

void swap(char *str1, char *str2) {
    char temp[100];
    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);
}

char *all_lower(char *str) {
    char *low = (char *) malloc(100*sizeof(char));
    for(int i=0; i<strlen(str); i++) {
        if(*(str+i)<=90) {
            *(low+i) = *(str+i)+32;
        }
        else {
            *(low+i) = *(str+i);
        }
    }
    return low;
}

void sort(char **dir, int count_dir) {
    for(int i=0; i<count_dir-1; i++) {
        for(int j=i+1; j<count_dir; j++) {
            if(strcmp(all_lower(*(dir+i)),all_lower(*(dir+j)))>0) {
                swap(*(dir+i),*(dir+j));
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char address[2000];
    int count_dir = 0;
    char **dir = (char **) malloc(10000*sizeof(char *));
    for(int i=0; i<10000; i++) {
        *(dir+i) = (char *) malloc(100*sizeof(char));
    }

    for(int i=0; i<n; i++) {
        getchar();
        fgets(address, 2000, stdin);

        char *token = strtok(address, "/");
        while (token != NULL) {
            if(file_check(token)) {
                break;
            }
            int bool = 1;
            for(int j=0; j<count_dir; j++) {
                if(strcmp(token,dir[j]) == 0) {
                    bool = 0;
                    break;
                }
            }
            if(bool) {
                strcpy(*(dir+count_dir),token);
                count_dir++;
            }
            token = strtok(NULL, "/");
        }
    }

    sort(dir, count_dir);
    
    for(int i=0; i<count_dir; i++) {
        printf("%s\n",dir[i]);
    }


    return 0;
}