#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 256
int main(void) {
    char str[MAXLINE];
    char *s;
    char *p, *q;
    int hantei = 0;

    if (fgets(str, MAXLINE, stdin) == NULL) {
        /* エラーフラグを設定し,処理を続行する */
        *str = '\0';
    }
    else {
        s = strchr(str, '\n');
        if (p != NULL) {
            *p = '\0';
        }
    }
    for (p = str, q = &str[(strlen(str)) - 1]; *p != '\0'; p++, q--) {
        if (*p != *q) {
            hantei = 0;
            break;
        }
    }
    if (hantei == 1) {
        printf("回文です\n");
    }
    else {
        printf("回文ではありません\n");
    }
    exit(0);
}