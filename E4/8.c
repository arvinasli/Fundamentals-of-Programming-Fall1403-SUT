// Arvin Baghal Asl
// 403105793

#include <stdio.h>

int table[20][20] = {0};
int g_rows[20][6];
int g_columns[20][6];
int found = 0;

int column_checker(int column_index, int guide_columns[], int n, int stop) {
    int less = 0;
    int index = 1;

    for(int i=0; i<=stop; i++) {
        if(table[i][column_index]==1) {
            int count = 0;
            while(table[i][column_index]==1) {
                count++;
                i++;
            }
            if(count < guide_columns[index]) {
                less++;
                if(less==2) {
                    return 0;
                }
            }
            else if(count == guide_columns[index]) {
                index++;
            }
            else {
                return 0;
            }
        }
    }

    return 1;
}

int row_checker(int row[], int guide_rows[], int m, int stop) {
    int less = 0;
    int index = 1;

    for(int i=0; i<=stop; i++) {
        if(row[i]==1) {
            int count = 0;
            while(row[i]==1) {
                count++;
                i++;
            }
            if(count < guide_rows[index]) {
                less++;
                if(less==2) {
                    return 0;
                }
            }
            else if(count == guide_rows[index]) {
                index++;
            }
            else {
                return 0;
            }
        }
    }

    return 1;
}

int final_row_checker(int row[], int guide_rows[], int m) {
    int correct_sum = 0;
    int sum = 0;
    int index = 1;

    for(int i=1; i<=guide_rows[0]; i++) {
        correct_sum+=guide_rows[i];
    }
    for(int i=0; i<m; i++) {
        sum+=row[i];
    }
    if(sum != correct_sum) {
        return 0;
    }

    for(int i=0; i<m; i++) {
        if(row[i]==1) {
            int count = 0;
            while(row[i]==1) {
                count++;
                i++;
            }
            if(count == guide_rows[index]) {
                index++;
            }
            else {
                return 0;
            }
        }
    }
    return 1;
}

int final_column_checker(int column_index, int guide_columns[], int n) {
    int correct_sum = 0;
    int sum = 0;
    int index = 1;

    for(int i=1; i<=guide_columns[0]; i++) {
        correct_sum+=guide_columns[i];
    }
    for(int i=0; i<n; i++) {
        sum+=table[i][column_index];
    }
    if(sum != correct_sum) {
        return 0;
    }

    for(int i=0; i<n; i++) {
        if(table[i][column_index]==1) {
            int count = 0;
            while(table[i][column_index]==1) {
                count++;
                i++;
            }
            if(count == guide_columns[index]) {
                index++;
            }
            else {
                return 0;
            }
        }
    }
    return 1;
}

void recursive_element_generator(int i, int j, int guide_row[], int guide_column[], int n, int m) {
    if(i==n) {
        for(int j=0; j<m; j++) {
            if(!final_column_checker(j,g_columns[j],n)) {
                return;
            }
        }
        found = 1; return;
    }

    if (j==m-1) {
        table[i][j]=1;
        if(final_row_checker(table[i],g_rows[i],m) && column_checker(j,g_columns[j],n,i)) {
            recursive_element_generator(i+1,0,g_rows[i+1],g_columns[0],n,m);
            if(found) {
                return;
            }
        }
        else {
            table[i][j]=0;
        }
    }
    else {
        table[i][j]=1;
        if(row_checker(table[i],g_rows[i],m,j) && column_checker(j,g_columns[j],n,i)) {
            recursive_element_generator(i,j+1,g_rows[i],g_columns[j+1],n,m);
            if(found) {
                return;
            }
        }
        else {
            table[i][j]=0;
        }
    }

    if (j==m-1) {
        table[i][j]=0;
        if(final_row_checker(table[i],g_rows[i],m) && column_checker(j,g_columns[j],n,i)) {
            recursive_element_generator(i+1,0,g_rows[i+1],g_columns[0],n,m);
            if(found) {
                return;
            }
        }
        else {
            table[i][j]=0;
        }
    }
    else {
        table[i][j]=0;
        if(row_checker(table[i],g_rows[i],m,j) && column_checker(j,g_columns[j],n,i)) {
            recursive_element_generator(i,j+1,g_rows[i],g_columns[j+1],n,m);
            if(found) {
                return;
            }
        }
        else {
            table[i][j]=0;
        }
    }
    
    
}

int main() {
    int n; int m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++) {
        scanf("%d", &g_rows[i][0]);
        for(int j=1; j<=g_rows[i][0]; j++) {
            scanf("%d", &g_rows[i][j]);
        }
    }
    for(int i=0; i<m; i++) {
        scanf("%d", &g_columns[i][0]);
        for(int j=1; j<=g_columns[i][0]; j++) {
            scanf("%d", &g_columns[i][j]);
        }
    }

    recursive_element_generator(0,0,g_rows[0],g_rows[0],n,m);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(table[i][j]==1) {
                printf("%s","EE");
            }
            else {
                printf("%s","  ");
            }
        }
        printf("\n");
    }

    return 0;
}