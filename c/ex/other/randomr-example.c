/* randomr-example.c */
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
int main() {
    #define STATE_LEN 256
    char sbuf[STATE_LEN];
    int32_t rnum;
    struct random_data rbuf;
    int i;

    rbuf.state = NULL;
    initstate_r(0, sbuf, STATE_LEN, &sbuf);

    for (i = 0; i < 10; i++) {
        random_r(&rbuf, &rnum);
        printf("%d\n", rnum);
    }
    exit(0);
}