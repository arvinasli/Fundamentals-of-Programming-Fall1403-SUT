// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int base, int n) {
    int result = 1;
    while(n > 0) {
        result *= base;
        n--;
    }
    return result;
}

void trim(char *str) {
    int length = strlen(str);
    for(int i=0; i<length; i++) {
        if(str[i] == ' ') {
            int shift_length = 0;
            int copy_i = i;
            while(copy_i<length && str[copy_i] == ' ') {
                copy_i++;
                shift_length++;
            }
            copy_i = i;
            for(copy_i; copy_i+shift_length<length; copy_i++) {
                str[copy_i] = str[copy_i+shift_length];
            }
            length -= shift_length;
        }
    }
    str[length] = 0;
}

int check_digit(char d) {
    if(48<=d && d<=57) {
        return 1;
    }
    return 0;
}

int calculate_result(char *str) {
    int result = 0;
    int *arr_nums = (int *) malloc(100000*sizeof(int));
    char *arr_operations = (char *) malloc(100000*sizeof(char));
    int num_index = 0;
    int operation_index = 0;
    for(int i=0; i<strlen(str); i++) {
        if(check_digit(str[i])) {
            int num = 0;
            int start_index = i;
            while(i<strlen(str) && check_digit(str[i])) {
                num *= 10;
                num += str[i]-48;
                i++;
            }
            if(start_index != 0 && str[start_index-1] == '-') {
                num *= -1;
            }
            arr_nums[num_index] = num;
            num_index++;
            i--;
        }
        else {
            if((str[i] == '-' && i == 0) || (str[i] == '-' && !check_digit(str[i-1]))) {
                continue;
            }
            else if(str[i] == '-' && check_digit(str[i-1])) {
                arr_operations[operation_index] = '+';
                operation_index++;
            }
            else {
                arr_operations[operation_index] = str[i];
                operation_index++;
            }
        }
    }
    arr_operations[operation_index] = '+';
    operation_index++;

    int temp_result = arr_nums[0];
    for(int i=0; i<operation_index; i++) {
        if(arr_operations[i] != '+') {
            temp_result = arr_nums[i];
            while(i<operation_index && arr_operations[i] != '+') {
                if(arr_operations[i] == '*') {
                    temp_result *= arr_nums[i+1];
                }
                else if(arr_operations[i] == '/') {
                    temp_result /= arr_nums[i+1];
                }
                i++;
            }
            i--;
        }
        else {
            result += temp_result;
            temp_result = arr_nums[i+1];
        }
    }
    return result;
}

int numlen(int num) {
    if(num == 0) {
        return 0;
    }
    int len = 0;
    while(num > 0) {
        len++;
        num /= 10;
    }
    return len;
}

void join(char *str, int result) {
    int length = strlen(str);
    str[length] = '=';
    if(result < 0) {
        result *= (-1);
        length++;
        str[length] = '-';
    }
    int result_length = numlen(result);
    do {
        length++;
        str[length] = 48 + result/power(10,result_length-1);
        result -= (str[length]-48)*power(10,result_length-1);
        result_length = numlen(result);
    } while (result_length > 0);
    
    str[length+1] = 0;
}

int main(int argc, char *argv[]) {
    FILE *inputFile;  
    inputFile = fopen("input.txt", "r");

    FILE *outputFile;
    outputFile = fopen("output.txt", "w");

    char *str = malloc(100000*sizeof(char));
    fgets(str, 100000, inputFile);
    str[strcspn(str, "\n")] = 0;

    trim(str);

    int length = strlen(str);

    int error = 0;
    for(int i=0; i<length-1; i++) {
        if(str[i] == '/' && str[i+1] == '0') {
            error = 1;
            break;
        }
    }

    if(error) {
        str[length] = '=';
        str[length+1] = 'E'; str[length+2] = 'r'; str[length+3] = 'r'; str[length+4] = 'o'; str[length+5] = 'r';
        str[length+6] = 0;
    }
    else {
        join(str, calculate_result(str));
    }
    
    length = strlen(str);
    fwrite(str, sizeof(char), length, outputFile);

    free(str);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}