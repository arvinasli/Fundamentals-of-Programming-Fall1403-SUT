// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <string.h>

int check_digit(char ch) {
    if (48<=ch && ch<=57) {
        return 1;
    }
    return 0;
}

int main() {
    char string[100000];
    char regex[100000];
    fgets(string, 100000, stdin);
    fgets(regex, 100000, stdin);
    string[strcspn(string,"\n")] = 0;
    regex[strcspn(regex,"\n")] = 0;

    int bool = 1;

    int i = 1;
    int index = 0;
    char ch;
    char operator;

    while (i<strlen(regex)-1 && index<strlen(string)) {
        if (regex[i] == '\\') {
            if (regex[i+1] == 'd') {
                ch = '0';
                i += 2;
            }
            else if (regex[i+1] == '\\') {
                ch = '\\';
                i += 2;
            }
            else if (regex[i+1] == '+') {
                ch = '+';
                i += 2;
            }
            else if (regex[i+1] == '*') {
                ch = '*';
                i += 2;
            }
            else if (regex[i+1] == '?') {
                ch = '?';
                i += 2;
            }
            else if (regex[i+1] == '^') {
                ch = '^';
                i += 2;
            }
            else if (regex[i+1] == '$') {
                ch = '$';
                i += 2;
            }
        }
        else {
            ch = regex[i];
            i++;
        }

        if(regex[i] == '+') {
            i++;
            if(ch == '0') {
                if(!check_digit(string[index])) {
                    bool = 0;
                    break;
                }
                else {
                    while (check_digit(string[index])) {
                        index++;
                    }
                }
            }
            else {
                if(string[index] != ch) {
                    bool = 0;
                    break;
                }
                else {
                    while (string[index] == ch) {
                        index++;
                    }
                }
            }
        }
        else if(regex[i] == '*') {
            i++;
            if(ch == '0') {
                while (check_digit(string[index])) {
                    index++;
                }
            }
            else {
                while (string[index] == ch) {
                    index++;
                }
            }
        }
        else if(regex[i] == '?') {
            i++;
            if(ch == '0') {
                if(check_digit(string[index])) {
                    index++;
                }
            }
            else {
                if(string[index] == ch) {
                    index++;
                }
            }
        }
        else {
            if(ch == '0') {
                if(!check_digit(string[index])) {
                    bool = 0;
                    break;
                }
            }
            else {
                if(string[index] != ch) {
                    bool = 0;
                    break;
                }
            }
            index++;
        }
    }

    if (i!=strlen(regex)-1 || index!=strlen(string)) {
        bool = 0;
    }

    if(bool) {
        printf("Yes");
    }
    else {
        printf("No");
    }

    return 0;
}