/* 練習問題2.4 */
/* 2次元配列を関数に渡したarray-p2.cを参考にして,
3次元配列を関数に渡すプログラムex2-4.cを作成しなさい.
例えば, mainの先頭で次のように配列を定義する. 
int a[MAXROW][MAXCOL][MAXZ]*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_X 4
#define MAX_Y 3
#define MAX_Z 2

void array(int b[MAX_X][MAX_Y][MAX_Z]) {
    int i, j, k;
    for (i = 0; i < MAX_X; i++) {
        for (j = 0; j < MAX_Y; j++) {
            for (k = 0; k < MAX_Z; k++) {
                b[i][j][k] *= 2;
            }
        }
    }
    return;
}

int main() {
    int i, j, k;
    int a[MAX_X][MAX_Y][MAX_Z];
    
    for (i = 0; i < MAX_X; i++) {
        for (j = 0; j < MAX_Y; j++) {
            for (k = 0; k < MAX_Z; k++) {
                a[i][j][k] = i*j*k;
            }
        }
    }
    array(a);
    for (i = 0; i < MAX_X; i++) {
        for (j = 0; j < MAX_Y; j++) {
            for (k = 0; k < MAX_Z; k++) {
                printf("a(%d)(%d)(%d)=%d\n", i, j, k, a[i][j][k]);
            }
        }
    }
    exit(0);
}


/* array-p2.c */
/*
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
            printf("a(%d)(%d)\n", i, j, a[i][j]);
        }
    }
    exit(0);
}
*/