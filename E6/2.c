// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hex_to_dec(char ch) {
    switch (ch) {
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'a':
        return 10;
    case 'b':
        return 11;
    case 'c':
        return 12;
    case 'd':
        return 13;
    case 'e':
        return 14;
    case 'f':
        return 15;
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    default:
        return 0;
    }
}

void trim(char *string) {
    int start = 0; 
    int end = strlen(string) - 1;

    while (string[start] == ' ') {
        start++;
    }

    while (end >= start && string[end] == ' ') {
        end--;
    }
    
    if (start > end) {
        string[0] = '\0';
        return;
    }

    int length = end - start + 1;
    for (int i = 0; i < length; i++) {
        string[i] = string[start + i];
    }

    string[length] = '\0';
}

int main() {
    char *command = (char *) malloc(200*sizeof(char));
    char *message = (char *) malloc(1000*sizeof(char));
    char *encrypted_message = (char *) malloc(2000*sizeof(char));

    while(1) {
        fgets(command, 200, stdin);
        command[strcspn(command,"\n")] = 0;
        char *token = strtok(command," ");
        if(strcmp(token,"exit")==0) {
            break;
        }

        else if(strcmp(token,"encrypt")==0) {
            token = strtok(NULL," ");
            token = strtok(NULL," ");
            fgets(message, 1000, stdin);
            message[strcspn(message,"\n")] = 0;
            trim(message);
            int index = 0;
            int sum = 0;
            while(index<strlen(message)) {
                for(int i=0; i<strlen(token); i++) {
                    sum += message[index];
                    sum %= 65536;
                    printf("%02x", message[index] ^ token[i]);
                    index++;
                    if(index==strlen(message)) {
                        break;
                    }
                }
            }
            printf("%02x",sum%256);
            printf("%02x\n",sum/256);
        }

        else if(strcmp(token,"decrypt")==0) {
            token = strtok(NULL," ");
            token = strtok(NULL," ");
            fgets(encrypted_message, 2000, stdin);
            encrypted_message[strcspn(encrypted_message,"\n")] = 0;
            trim(encrypted_message);
            int index = 0;
            int check_index = strlen(encrypted_message)-4;
            int sum = 0;
            int check_sum = 0;
            for(int i=0; i<check_index; i+=2) {
                message[index] = (hex_to_dec(encrypted_message[i])*16+hex_to_dec(encrypted_message[i+1])) ^ token[index%strlen(token)];
                sum += message[index];
                sum %= 65536;
                index++;
            }
            message[index] = 0;
            check_sum = (hex_to_dec(encrypted_message[check_index+2])*16+hex_to_dec(encrypted_message[check_index+3]))*256 + hex_to_dec(encrypted_message[check_index])*16+hex_to_dec(encrypted_message[check_index+1]); 
            if(sum != check_sum) {
                printf("Invalid key!\n");
            }
            else {
                printf("%s\n",message);
            }
        }
    }
    
    return 0;
}