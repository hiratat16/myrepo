/* is-example.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 256
int main() {
    char str1[MAXLINE];
    char *s;

    printf("文字列を入れて下さい\n");
    if (fgets(str1, MAXLINE, stdin) == NULL) {
        /* エラーフラグを代入し, 処理を続行する */
        *str1 = '\0';
    }
    s = strchr(str1, '\n');
    if (s != NULL) {
        *s = '\0';
    }
    /* 文字列の表示 */
    printf("入力されたのは%sです\n", str1);
    /* 文字列の検査 */
    for (s = str1; *s != '\0'; s++) {
        if (isdigit(*s)) {
            printf("%cは数字です", *s);
            continue;
        }
        if (isalpha(*s)) {
            printf("%cはAlphabetです\n", *s);
            if (isxdigit(*s)) {
                printf("16真数でも使われます\n");
                continue;
            }
        }
        if (isspace(*s)) {
            printf("%cは空白文字です\n", *s);
            continue;
        }
        printf("%cはその他の文字です\n", *s);
    }
    exit(0);
}