/* 練習問題3.1 */
/* アルファベットを何文字か1行で入力し,その中に出てくる小文字をすべて
大文字にして出力するプログラムを,ポインタを使わずに配列を用いてmain()関数
だけで作成しなさい. 
小文字を大文字に変換するには, この回で述べた標準ライブラリにあるtoupper()関数を
使いなさい. #include <ctype.h>が必要なことを忘れないようにしましょう.
小文字を引数にとり,大文字の値を返す関数です.
英文の入力は,fgets()を使いましょう */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 256

int main() {
    char str1[MAXLINE];
    char ret;
    char *s;

    printf("アルファベットを入力して下さい\n");
    fgets(str1, MAXLINE, stdin);
    /* 文字列の最後の\nをNULL文字に換える */
    s = strchr(str1, '\n');
    if (s != NULL) {
        *s = '\0';
    }
    
    /* 文字列の表示 */
    printf("入力されたのは%sです\n", str1);
    /* 文字列の変換 */
    for (int i = 0; i < strlen(str1); i++) {
        str1[i] = toupper(str1[i]);
    }
    printf("%s\n", str1);

    exit(0);
}