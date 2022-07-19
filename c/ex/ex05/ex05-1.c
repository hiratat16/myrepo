/* 練習問題5.1 */
/* 練習問題1.3でやったつるかめ算を, コマンド引数として, 頭の数と足の数を入力する
ように変更し, 不正な値や文字の判定をして, 結果を表示するプログラムを作りなさい */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
struct kotae {
    int turu;
    int kame;
} kotae;
int main(int argc, char *argv[]) {
    int kame, turu;
    int atama, ashi;

    if (argc < 3) {
        fprintf(stderr, "入力が正しくありません\n");
        return -1;
    }

    atama = atoi(argv[1]);
    ashi = atoi(argv[2]); 

    if (atama * 4 < ashi || atama * 2 > ashi || atama % 2 != 0) {
        printf("頭の数と足の数の組み合わせがおかしいです\n");
        exit(0);
    }
    kame = (ashi - atama * 2) / 2;
    turu = atama - kame;
    printf("亀=%d, 鶴=%d\n", kame, turu);

    return 0; 
}