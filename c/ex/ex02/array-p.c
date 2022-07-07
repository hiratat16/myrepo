/* array-p.c */
/* 配列のわたし方 */
// 配列を関数にわたす場合には次のように配列の名前を書き,
// 関数側でも同じように配列で受けとる 
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10
void array(int b[]) {
    int i;
    for (i = 0; i < MAXNUM; i++) {
        b[i] *= 2;
        printf("b[%d] = %d, &b[%d] = %p\n", i, b[i], i, &b[i]);
    }
    return;
}

int main() {
    int i, a[MAXNUM];

    // 整数型変数の配列a[]を初期化
    for (i = 0; i < MAXNUM; i++) {
        a[i] = i;
    }
    array(a);
    for (i = 0; i < MAXNUM; i++) {
        printf("a(%d)=%d, &a[%d] = %p\n", i, a[i], i, &a[i]);
    }
    exit(0);
}
