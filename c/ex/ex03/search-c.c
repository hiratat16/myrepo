/* search-c.c */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

int searchc(char *s, char c) {
    char *p;
    int i = 1;

    for(p = s; *p != '\0'; p++, i++) {
        if (*p == c) {
            break;
        }
    }
    if (*p == '\0') {
        return -1;
    } else {
        return i;
    }
}
int main() {
    char input[MAXLINE];
    int c, loc;
    printf("文字列を入れて下さい\n");
    if (fgets(input, MAXLINE, stdin) == NULL) {
        /* エラーフラグを設定し, 処理を続行する */
        *input = '\0';
    }
    printf("探す文字を入れて下さい\n");
    c = getc(stdin);
    // if (c == EOF) {
    //     if( feof(fp)) {
    //         printf("終わり\n");
    //     } else if (ferror(fp)) {
    //         printf("Error\n");
    //     }
    // }
    loc = searchc(input, c);
    if (loc < 0) {
        printf("%cは見つかりませんでした\n", c);
    } else {
        printf("%cは%d番目に見つかりました\n", c, loc);
    }
    exit(0);
}