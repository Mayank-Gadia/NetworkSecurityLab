#include<stdio.h>
#include<string.h> 
#include<ctype.h> 

// Define the encryption function here
void encrypt(char *plaintext, const char *key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            plaintext[i] = key[plaintext[i] - base];
        }
    }
}

// Function to decryption function here
void decrypt(char *ciphertext, const char *key) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            const char *pos = strchr(key, ciphertext[i]);
            
            if (pos != NULL) {
                ciphertext[i] = base + (pos - key);
            }
        }
    }
}


int main() {
    char plaintext[200];
    char key[27];
    char ciphertext[200];
    char decrypted[200];

    // Input plaintext from user
    printf("Enter the plaintext here:  ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    // Input key from user
    printf("Enter the key for reference: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove trailing newline if present

    // Call the encryption function
    strcpy(ciphertext, plaintext);
    encrypt(ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);

    // Call the decryption function 
    strcpy(decrypted, ciphertext);
    decrypt(decrypted, key);
    printf("Decrypted plaintext: %s\n", decrypted);

    return 0;
}

