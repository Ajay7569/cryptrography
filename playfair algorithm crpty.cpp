#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5


void preprocessText(char *text) {
    int length = strlen(text);
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            text[count++] = toupper(text[i]);
        }
    }
    text[count] = '\0';
}


void generateKeyMatrix(char *key, char keyMatrix[SIZE][SIZE]) {
    char letters[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; 

    int keyLen = strlen(key);
    int index = 0;

    
    for (int i = 0; i < keyLen; i++) {
        char currentChar = toupper(key[i]);

        if (currentChar == 'J')
            continue;

        if (index / SIZE < SIZE) {
            if (!strchr(key, currentChar)) {
                keyMatrix[index / SIZE][index % SIZE] = currentChar;
                index++;
            }
        }
    }

    
    for (int i = 0; i < 26; i++) {
        char currentChar = letters[i];

        if (!strchr(key, currentChar)) {
            keyMatrix[index / SIZE][index % SIZE] = currentChar;
            index++;
        }
    }
}


void findPosition(char keyMatrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I';

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}


void playfairCipher(char *plaintext, char keyMatrix[SIZE][SIZE]) {
    preprocessText(plaintext);

    int len = strlen(plaintext);
    char encryptedText[len * 2];
    int index = 0;

    for (int i = 0; i < len; i += 2) {
        char ch1 = plaintext[i];
        char ch2 = (i + 1 < len) ? plaintext[i + 1] : 'X'; 

        int row1, col1, row2, col2;
        findPosition(keyMatrix, ch1, &row1, &col1);
        findPosition(keyMatrix, ch2, &row2, &col2);

        if (row1 == row2) {
            encryptedText[index++] = keyMatrix[row1][(col1 + 1) % SIZE];
            encryptedText[index++] = keyMatrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            encryptedText[index++] = keyMatrix[(row1 + 1) % SIZE][col1];
            encryptedText[index++] = keyMatrix[(row2 + 1) % SIZE][col2];
        } else {
            encryptedText[index++] = keyMatrix[row1][col2];
            encryptedText[index++] = keyMatrix[row2][col1];
        }
    }

    encryptedText[index] = '\0';
    printf("Encrypted text: %s\n", encryptedText);
}

int main() {
    char key[100];
    char plaintext[1000];
    char keyMatrix[SIZE][SIZE];

    printf("Enter the keyword: ");
    scanf("%s", key);

    printf("Enter the plaintext: ");
    getchar(); 
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    generateKeyMatrix(key, keyMatrix);

    playfairCipher(plaintext, keyMatrix);

    return 0;
}

