#include <stdio.h>
#include <string.h>

void encryption(const char pt[], const char ct[], char p[], char c[]);
void decryption(const char pt[], const char ct[], char c[], char d[]);

int main() {
    char pt[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char ct[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    char p[500] = {'\0'};
    char c[500] = {'\0'};
    char d[500] = {'\0'};
    
    printf("Enter the plain text: ");
    fgets(p, sizeof(p), stdin);
    p[strcspn(p, "\n")] = '\0';  // Remove the newline character

    // Converting plain text into cipher text (encryption)
    encryption(pt, ct, p, c);
    printf("Cipher text is: %s\n", c);

    // Converting cipher text into plain text (decryption)
    decryption(pt, ct, c, d);
    printf("Plain text is: %s\n", d);

    return 0;
}

void encryption(const char pt[], const char ct[], char p[], char c[]) {
    int len = strlen(p);
    for (int i = 0; i < len; i++) {
        if (p[i] >= 'A' && p[i] <= 'Z') {  // Only process uppercase letters
            for (int j = 0; j < 26; j++) {
                if (p[i] == pt[j]) {
                    c[i] = ct[j];
                    break;  // Exit the inner loop once a match is found
                }
            }
        } else {
            c[i] = p[i];  // Non-alphabetic characters are copied as-is
        }
    }
    c[len] = '\0';  // Null-terminate the cipher text
}

void decryption(const char pt[], const char ct[], char c[], char d[]) {
    int len = strlen(c);
    for (int i = 0; i < len; i++) {
        if (c[i] >= 'A' && c[i] <= 'Z') {  // Only process uppercase letters
            for (int j = 0; j < 26; j++) {
                if (c[i] == ct[j]) {
                    d[i] = pt[j];
                    break;  // Exit the inner loop once a match is found
                }
            }
        } else {
            d[i] = c[i];  // Non-alphabetic characters are copied as-is
        }
    }
    d[len] = '\0';  // Null-terminate the plain text
}
