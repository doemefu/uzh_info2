#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 150

/* Implement */
int insertKeyH1(int *HT, int k) {
    int conflicts = 0;
    int key = k%7;

    while (HT[key] != -1) {
        key++;
        conflicts++;
    }

    HT[key] = k;
    return conflicts;
}

/* Implement */
int insertKeyH2(int *HT, int k) {
    int conflicts = 0;
    int key = k%151;

    while (HT[key] != -1) {
        key++;
        conflicts++;
    }

    HT[key] = k;
    return conflicts;
}

/* given */
void initHT(int *HT) {
    for (int i = 0; i < N; ++i) {
        HT[i] = -1;
    }
}

/* given */
void printHT(int *HT) {
    for (int i = 0; i < N; ++i) {
        printf("%d,", HT[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) { //no change required
    clock_t start_time, end_time;
    int collisions = 0;
    int HT[N];
    int keys[100] = {73,  148, 29,  214, 101, 47,  92,  201, 164, 88,  133, 19,
                     176, 58,  123, 82,  209, 37,  147, 66,  112, 193, 79,  155,
                     11,  98,  181, 44,  119, 71,  207, 23,  162, 94,  136, 52,
                     185, 67,  144, 32,  199, 77,  120, 17,  158, 26,  191, 49,
                     105, 14,  173, 55,  129, 84,  201, 38,  168, 59,  112, 70,
                     141, 33,  196, 80,  117, 22,  153, 102, 66,  125, 47,  108,
                     31,  177, 14,  86,  172, 41,  95,  164, 75,  188, 57,  133,
                     16,  121, 74,  144, 39,  109, 168, 81,  201, 53,  97,  24,
                     137, 62,  116, 9};

    initHT(HT);

    start_time = clock();
    for (int i = 0; i < 100; ++i) {
        collisions += insertKeyH1(HT, keys[i]);
    }
    end_time = clock();

    printHT(HT);
    printf("H1: completed in %.2f clocks, %d collisions\n",
           (double)(end_time - start_time), collisions);

    /* improved hash function */
    initHT(HT);
    collisions = 0;

    start_time = clock();
    for (int i = 0; i < 100; ++i) {
        collisions += insertKeyH2(HT, keys[i]);
    }
    end_time = clock();

    printHT(HT);
    printf("H2: completed in %.2f clocks, %d collisions\n\n",
           (double)(end_time - start_time), collisions);

    return 0;
}
