#include <stdio.h>
#include <stdlib.h>

#define N 10

struct elem {
    int val;
    int status; /* 0: occ, -1 emp */
};

/* print */
void printHT(int *HT) {
    for (int i = 0; i < N; ++i) {
        printf("%d,", HT[i]);
    }
    printf("\n");
}

int h(int k, int i) { return ((k + 4) + i) % N; }

int insertH(int *T, int k) {
    int index = h(k, 0);
    int c = 0;

    while (T[index] != -1 && c < N) {
        c++;
        index = h(k, c);
    }

    if (c >= N) {
        printf("full for %d\n", k);
        return -1; /* failure */
    }

    /* T[index].val = k; */
    /* T[index].status = 0; */
    T[index] = k;
    return 0; /* success */
}

int HTdelete(int *T, int k) {
    int index = h(k, 0);     /* index */
    int indexActual = index; /* save original index */
    int c = 0;               /* counter */

    while (c<N && T[index] != k && T[index]!=-1) {
        c++;
        index = h(k, c);
    }

    if (c >= N || T[index] == -1) /* not found */
        return -1;

    T[index]=0;


    int c=0;
    while (c<N) {

        c++;
    }

}

int main(int argc, char *argv[]) {
    int T[N] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int vals[] = {32, 52, 33, 74, 96}; /* constraint: only positive */

    /* init hash table as of ex (a) */
    for (int i = 0; i < N; ++i) {
        /* struct elem * e = malloc(sizeof(struct elem)); */
        /* T[i] = &e */
        /* T[i].status = -1; */
        T[i] = -1;
    }
    for (int i = 0; i < 5; ++i)
        insertH(T, vals[i]);

    /* delete example val 33 */
    printf("Before del 33: ");
    printHT(T);

    HTdelete(T, 33);

    printf("After del 33:  ");
    printHT(T);

    return 0;
}
