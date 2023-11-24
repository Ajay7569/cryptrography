#include <stdio.h>
#include <stdint.h>

#define STATE_SIZE 25
#define CAPACITY_BITS 576
#define MESSAGE_BLOCK_SIZE 1024

typedef uint64_t state_t[STATE_SIZE];
void initializeState(state_t state) {
    for (int i = 0; i < STATE_SIZE; ++i) {
        state[i] = 0;
    }
    for (int i = 0; i < CAPACITY_BITS / 64; ++i) {
        state[i] = 12;
    }
}

int main() {
    state_t state;
    initializeState(state);
    printf("Initialized State:\n");
    for (int i = 0; i < STATE_SIZE; ++i) {
        printf("%016llx ", state[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }

    return 0;
}

