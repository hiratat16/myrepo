/* 問題 */
/* テキストのpointer4.cなどを参考にして,次の要件を満たすプログラムを作成してください.
そして,テキストに示されたような変数の記憶場所(アドレス)とその占める大きさ,
記憶されている内容を図解する図表を作り,その説明をしてください.レポートはpdf形式で
A4用紙を縦長に使い,横書きで記述してください.作成したプログラムと図以外の本文の量は
1ページ以内におさめてください.また,図は手書きではなく,ワードやペイント,エクセルなど
そのほかのツールを使って作成してください.
・整数型の変数(記憶領域の大きさの違うもの2種類),整数型の配列変数,文字列の変数,
   文字列(文字型の配列),ポインタ型の変数を定義する
・各変数に値を代入し,アドレスとともにprintf()で表示する

記憶場所に占める領域の大きさを直接知る方法として,sizeof演算子を使う方法があります.

sizeof(int)とすると,その処理系をint型の占める記憶領域のバイト数が得られますので,
それをprintf()で表示すると正確な値が得られます. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    /*---------- 整数型の変数(記憶領域の大きさの違うもの2種類) ----------*/
    printf("整数型の配列変数\n");
    int seisu_1; long int seisu_2; 
    seisu_1 = 5; seisu_2 = 10;
    printf("seisu_1 = %d, &seisu_1 = %p, sizeof(%lu)\n", seisu_1, &seisu_1, sizeof(seisu_1));
    printf("seisu_2 = %ld, &seisu_2 = %p, sizeof(%lu)\n", seisu_2, &seisu_2, sizeof(seisu_2));

    /*---------- 整数型の配列変数 ----------*/
    printf("\n");
    printf("整数型の配列変数\n");
    int hairetsu[3] = {1, 2, 3};
    printf("hairetsu[0] = %d, &hairetsu[0] = %p, sizeof(%lu)\n", hairetsu[0], &hairetsu[1], sizeof(hairetsu[1]));
    printf("hairetsu[1] = %d, &hairetsu[1] = %p, sizeof(%lu)\n", hairetsu[1], &hairetsu[2], sizeof(hairetsu[2]));
    printf("hairetsu[2] = %d, &hairetsu[2] = %p, sizeof(%lu)\n", hairetsu[2], &hairetsu[3], sizeof(hairetsu[3]));

    // &hairetsu[0]とhairetsuは同じアドレス.sizeof(hairetsu)で配列全体のサイズが得られる.
    printf("hairetsu = %p, sizeof(hairetsu)=%lu\n", hairetsu, sizeof(hairetsu));

    /*---------- 文字型の変数 ----------*/
    printf("\n");
    printf("文字型の変数\n");
    char moji = 'A';
    printf("moji = %d, &moji = %p, sizeof(%lu)\n", moji, &moji, sizeof(moji));

    /*---------- 文字列(文字型の配列) ----------*/
    printf("\n");
    printf("文字列(文字型の配列)\n");
    char moji_hairetsu[] = "APPLE";
    // &moji_hairetsuとmoji_hairetsuは同じアドレス
    // sizeof(moji_hairetsu)では配列全体のサイズ, sizeof(&moji_hairetsu)ではポインタのサイズが得られる
    printf("moji_hairetsu=%s, &moji_hairetsu=%p, moji_hairetsu=%p, sizeof(moji_hairetsu)=%lu, sizeof(&moji_hairetsu)=%lu\n",
        moji_hairetsu, &moji_hairetsu, moji_hairetsu, sizeof(moji_hairetsu), sizeof(&moji_hairetsu));

    /*---------- ポインタ型の変数の定義 ----------*/
    printf("\n");
    printf("ポインタ型の変数の定義\n");
    int *p; 
    int a = 15;
    p = &a;
    printf("a = %d, &a = %p\n", a, &a);
    printf("p = %p, *p = %d, &p = %p, sizeof(%lu)\n", p, *p, &p, sizeof(*p));

    /*---------- 補足 ----------*/
    printf("\n");
    printf("文字列(文字型の配列)と文字型へのポインタ\n");
    char a[] = "Hello";
    char *b = "Hello";
    printf("a = %s, &a = %p, a = %p, sizeof(%ld), sizeof(%ld)", a, &a, a, sizeof(a), sizeof(&a));
    printf("b = %s, &b = %p, b = %p, sizeof(%ld), sizeof(%ld)", b, &b, b, sizeof(b), sizeof(&b));


    exit(0);
}