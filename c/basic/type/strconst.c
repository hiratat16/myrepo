/* train02の補足説明 */
/* 文字型の配列の初期化とその記憶領域に関する追加説明 */

/* 次のプログラムでは, 文字型の配列と, 文字型へのポインタの二つの変数があり,
それぞれ, 同じ文字列で初期化している. 出力結果で示される記憶領域を確認しよう. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char a[] = "HELLO";
    char *b = "HELLO";

    printf("a = %s, &a = %p, a = %p, sizeof(%ld), sizeof(%ld)\n", a, &a, a, sizeof(a), sizeof(&a));
    printf("b = %s, &b = %p, b = %p, sizeof(%ld), sizeof(%ld)\n", b, &b, b, sizeof(b), sizeof(&b));
    return 0;
}

/* memo */
/*
%s:
%sは対応する変数を文字型変数へのポインタとして扱い,そのポインタの示す
場所から終端文字('\0')に到達するまで文字列を表示する.

*/
