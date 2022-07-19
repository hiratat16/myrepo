#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 256

int main() {
    char str1[MAXLINE];
    char *p;
    char *s;

    printf("文字を入力して下さい\n");
    fgets(str1, MAXLINE, stdin);
    /* 文字列の最後の\nをNULL文字に換える */
    s = strchr(str1, '\n');
    if (s != NULL) {
        *s = '\0';
    }
    printf("str1[] = %s\n", str1);
    for (p = str1; *p != '\0'; p++) {
        printf("%s\n", p);
    }
    exit(0);
}