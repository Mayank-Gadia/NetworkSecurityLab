#include <ctype.h>
#include <string.h>
#include <stdio.h>

void encryption(char text[], int key);
void decryption(char text[], int key);

int main() {
    int key;
    int choice;
    char text[500];
    
    printf("Enter the msg: ");
    // scanf("%s" , text);
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    
    printf("Enter the key: ");
    scanf("%d", &key);
    
    printf("Enter the choice: 1.Encryption  2.Decryption\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            encryption(text, key);
            break;
        
        case 2:
            decryption(text, key);
            break;
                
        default:
            printf("Invalid selection\n");
    }

    return 0;
}

void encryption(char text[], int key) {
    for(int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        
        if(isupper(ch)) {
            ch = (ch - 'A' + key) % 26 + 'A';
        } else if(islower(ch)) {
            ch = (ch - 'a' + key) % 26 + 'a';
        } else if(isdigit(ch)) {
            ch = (ch - '0' + key) % 10 + '0';
        }
        
        text[i] = ch;
    }
    
    printf("Encrypted msg is: %s\n", text);
}

void decryption(char text[], int key) {
    for(int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        
        if(isupper(ch)) {
            ch = (ch - 'A' - key + 26) % 26 + 'A';
        } else if(islower(ch)) {
            ch = (ch - 'a' - key + 26) % 26 + 'a';
        } else if(isdigit(ch)) {
            ch = (ch - '0' - key + 10) % 10 + '0';
        }
        
        text[i] = ch;
    }
    
    printf("Decrypted msg is: %s\n", text);
}
