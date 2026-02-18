// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <string.h>
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
    int number = 0;

    for (int i=0; i<strlen(operation); i++) {
        if (check_digit(operation[i])) {
            while (check_digit(operation[i])) {
                number = number * 10 + (operation[i] - '0');
                i++;
            }
            break;
        }
    }

    if (strstr(operation, "-")) {
        number = (-1)*number;
    }

    if (*pointer + number >= size || *pointer + number < 0) {
        printf("Not enough characters.\n");
    }
    else {
        *pointer += number;
    }
}

void shift(char operation[], int *pointer, int size, char *string) {
    int number = 0;
    int amount = 0;
    int number_index;  int number_len = 0;

    for (int i=0; i<strlen(operation); i++) {
        if (check_digit(operation[i])) {
            number_index = i;
            while (check_digit(operation[i])) {
                number = number * 10 + (operation[i] - '0');
                number_len++;
                i++;
            }
            break;
        }
    }

    for (int i=number_index + number_len; i<strlen(operation); i++) {
        if (check_digit(operation[i])) {
            while (check_digit(operation[i])) {
                amount = amount * 10 + (operation[i] - '0');
                i++;
            }
            break;
        }
    }
    if(strstr(operation,"-")) {
        amount = (-1)*amount;
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
    int number = 0;

    for (int i=0; i<strlen(operation); i++) {
        if (check_digit(operation[i])) {
            while (check_digit(operation[i])) {
                number = number * 10 + (operation[i] - '0');
                i++;
            }
            break;
        }
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
    int number = 0;

    for (int i=0; i<strlen(operation); i++) {
        if (check_digit(operation[i])) {
            while (check_digit(operation[i])) {
                number = number * 10 + (operation[i] - '0');
                i++;
            }
            break;
        }
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

void replace(char operation[], int *size, char *string) {
    char *word1 = strtok(operation, " ");
    word1 = strtok(NULL, " ");
    char *word2 = strtok(NULL, " ");

    int len1 = strlen(word1);
    int len2 = strlen(word2);

    for (int i=0; i<=*size-len1; i++) {
        if (strncmp(&string[i], word1, len1) == 0) {
            memmove(&string[i+len2], &string[i+len1], *size-(i+len1));
            memcpy(&string[i], word2, len2);
            *size += (len2-len1);
            i += len2 - 1;
        }
    }

    string[*size] = '\0';
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
    char operation[100];
    fgets(string, 20000, stdin);
    string[strcspn(string,"\n")] = 0;

    int pointer = 0;
    int size = strlen(string);

    do
    {
        fgets(operation, 100, stdin);
        operation[strcspn(operation,"\n")] = 0;

        if(strstr(operation,"replace")) {
            replace(operation, &size, string);
            pointer = 0;
        }
        else if(strstr(operation,"count")) {
            printf("%d\n",count(operation, size, string));
        }
        else if(strstr(operation,"move")) {
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

        else if(strstr(operation,"translate")) {
            if(strstr(operation,"Hindi")) {
                translate_Hindi(size, string);
            }
            else if(strstr(operation,"French")) {
                translate_French(size, string);
            }
        }

    } while (!strstr(operation,"&&"));
    
    printf("%s\n",string);
    
    return 0;
}