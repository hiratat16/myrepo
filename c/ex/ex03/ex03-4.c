/* 練習問題3.4 */
/* 文字列を3種類入力し, それぞれ, ○, ×, △とする.
これらを並べて3種類の文字列, ○×△, △×○, ×○△× を作成し,
変数として用意された3つの文字型配列にそれぞれ入れましょう.
そしてそれらの文字型配列を表示するプログラムを作成しなさい */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 256
int main(void) {
    char input[MAXLINE];
    char A[MAXLINE], B[MAXLINE], C[MAXLINE];
    char str1[MAXLINE], str2[MAXLINE], str3[MAXLINE];
    char *s;
    int ret;

    printf("A B C の3種類の文字列を入力して下さい\n");
    if (fgets(input, MAXLINE, stdin) == NULL) {
        /* エラーフラグを設定し, 処理を続行する */
        *input = '\0';
    }
    /* 文字列の最後の\nを'\0'に換える */
    else {
        s = strchr(input, '\n');
        if (s != NULL) {
            *s = '\0';
        }
    }
    ret = sscanf(input, "%s %s %s", A, B, C);

    // 3種類の文字列を3つの文字型配列に入れる
    sprintf(str1, "%s %s %s", A, B, C);
    sprintf(str2, "%s %s %s", C, B, A);
    sprintf(str3, "%s %s %s %s", B, A, C, B);

    printf("----- 生成した文字列を表示 -----\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);

    return 0;
}
