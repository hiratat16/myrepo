/* 練習問題2.1 */
/* mainの中でローカル変数として整数型変数を2つ定義し,
その2つを引数として関数に渡し,
関数の中で,2つの数のうち小さくない方を1番目の引数に入れ,
そうでない方を2番目の引数に入れて返すプログラムを作成しなさい. */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

void sort2items(int *a, int *b) {
    int tmp;
    if (*a < *b) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
    return;
}

int main() {
    int x, y; // 符号なし整数を2つ定義
    int ret; 
    char input[MAXLINE];

    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d,%d", &x, &y);
    if (ret != 2) {exit(1);}

    compare(&x, &y);

    printf("%d,%d\n", x, y);

    exit(0);
}
