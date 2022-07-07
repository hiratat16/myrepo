/* array-p2.c */
// void array(int b[MAXROW][MAXCOL])のように, 関数側で配列の大きさを指定しないと,
// 2次元配列をどのように扱っていいのかわからないのでエラーになる.
#include <stdio.h>
#include <stdlib.h>
#define MAXROW 5
#define MAXCOL 4
void array(int b[MAXROW][MAXCOL]) {
    int i, j;
    for (i = 0; i < MAXROW; i++) {
        for (j = 0; j < MAXCOL; j++) {
            b[i][j] *= 2;
        }
    }
    return;
}

int main() {
    int i, j;
    int a[MAXROW][MAXCOL];

    for (i = 0; i < MAXROW; i++) {
        for (j = 0; j < MAXCOL; j++) {
            a[i][j] = i * j;
        }
    }
    array(a);
    for (i = 0; i < MAXROW; i++) {
        for (j = 0; j < MAXCOL; j++) {
            printf("a(%d)(%d)=%d\n", i,j,a[i][j]);
        }
    }
    exit(0);
}