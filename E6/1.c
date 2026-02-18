// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <string.h>

int char_to_int (char ch) {
    switch (ch) {
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 1;
    }
}

int compare (char ch1, char ch2) {
    if(ch1 == 'M') {
        return 1;
    }
    else if(ch1 == 'D' && ch2 != 'M') {
        return 1;
    }
    else if(ch1 == 'C' && ch2 != 'M' && ch2 != 'D') {
        return 1;
    }
    else if(ch1 == 'L' && ch2 != 'M' && ch2 != 'D' && ch2 != 'C') {
        return 1;
    }
    else if(ch1 == 'X' && ch2 != 'M' && ch2 != 'D' && ch2 != 'C' && ch2 != 'L') {
        return 1;
    }
    else if(ch1 == 'V' && ch2 != 'M' && ch2 != 'D' && ch2 != 'C' && ch2 != 'L' && ch2 != 'X') {
        return 1;
    }

    return 0;
}

int roman_to_int (char roman[]) {
    int sum = 0;
    
    for (int i=0; i<strlen(roman); i++) {
        int temp_sum = 0;

        temp_sum += char_to_int(roman[i]);
        while (i!=strlen(roman) && roman[i]==roman[i+1]) {
            i++;
            temp_sum += char_to_int(roman[i]);
        }

        if(i==strlen(roman)-1 || i==strlen(roman) || compare(roman[i],roman[i+1])) {
            sum += temp_sum;
        }
        else {
            sum -= temp_sum;
        }
    }

    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    char rn1[50]; char rn2[50];
    char operation[10];

    for(int i=0; i<n; i++) {
        scanf("%s", rn1);
        scanf("%s", operation);

        if (strcmp(operation,"plus") == 0) {
            scanf("%s", rn2);
            printf("%d\n", roman_to_int(rn1)+roman_to_int(rn2));
        }
        else if (strcmp(operation,"minus") == 0) {
            scanf("%s", rn2);
            printf("%d\n", roman_to_int(rn1)-roman_to_int(rn2));
        }
        else if (strcmp(operation,"times") == 0) {
            scanf("%s", rn2);
            printf("%d\n", roman_to_int(rn1)*roman_to_int(rn2));
        }
        else if (strcmp(operation,"divided") == 0) {
            scanf("%s", operation);
            scanf("%s", rn2);
            printf("%d\n", roman_to_int(rn1)/roman_to_int(rn2));
        }
        else if (strcmp(operation,"mod") == 0) {
            scanf("%s", rn2);
            printf("%d\n", roman_to_int(rn1)%roman_to_int(rn2));
        }
    }
    
    return 0;
}