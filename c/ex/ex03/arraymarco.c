#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 5
int main() {
    int i, a[ARRAYSIZE];
    for (i = 0; i < ARRAYSIZE; i++) {
        a[i] = 1;
    }
    for (i = 0; i < ARRAYSIZE; i++) {
        printf("s(%d) = %d\n", i, a[i]);
    }
    exit(0);
}