#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26


void polyalphabeticCipher(char *plaintext, char *key) {
    int textLength = strlen(plaintext);
    int keyLength = strlen(key);
    char ciphertext[textLength + 1];

    for (int i = 0; i < textLength; i++) {
        char currentChar = plaintext[i];
        if (isalpha(currentChar)) {
            char shift = key[i % keyLength] - 'A';
            char base = isupper(currentChar) ? 'A' : 'a';
            ciphertext[i] = (currentChar - base + shift) % ALPHABET_SIZE + base;
        } else {
            ciphertext[i] = currentChar; 
        }
    }
    ciphertext[textLength] = '\0';
    printf("Encrypted text: %s\n", ciphertext);
}

int main() {
    char plaintext[1000];
    char key[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    printf("Enter the key: ");
    scanf("%s", key);

    polyalphabeticCipher(plaintext, key);

    return 0;
}

