// Arvin Baghal Asl
// 403105793

#include <stdio.h>

#define MAX_SIZE 10000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX_SIZE];

    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }


    char command;
    int start, end;
    do {
        scanf("\n");
        scanf("%c %d %d", &command, &start, &end);
        if (command == 'r') {
            int temp[MAX_SIZE];
            for (int i=(end-2), j=0; i >= (start-1); i--, j++) {
                temp[j] = arr[i];
            }
            for (int i=(start-1), j=0; i < (end-1); i++, j++) {
                arr[i] = temp[j];
            }
        }
        else if (command == 's') {
            for (int i=(start-1); i < (end-1); i++) {
                for (int j=i+1; j < (end-1); j++) {
                    if (arr[i] > arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
        else if (command == 'd') {
            for (int i=(start-1); i < (end-1); i++) {
                arr[i] *= 2;
            }
        }
    } while (command != 'e');

    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}