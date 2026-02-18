// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <string.h>
#include <math.h>

char board[50][50];

void initial_set (int n, int m) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            board[i][j] = '.';
        }
    }
}

int str_to_num (char *str) {
    int num = 0;
    int p = strlen(str)-1;
    for(p; p>=0; p--) {
        num += ((str[strlen(str)-p-1]-'0')*pow(10,p));
    }
    
    return num;
}

char piece (char *token, int is_black) {
    char ch = '.';

    if (strcmp(token,"king") == 0) {
        ch = 'k' - is_black*32;
    }
    else if (strcmp(token,"queen") == 0) {
        ch = 'q' - is_black*32;
    }
    else if (strcmp(token,"rook") == 0) {
        ch = 'r' - is_black*32;
    }
    else if (strcmp(token,"bishop") == 0) {
        ch = 'b' - is_black*32;
    }
    else if (strcmp(token,"knight") == 0) {
        ch = 'n' - is_black*32;
    }
    else if (strcmp(token,"pawn") == 0) {
        ch = 'p' - is_black*32;
    }
    else if (strcmp(token,"cannon") == 0) {
        ch = 'c' - is_black*32;
    }
    else if (strcmp(token,"chariot") == 0) {
        ch = 'h' - is_black*32;
    }
    else if (strcmp(token,"sorcerer") == 0) {
        ch = 's' - is_black*32;
    }
    else if (strcmp(token,"dragon") == 0) {
        ch = 'd' - is_black*32;
    }
    else if (strcmp(token,"ninja") == 0) {
        ch = 'i' - is_black*32;
    }
    else if (strcmp(token,"warrior") == 0) {
        ch = 'w' - is_black*32;
    }
    else if (strcmp(token,"mage") == 0) {
        ch = 'm' - is_black*32;
    }
    else if (strcmp(token,"golem") == 0) {
        ch = 'g' - is_black*32;
    }

    return ch;
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    initial_set(n,m);

    char command[100];

    int i;
    scanf("%d", &i);
    getchar();
    for(int j=0; j<i; j++) {
        fgets(command, 100, stdin);
        int is_black = 0;
        int column; int row;
        char ch; int bool = 0;

        char *token = strtok(command, " ");
        while (token != NULL) {
            if (strcmp(token,"black") == 0) {
                is_black = 1;
                token = strtok(NULL, " ");
                ch = piece(token, is_black);
            }
            else if(strcmp(token,"white") == 0) {
                token = strtok(NULL, " ");
                ch = piece(token, is_black);
            }

            if (strcmp(token,"column") == 0) {
                token = strtok(NULL, " ");
                column = str_to_num(token);
            }
            else if (strcmp(token,"row") == 0) {
                token = strtok(NULL, " ");
                token[strlen(token)-1] = '\0';
                row = str_to_num(token);
                for (int k=0; k<n; k++) {
                    for (int l=0; l<m; l++) {
                        if (board[k][l] == ch) {
                            board[k][l] = '.';
                            bool = 1;
                            break;
                        }
                    }
                    if(bool) {
                        break;
                    }
                }
                board[row-1][column-1] = ch;
            }
            
            token = strtok(NULL, " ");
        }
    }

    int p;
    scanf("%d", &p);
    getchar();
    for(int j=0; j<p; j++) {
        fgets(command, 100, stdin);
        int is_black = 0;
        int column; int row;
        char ch; int bool = 0;

        char *token = strtok(command, " ");
        while (token != NULL) {
            if (strcmp(token,"black") == 0) {
                is_black = 1;
                token = strtok(NULL, " ");
                ch = piece(token, is_black);
            }
            else if(strcmp(token,"white") == 0) {
                token = strtok(NULL, " ");
                ch = piece(token, is_black);
            }

            if (strcmp(token,"column") == 0) {
                token = strtok(NULL, " ");
                column = str_to_num(token);
            }
            else if (strcmp(token,"row") == 0) {
                token = strtok(NULL, " ");
                token[strlen(token)-1] = '\0';
                row = str_to_num(token);

                for (int k=0; k<n; k++) {
                    for (int l=0; l<m; l++) {
                        if (board[k][l] == ch) {
                            board[k][l] = '.';
                            bool = 1;
                            break;
                        }
                    }
                    if(bool) {
                        break;
                    }
                }
                if(bool) {
                    board[row-1][column-1] = ch;
                }
            }
            
            token = strtok(NULL, " ");
        }
    }

    for(int j=0; j<n; j++) {
        for(int k=0; k<m; k++) {
            printf("%c ", board[j][k]);
        }
        printf("\n");
    }

    return 0;
}