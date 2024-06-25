#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define size 26

void encryption(char *alph , char *key , int encrypt){
    int alen = strlen(alph);
    int klen = strlen(key);
    
    for(int i = 0 , j = 0 ; i < alen ; i++){
        if(isalpha(alph[i])){
            char base = islower(alph[i]) ? 'a' : 'A';
            int shift = tolower(key[j % klen]) - 'a';
            
            shift = encrypt ? shift : -shift;
            
            alph[i] = (char) (((alph[i] - base + shift) + size) % size + base);
            j++;
        }
    }
}


int main() {
    char alph[200];
    char key[200];

    printf("Enter the plaintext: ");
    fgets(alph , sizeof(alph) , stdin);
    alph[strcspn(alph , "\n")] = '\0';
    
    printf("Enter the key: ");
    fgets(key , sizeof(key) , stdin);
    key[strcspn(key , "\n")] = '\0';
    
    encryption(alph , key , 1);
    printf("encrypted:  %s\n" , alph);
    
    encryption(alph , key , 0);
    printf("decrypted:  %s\n  " , alph);

    return 0;
}