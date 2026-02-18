// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1500
#define MAX_WORD 100
#define MAX_WORD_LENGTH 30
#define MAX_CATEGORIES 10
#define MAX_KEYWORDS 50

double str_to_double(char token[]) {
    double result = 0;
    double jozesahih = 0;
    double aashar = 0;
    int index = 0;
    while(index < strlen(token) && token[index] != '.') {
        jozesahih = jozesahih*10+(token[index]-48);
        index++;
    }
    index++;
    double aashar_divisor = 1;
    while(index < strlen(token)) {
        aashar = aashar*10+(token[index]-48);
        aashar_divisor *= 10;
        index++;
    }
    aashar /= aashar_divisor;
    result = jozesahih+aashar;
    return result;
}

int check_upper(char ch) {
    if(65 <= ch && ch <= 90) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *categories_file = fopen(argv[1], "r");
    char categories[MAX_CATEGORIES][MAX_WORD_LENGTH] = {0};
    char keywords[MAX_CATEGORIES][MAX_KEYWORDS][MAX_WORD_LENGTH] = {0};
    double coofficients[MAX_CATEGORIES][MAX_KEYWORDS] = {0};
    int count_categories = 0;
    int count_keywords[MAX_CATEGORIES] = {0};

    char line[MAX_LINE];
    
    while(fscanf(categories_file, "%s", line) == 1) {
        char *token = strtok(line, ":");
        if(token == NULL) {
            break;
        }
        strcpy(categories[count_categories], token);

        count_keywords[count_categories] = 0;
        while(1) {
            token = strtok(NULL, ":");
            if(token == NULL) {
                break;
            }
            strcpy(keywords[count_categories][count_keywords[count_categories]], token);
            token = strtok(NULL, ":");
            coofficients[count_categories][count_keywords[count_categories]] = str_to_double(token);
            count_keywords[count_categories]++;
        }
        count_categories++;
    }
    

    double sum[MAX_CATEGORIES] = {0};

    for (int k = 2; k < argc; k++) {
        for(int i=0; i<MAX_CATEGORIES; i++) {
            sum[i] = 0;
        }
        FILE *text = fopen(argv[k], "r");

        while(fgets(line, MAX_LINE, text) != NULL) {
            char *token = strtok(line, " \t\n.,;!?\"'()[]{}:-");
            while(token != NULL) {
                for(int i=0; i<strlen(token); i++) {
                    if(check_upper(token[i])) {
                        token[i] += 32;
                    }
                }
                for(int i=0; i<count_categories; i++) {
                    for(int j=0; j<count_keywords[i]; j++) {
                        if(strcmp(token, keywords[i][j]) == 0) {
                            sum[i] += coofficients[i][j];
                            break;
                        }
                    }
                }
                token = strtok(NULL, " \t\n.,;!?\"'()[]{}:-");
            }
        }
        
        

        int ans_index = 0;
        char ans[MAX_WORD_LENGTH];
        for(int i=1; i<count_categories; i++) {
            if(sum[ans_index] < sum[i]) {
                ans_index = i;
            }
        }
        strcpy(ans, categories[ans_index]);
        for(int i=0; i<count_categories; i++) {
            if(i != ans_index && sum[ans_index] == sum[i]) {
                strcpy(ans, "Unknown");
                break;
            }
        }
        printf("%s\n", ans);
        fclose(text);
    }


    fclose(categories_file);

    return 0;
}



