/* 練習問題1-1 */
/*
次の数列を順番に計算するプログラムex1-1.cを書きましょう.とりあえず,30番目くらいまで
計算するようにしましょう.
1 1 2 3 5 8 13 ......
*/

#include <stdio.h> // ファイルからの文字や数の読み込み,書き出し

int main() {

    /* 変数の宣言 */
    int f0, f1, f2;

    f0 = 0;
    f1 = 1;

    /* フィボナッチ数(n=0)の出力 */
    // printf("%d\n", f0);

    /* フィボナッチ数の計算 */
    for (int i = 0; i < 30; i++) {
        // フィボナッチ数の出力(n>0)
        printf("%d\n", f1);

        // フィボナッチ数の計算
        f2 = f1 + f0;
        
        // 変数の代入
        f0 = f1;
        f1 = f2;
    }
    return 0;
}