// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char alphabet[52] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
char ALPHABET[52] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";

int check_digit(char ch) {
    if (48<=ch && ch<=57) {
        return 1;
    }
    return 0;
}

int check_lower(char ch) {
    if (97<=ch && ch<=122) {
        return 1;
    }
    return 0;
}

int check_upper(char ch) {
    if (65<=ch && ch<=90) {
        return 1;
    }
    return 0;
}

void move(char operation[], int *pointer, int size) {
    int len = 0; int index;
    int number = 0;
    for(int i=0; i<strlen(operation); i++) {
        if (check_digit(operation[i])) {
            index = i;
            while(check_digit(operation[i])) {
                len++;
                i++;
            }
            break;
        }
    }
    for(int j=index; j<index+len; j++) {
        number += (operation[j]-48)*pow(10,len-j+index-1);
    }
    if(strstr(operation,"-")) {
        number *= (-1);
    }

    if(*pointer+number>=size || *pointer+number<0) {
        printf("%s\n","Not enough characters.");
    }
    else {
        *pointer += number;
    }
}

void shift(char operation[], int *pointer, int size, char *string) {
    int number_len = 0; int shift_len = 0; int number_index; int shift_index;
    int number = 0;
    int amount = 0;
    for(int i=0; i<strlen(operation); i++) {
        if (check_digit(operation[i])) {
            number_index = i;
            while(check_digit(operation[i])) {
                number_len++;
                i++;
            }
            break;
        }
    }
    for(int j=number_index; j<number_index+number_len; j++) {
        number += (operation[j]-48)*pow(10,number_len-j+number_index-1);
    }
    for(int i=number_index+number_len; i<strlen(operation); i++) {
        if (check_digit(operation[i])) {
            shift_index = i;
            while(check_digit(operation[i])) {
                shift_len++;
                i++;
            }
            break;
        }
    }
    for(int k=shift_index; k<shift_index+shift_len; k++) {
       amount += (operation[k]-48)*pow(10,shift_len-k+shift_index-1);
    }
    if(strstr(operation,"-")) {
        amount *= (-1);
    }

    if(*pointer+number>=size || *pointer+number<0) {
        printf("%s\n","Not enough characters.");
    }
    else {
        if(amount>=0) {
            amount %= 26;
        }
        else {
            amount = 26 - ((-1)*(amount))%26;
        }
        for(int i=*pointer; i<*pointer+number; i++) {
            if(check_lower(*(string+i))) {
                for(int j=0; j<26; j++) {
                    if(alphabet[j]==*(string+i)) {
                        *(string+i) = alphabet[j+amount];
                        break;
                    }
                }
            }
            else if(check_upper(*(string+i))) {
                for(int j=0; j<26; j++) {
                    if(ALPHABET[j]==*(string+i)) {
                        *(string+i) = ALPHABET[j+amount];
                        break;
                    }
                }
            }
        }
        *pointer += number;
    }
}

void lower(char operation[], int *pointer, int size, char *string) {
    int len = 0; int index;
    int number = 0;
    for(int i=0; i<strlen(operation); i++) {
        if (check_digit(operation[i])) {
            index = i;
            while(check_digit(operation[i])) {
                len++;
                i++;
            }
            break;
        }
    }
    for(int j=index; j<index+len; j++) {
        number += (operation[j]-48)*pow(10,len-j+index-1);
    }

    if(*pointer+number>=size || *pointer+number<0) {
        printf("%s\n","Not enough characters.");
    }
    else {
        for(int i=*pointer; i<*pointer+number; i++) {
            if(check_upper(*(string+i))) {
                *(string+i) += 32;
            }
        }
        *pointer += number;
    }
}

void upper(char operation[], int *pointer, int size, char *string) {
    int len = 0; int index;
    int number = 0;
    for(int i=0; i<strlen(operation); i++) {
        if (check_digit(operation[i])) {
            index = i;
            while(check_digit(operation[i])) {
                len++;
                i++;
            }
            break;
        }
    }
    for(int j=index; j<index+len; j++) {
        number += (operation[j]-48)*pow(10,len-j+index-1);
    }

    if(*pointer+number>=size || *pointer+number<0) {
        printf("%s\n","Not enough characters.");
    }
    else {
        for(int i=*pointer; i<*pointer+number; i++) {
            if(check_lower(*(string+i))) {
                *(string+i) -= 32;
            }
        }
        *pointer += number;
    }
}

int count(char operation[], int size, char *string) {
    int c = 0;
    char *substring = strtok(operation, " ");
    substring = strtok(NULL, " ");
    int len = strlen(substring);

    for (int i=0; i<=size-len; i++) {
        if (strncmp(&string[i], substring, len) == 0) {
            c++;
            i += len-1;
        }
    }

    return c;
}

void replace(char operation[], int size, char *string) {
    char *word = strtok(operation, " ");
    word = strtok(NULL, " ");
    char *word_1 = (char *) malloc(100*sizeof(char));
    strcpy(word_1,word);
    int len1 = strlen(word_1);
    word = strtok(NULL, " ");
    char *word_2 = (char *) malloc(100*sizeof(char));
    strcpy(word_2,word);
    int len2 = strlen(word_2);

    for (int i=0; i<=size-len1; i++) {
        if (strncmp(&string[i], word_1, len1) == 0) {
            *(string+size+len2-len1) = 0;
            for (int j=size+len2-len1-1; j>=i+len2; j--) {
                *(string+j) = *(string+j-(len2-len1));
            }
            for (int k=i; k<i+len2; k++) {
                *(string+k) = *(word_2+k-i);
            }
            i+=len2-1;
            size+=len2-len1;
        }
    }
    free(word_1); free(word_2);
}

void translate_Hindi(int size, char *string) {
    for(int i=0; i<size; i++) {
        if(*(string+i)=='t') {
            *(string+i) = 'd';
        }
        else if(*(string+i)=='T') {
            *(string+i) = 'D';
        }
    }
}

void translate_French(int size, char *string) {
    for(int i=0; i<size; i++) {
        if(*(string+i)=='r') {
            *(string+i) = 'q';
        }
        else if(*(string+i)=='R') {
            *(string+i) = 'Q';
        }
    }
}


int main() {
    char *string = (char *) malloc(20000*sizeof(char));
    char operation[50];
    fgets(string, 20000, stdin);
    string[strcspn(string,"\n")] = 0;

    int pointer = 0;
    int size = strlen(string);

    do
    {
        fgets(operation, 50, stdin);
        operation[strcspn(operation,"\n")] = 0;

        if(strstr(operation,"move")) {
            move(operation, &pointer, size);
        }
        else if(strstr(operation,"position")) {
            printf("%d\n", pointer);
        }
        else if(strstr(operation,"shift")) {
            shift(operation, &pointer, size, string);
        }
        else if(strstr(operation,"upper")) {
            upper(operation, &pointer, size, string);
        }
        else if(strstr(operation,"lower")) {
            lower(operation, &pointer, size, string);
        }
        else if(strstr(operation,"count")) {
            printf("%d\n",count(operation, size, string));
        }
        else if(strstr(operation,"replace")) {
            replace(operation, size, string);
            pointer = 0;
            size = strlen(string);
        }
        else if(strstr(operation,"translate")) {
            if(strstr(operation,"Hindi")) {
                translate_Hindi(size, string);
            }
            else if(strstr(operation,"French")) {
                translate_French(size, string);
            }
        }

    } while (!strstr(operation,"&&"));
    
    printf("%s",string);
    
    return 0;
}