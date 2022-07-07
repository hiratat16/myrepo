/* 練習問題2.3 */
/* 配列 a[MAXITEM]に, プログラム中で配列の先頭の要素(a[0]なことに注意)から,
それぞれ1からMAXITEMを代入する. その後, すべての配列の要素a[i]に対して, 
a[i]*a[i]を計算し, 対応する別の配列の要素b[i]に代入し,
全てのb[i]をprintfで表示するプログラムを作成しなさい.
MAXITEMはマクロで,プログラムの先頭のほうで次のように定義する.
#define MAXITEM 10 */
#include <stdio.h>
#include <stdlib.h>
#define MAXITEM 10

int main() {
    int i;
    int a[MAXITEM];
    int b[MAXITEM];

    for (i = 1; i <= MAXITEM; i++) {
        a[i] = i; 
    }
    for (i = 1; i <= MAXITEM; i++) {
        b[i] = a[i] * a[i];
        printf("%d\n", b[i]);    
    }
    exit(0);
}
