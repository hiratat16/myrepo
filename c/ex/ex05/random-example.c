/* random-example.c */
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
int main() {
    int i;
    int res[10];
    for (i = 0; i < 10; i++) {
        // 1から10までの乱数を発生
        // printf("%d\n", rand() % 10 + 1);
        res[i] = rand() % 10 + 1;
        printf("%d\n", res[i]);
    }
    exit(0);
}