/* 練習問題3-5 */
/* 少し長めの文字列を入力し,5文字ずつに分割して,別々の変数に入れて,
その後表示するプログラムを作りなさい. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 256
int main(void) {
    char input[MAXLINE];
    char *s,*p;
    // char ret1[MAXLINE];
    // char ret2[MAXLINE]; 
    // char ret3[MAXLINE];
    printf("少し長めの文字列を入力して下さい\n");
    if (fgets(input, MAXLINE, stdin) == NULL) {
        /* エラーフラグを設定し, 処理を実行する */
        *input = '\0'; }
    else {
        s = strchr(input, '\n');
        if (s != NULL) { *s = '\0';}
    }
    /* ----- memcpy ----- */
    // memcpy(ret1, input, 5);
    // ret1[5] = '\0';
    // memcpy(ret2, &input[5], 5);
    // ret2[5] = '\0';
    // memcpy(ret3, &input[10], 5);
    // ret3[5] = '\0';
    // printf("%s\n", ret1);
    // printf("%s\n", ret2); 
    // printf("%s\n", ret3);

    /* ----- for文 ----- */
    // for (int i = 0; i < 5; i++) {
    //     ret1[i] = input[i];
    // }
    // ret1[5] = '\0';

    /* ----- for文 ----- */
    /* ----- 3つ以上に対応したい場合,2次元配列やmallocを使用する ----- */
    int i;
    int len = strlen(input);
    int count = len / 5;
    char ret[count][6];
    /* ----- inputの長さが5で割り切れない時オーバーフローする ----- */
    // for (i = 0; i < count; i++) {
    //     memcpy(ret[i], &input[i * 5], 5);
    //     ret[i][5] = '\0';
    // }
    // for (i = 0; i < count; i++) {
    //     printf("%s\n", ret[i]);
    // }
    /* ----- チェック(オーバーフローを防ぐ) ----- */
    for (i = 0; i < count; i++) {
        int str_len = strnlen(&input[i * 5], 5);
        memcpy(ret[i], &input[i * 5], str_len);
        ret[i][5] = '\0';
        if (str_len < 5) { break; }
    }
    for (i = 0; i < count; i++) {
        printf("%s\n", ret[i]);
    }
    
    exit(0);
}