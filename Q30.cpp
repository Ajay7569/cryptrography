#include <stdio.h>
#include <string.h>
void xorBlocks(const unsigned char *a, const unsigned char *b, unsigned char *result, int block_size) {
    for (int i = 0; i < block_size; i++) {
        result[i] = a[i] ^ b[i];
    }
}
void cbcMac(const unsigned char *key, const unsigned char *message, unsigned char *mac, int block_size) {
    unsigned char iv[block_size];
    memset(iv, 0, block_size); 
    xorBlocks(message, iv, mac, block_size); 
    aesEncrypt("mac, key:12");
}

int main() {
    unsigned char key[16] = {'k', 'e', 'y', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'a', 'b', 'c'};
    unsigned char message[16] = {'m', 'e', 's', 's', 'a', 'g', 'e', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    unsigned char mac[16];
    cbcMac(key, message, mac, 16);
    printf("MAC for one-block message: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", mac[i]);
    }
    printf("\n");
    unsigned char twoBlockMessage[32];
    memcpy(twoBlockMessage, message, 16); 
    xorBlocks(message, mac, twoBlockMessage + 16, 16); 
    cbcMac(key, twoBlockMessage, mac, 16);
    printf("MAC for two-block message: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", mac[i]);
    }
    printf("\n");

    return 0;
}

