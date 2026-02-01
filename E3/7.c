// Arvin Baghal Asl
// 403105793

#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int m,n;
    scanf("%d %d", &m, &n);

    int board[MAX_SIZE][MAX_SIZE];
    int check_table[MAX_SIZE][MAX_SIZE];
    int copy_check_table[MAX_SIZE][MAX_SIZE];
    int count_boats = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &board[i][j]);
            check_table[i][j] = 0; copy_check_table[i][j] = 0;
            if (board[i][j] == 1) {
                count_boats++;
            }
        }
    }

    int k;
    scanf("%d", &k);
    int used = 0;
    int boats = count_boats;

    int coordinates[100000][2];
    for(int i=0; ((used!=k) && (boats!=0)); i++) {
        scanf("%d %d", &coordinates[i][0], &coordinates[i][1]);
        if ((coordinates[i][0] < m) & (coordinates[i][1] < n)) {
            if (check_table[coordinates[i][0]][coordinates[i][1]] == 0) {
                check_table[coordinates[i][0]][coordinates[i][1]] = 1;
                if (board[coordinates[i][0]][coordinates[i][1]] == 1) {
                    used++;
                    boats--;
                }
                else if (board[coordinates[i][0]][coordinates[i][1]] == 0) {
                    used++;
                }
            }
        }
    }


    used = 0;
    boats = count_boats;
    for (int i=0; ((used!=k) && (boats!=0)); i++) {
        if ((coordinates[i][0] >= m) || (coordinates[i][1] >= n)) {
            printf("Out Of Board, %d of %d bombs have been used.\n", used, k);
        }
        else {
            if (copy_check_table[coordinates[i][0]][coordinates[i][1]] == 0) {
                copy_check_table[coordinates[i][0]][coordinates[i][1]] = 1;
                if (board[coordinates[i][0]][coordinates[i][1]] == 1) {
                    used++;
                    boats--;
                    printf("Hit, %d of %d bombs have been used.\n", used, k);
                }
                else if (board[coordinates[i][0]][coordinates[i][1]] == 0) {
                    used++;
                    printf("Sea, %d of %d bombs have been used.\n", used, k);
                }
            }
            else {
                printf("Wrong Place, %d of %d bombs have been used.\n", used, k);
            }
        }
    }

    if (boats == 0) {
        printf("You Won!");
    }
    else {
        printf("You Lost!, %d of %d boats still remaining.", boats, count_boats);
    }

    return 0;
}