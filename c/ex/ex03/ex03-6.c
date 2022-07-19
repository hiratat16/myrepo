/* 練習問題3.6 */
/* 文字列を入力して, 入力された文字の順番を入れ替えてでたらめな文字列を
作成するプログラムを作りなさい. 入力された文字の種類と数は同じになるようにしましょう. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXLINE 256
/* 文字列をシャッフルする */
char *strshf(char *s) {
    int len = strlen(s);
    int i, j;
    char tmp;

    /* Fisher-Yates のシャッフル */
    for (i = len - 1; i > 0; i--) {
        j = rand() % i;
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
    }
    return s;
}

int main(void) {
    char input[MAXLINE];
    char *s;
    srand((unsigned)time(NULL));

    if (fgets(input, MAXLINE, stdin) == NULL) {
        *input = '\0';
    }
    s = strchr(input, '\n');
    if (s != NULL) {
        *s = '\0';
    }
    printf("シャッフル前:%s\n", input);
    strshf(input);
    printf("シャッフル後:%s\n", input);

    return 0;
}