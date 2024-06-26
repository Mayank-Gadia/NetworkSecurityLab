#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// Function to encrypt or decrypt the input string based on the key
void encryption(char alph[], char key[], int encrypt) {
    int alen = strlen(alph);
    int klen = strlen(key);
    
    for (int i = 0, j = 0; i < alen; i++) {
        if (isalpha(alph[i])) {  // Process only alphabetic characters
            char base = islower(alph[i]) ? 'a' : 'A';
            int shift = tolower(key[j % klen]) - 'a';
            
            shift = encrypt ? shift : -shift;
            
            alph[i] = (char)(((alph[i] - base + shift) + 26) % 26 + base);
            j++;
        }
    }
}

int main() {
    char alph[200];
    char key[200];

    printf("Enter the plaintext: ");
    fgets(alph, sizeof(alph), stdin);
    alph[strcspn(alph, "\n")] = '\0';  // Remove newline character from input
    
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove newline character from input
    
    // Encrypt the plaintext
    encryption(alph, key, 1);
    printf("Encrypted: %s\n", alph);
    
    // Decrypt the ciphertext
    encryption(alph, key, 0);
    printf("Decrypted: %s\n", alph);

    return 0;
}
