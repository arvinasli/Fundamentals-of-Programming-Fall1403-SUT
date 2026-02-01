// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 5000

int check_UPPER (char c) {
    if ('A'<=c && c<='Z') {
        return 1;
    }
    return 0;
}

int check_digit (char c) {
    if ('0'<=c && c<='9') {
        return 1;
    }
    return 0;
}

int check_vowel (char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }
    return 0;
}

int check_punctuation (char c) {
    if ((33<=c && c<=47) || (58<=c && c<=64) || (91<=c && c<=96) || (123<=c && c<=126)) {
        return 1;
    }
    return 0;
}

int check_lower (char c) {
    if ('a'<=c && c<='z') {
        return 1;
    }
    return 0;
}

int check_letters(char c) {
    if (c == 'h' || c == 'o' || c == 'm' || c == 'e' || c == 'l' || c == 'a' || c == 'n' || c == 'd' || c == 'r' || c == 's'
     || c == 't' || c == 'i' || c == 'g') {
        return 1;
    }
    return 0;
}

int homelander_starlight(int len, char arr[]) {
    for(int index=0; index<len; index++) {
        if(check_letters(arr[index])) {
            int sum = 0;
            int start = index, end = index;
            int bool = 0;
            while(1) {
                if(check_letters(arr[end]) && end<len) {
                    if((end-start) == 21) {
                        bool = 1;
                        break;
                    }
                    end++;
                }
                else {
                    break;
                }
            }
            if(bool) {
                for(int i=start; i<=end; i++) {
                    sum += arr[i]-96;
                }
                if(sum == 228) {
                    return 1;
                }
                else {
                    index=start;
                }
            }
            else {
                index=end;
            }
        }
    }
    return 0;
}

int main() {
    int score = 0;
    char password[MAX_SIZE];

    int bool_UPPER = 0; int bool_digit = 0; int bool_vowel = 0; int bool_punc = 0;    

    int l = 0;
    long long int sum = 0;
    while(1) {
        scanf("%c", &password[l]);

        if (check_UPPER(password[l]) && bool_UPPER==0) {
            bool_UPPER = 1;
        }
        if (check_digit(password[l]) && bool_digit==0) {
            bool_digit = 1;
        }
        if (check_vowel(password[l]) && bool_vowel==0) {
            bool_vowel= 1;
        }
        if (check_punctuation(password[l]) && bool_punc==0) {
            bool_punc = 1;
        }

        if (password[l] == ' ') {
            break;
        }

        l++;
    }

    score = bool_UPPER + bool_digit + bool_vowel + bool_punc + homelander_starlight(l,password);

    for(int index=0; index<l; index++) {
        if(check_digit(password[index])) {
            int start = index, end = index;
            while(1) {
                if(check_digit(password[end]) && end<l) {
                    end++;
                }
                else {
                    break;
                }
            }
            int size = end-start;
            if(password[start-1] == '-') {
                for(int i=size; i>0; i--) {
                    sum -= pow(10,i-1)*(password[start+size-i]-48);
                }
            }
            else {
                for(int i=size; i>0; i--) {
                    sum += pow(10,i-1)*(password[start+size-i]-48);
                }
            }
            index = end;
        }
    }
    
    
    if(l >= 10) {
        score++;
    }
    if(sum == 10) {
        score++;
    }

    printf("%d", score);

    return 0;
}