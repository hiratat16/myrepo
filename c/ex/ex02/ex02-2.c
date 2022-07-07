/* 練習問題2.2 */
/* 前問で, 整数型変数を2個ではなく, 3個にして, 同じように関数を呼び出して,
大きなほうから小さいほうに並びかえるプログラムを作成しなさい */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

int sort3items(int *a, int *b, int *c) {

    int tmp;
    if (*a < *b) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
    if (*a < *c) {
        tmp = *a;
        *a = *c;
        *c = tmp;
    }
    if (*b < *c) {
        tmp = *b;
        *b = *c;
        *c = tmp;
    }
    return 0;
}

int main() {
    int x, y, z;
    char input[MAXLINE];
    int ret;

    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d,%d,%d", &x, &y, &z);
    if (ret != 3) {exit(0);}

    sort3items(&x, &y, &z);

    printf("%d,%d,%d\n", x, y, z);

    exit(0);

}

/* 練習問題2.1 */
/* mainの中でローカル変数として整数型変数を2つ定義し,
その2つを引数として関数に渡し,
関数の中で,2つの数のうち小さくない方を1番目の引数に入れ,
そうでない方を2番目の引数に入れて返すプログラムを作成しなさい. */


