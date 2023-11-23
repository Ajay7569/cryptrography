#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26


void calculateFrequencies(const char *input, int frequencies[]) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        char ch = tolower(input[i]);
        if (isalpha(ch)) {
            frequencies[ch - 'a']++;
        }
    }
}


void frequencyAttack(const char *ciphertext, int topPlaintexts) {
    int ciphertextLength = strlen(ciphertext);

    int frequencies[ALPHABET_SIZE] = {0};
    calculateFrequencies(ciphertext, frequencies);

  
    char decryptionKey[ALPHABET_SIZE + 1];
    decryptionKey[ALPHABET_SIZE] = '\0';
    int sortedIndices[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        sortedIndices[i] = i;
    }

    for (int i = 0; i < ALPHABET_SIZE - 1; i++) {
        for (int j = i + 1; j < ALPHABET_SIZE; j++) {
            if (frequencies[sortedIndices[i]] < frequencies[sortedIndices[j]]) {
                int temp = sortedIndices[i];
                sortedIndices[i] = sortedIndices[j];
                sortedIndices[j] = temp;
            }
        }
    }


    for (int i = 0; i < ALPHABET_SIZE; i++) {
        int shift = sortedIndices[i] - ('e' - 'a');
        if (shift < 0) {
            shift += ALPHABET_SIZE;
        }
        decryptionKey['a' + sortedIndices[i]] = 'a' + shift;
    }


    printf("Top %d possible plaintexts:\n", topPlaintexts);
    for (int i = 0; i < topPlaintexts; i++) {
        printf("%d. ", i + 1);
        for (int j = 0; j < ciphertextLength; j++) {
            char ch = ciphertext[j];
            if (isalpha(ch)) {
                char decrypted = decryptionKey[tolower(ch)];
                if (isupper(ch)) {
                    decrypted = toupper(decrypted);
                }
                printf("%c", decrypted);
            } else {
                printf("%c", ch);
            }
        }
        printf("\n");
    }
}

int main() {
    char ciphertext[] = "Wkh frxuvh lv d vhfuhw phvvdjh."; 

    int topPlaintexts;
    printf("Enter the number of top possible plaintexts to generate: ");
    scanf("%d", &topPlaintexts);

    frequencyAttack(ciphertext, topPlaintexts);

    return 0;
}

