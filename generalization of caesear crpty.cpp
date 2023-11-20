#include <stdio.h>


int areCoprime(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a == 1; 
}

int main() {
    int allowedValues = 0;

    printf("Values of 'a' not allowed for the affine Caesar cipher:\n");

    for (int a = 1; a < 26; a++) {
        if (areCoprime(a, 26)) {
            printf("%d ", a);
        } else {
            allowedValues++;
        }
    }

    if (allowedValues == 0) {
        printf("No values of 'a' are disallowed for the affine Caesar cipher.\n");
    }

    return 0;
}

