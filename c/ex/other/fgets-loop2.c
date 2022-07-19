/* fgets-loop2.c */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define MAXLEN 8
int main() {
    char input[MAXLEN], *s;

    for (;;) {
        s = fgets(input, MAXLEN, stdin);
        if (s == NULL) {
            break;
        }
        s = strchr(input, '\n');
        if (s != NULL) {
            *s = '\0';
        } else {
            while(getchar() != '\n');
        }
        printf("%s*\n", input);
    }
    exit(0);
}