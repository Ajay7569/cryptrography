#include <stdio.h>
#include <string.h>

// Function to perform ECB encryption
void ecb_encrypt(char *plaintext, char *key) {
    // Perform encryption logic here
    // In a real implementation, you would use a proper encryption algorithm
    // For simplicity, let's assume a simple XOR operation with the key

    int i, len = strlen(plaintext);
    for (i = 0; i < len; i++) {
        plaintext[i] ^= key[i % strlen(key)];
    }
}

// Function to perform ECB decryption
void ecb_decrypt(char *ciphertext, char *key) {
    // Perform decryption logic here
    // In a real implementation, you would use a proper decryption algorithm
    // For simplicity, let's assume the same XOR operation with the key as encryption

    int i, len = strlen(ciphertext);
    for (i = 0; i < len; i++) {
        ciphertext[i] ^= key[i % strlen(key)];
    }
}

int main() {
    char plaintext[] = "HelloWorld"; // 11 characters including '\0'
    char key[] = "Key123"; // Example key

    // Display original plaintext
    printf("Original plaintext: %s\n", plaintext);

    // Encryption
    ecb_encrypt(plaintext, key);
    printf("Encrypted ciphertext: %s\n", plaintext);

    // Decryption
    ecb_decrypt(plaintext, key);
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}

