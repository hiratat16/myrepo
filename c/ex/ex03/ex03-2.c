/* 練習問題3.2 */
/* 前の練習問題3.1と同じ機能を関数を使って書いたプログラムを作りなさい.
main()のほかに, void convupper(char *)という関数を作成し,
文字列へのポインタを関数に渡し,関数内で小文字を大文字に変換します. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 256

void convupper(char *str) {
    char *p;
    // 大文字と小文字はそれぞれ"32"離れているため
    // 小文字の文字の値を32('a' - 'A')で引く
    for (p = str; *p != '\0'; p++) {
        if ('a' <= *p && *p <= 'z') {
        *p = *p - ('a' - 'A');
        }
    }
    return;
}

int main() {
    char str1[MAXLINE];
    char *s;
    char ret;

    printf("文字列を入力して下さい\n");
    fgets(str1, MAXLINE, stdin);
    s = strchr(str1, '\n');
    if (s != NULL) {
        *s = '\0';
    }
    // printf("%s\n", str1);
    convupper(str1);
    printf("%s\n", str1);
    exit(0);
}


/* 練習問題3.1 */
/* アルファベットを何文字か1行で入力し,その中に出てくる小文字をすべて
大文字にして出力するプログラムを,ポインタを使わずに配列を用いてmain()関数
だけで作成しなさい. 
小文字を大文字に変換するには, この回で述べた標準ライブラリにあるtoupper()関数を
使いなさい. #include <ctype.h>が必要なことを忘れないようにしましょう.
小文字を引数にとり,大文字の値を返す関数です.
英文の入力は,fgets()を使いましょう */

/* memo */
/* int main(void) {
    char c = 'H';
    printf("moji: %c\n", c);
    printf("suuji: %d\n", c);
    return 0;
}
*/