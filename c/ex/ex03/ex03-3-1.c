/* 練習問題3.3 */
/* 英語の単語を入力し, dad,mam,peep のように逆から綴っても
同じになるかどうかを判定するプログラムを作成しなさい */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 256
int main() {
    char str[MAXLINE];
    char *s;
    int *p, *q;
    int hantei = 1;

    printf("英単語を入力して下さい\n");
    fgets(str, MAXLINE, stdin);
    s = strchr(str, '\n');
    if (s != NULL) {
        *s = '\0';
    }
    // printf("%s\n", str);
    // 先頭から順に1文字ずつ取り出し,
    // 比較する文字を後ろから1文字ずつ取り出す
    for (int i = 0; i < strlen(str); i++) {
        // 文字が不一致なら回文でない
        if (str[i] != str[(strlen(str)) - i - 1]) {
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