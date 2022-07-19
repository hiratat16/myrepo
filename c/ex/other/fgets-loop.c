/* fgets-loop.c */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define MAXLEN 8
int main() {
    char input[MAXLEN], *s;

    for(;;) {
        s = fgets(input, MAXLEN, stdin);
        if (s == NULL) {
            break;
        }
        printf("%s*", input);
    }
    exit(0);
}