/* random-example.c */
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
int main() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%ld\n", random());
    }
    exit(0);
}