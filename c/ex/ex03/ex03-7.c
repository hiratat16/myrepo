/* 練習問題3.7 */
/* つるかめ算のプログラムを,頭の数と足の数をそれぞれ入力するようにしたプログラムを
作成しなさい.数字以外の文字が入力された時は,数字を入力しなさいという注意メッセージを
表示させ,再び頭の数と足の数の入力を促しましょう.また,頭の数と足の数の組み合わせが
おかしいときはそのように表示して,別の数の入力を促しましょう.ただし,つるの数とかめの数
を計算し表示したら,次の頭の数の組み合わせの入力を促しましょう. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 256

int main(void) {
    char input[MAXLINE];
    int turu, kame;
    int atama, ashi;
    int ret;

    printf("頭,足(例:8,26)の順番で入れて下さい\n");
    
    while(1) {
        if (fgets(input, MAXLINE, stdin) == NULL) {
            continue;
        }
        ret = sscanf(input, "%d,%d\n", &atama, &ashi);
        if (ret != 2) {
            printf("正しく数字を入力して下さい\n");
            continue;
        }
        // 成功した場合
        break;
    }
    
    // 頭の数と足の数の組み合わせがおかしい場合
    if (atama * 4 < ashi || ashi < atama * 2 || ashi % 2 != 0) {
        printf("頭の数と足の数の組み合わせがおかしいです.\n");
        printf("別の数を入力して下さい.\n");
        return -1;
    }

    kame = (ashi / 2) - atama;
    turu = atama - kame;

    printf("鶴 = %d, 亀 = %d\n", turu, kame);

    return 0;
}