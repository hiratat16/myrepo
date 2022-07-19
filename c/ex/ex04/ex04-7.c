/* 練習問題4.7 */
/* 1と自分自身以外の数で割り切れない数を素数(prime number)といいます.
たとえば,2とか7とか19とかが素数です.ここでは,エラトステネス(Eratosthenes)の
古い方法を使って10000以下の素数を表示するプログラムを作りなさい.
次のような手順を実行します.
・2~10000までの数を数えあげておきます.
・最小の数2を残して,その倍数を全て消す.
・残った最小の数3を残して,その倍数を消す.
・残った最小の数5を残して,その倍数を消す.
・以下同様に,残った最小の数を残して,その倍数を消します.
・これを繰り返すと,消し残ったものが素数ということになります.
これをプログラムするためには,2~10000の表を配列として定義しておく必要があります.
例えば,次のようにします.
char prime[10001];
prime[i]にiが素数かどうかを入れておくことにしましょう.
例えば,0なら素数ではなく,1なら素数ということにします.この表を初期化し,上の順番に従って
素数でないものを消していきます.最後に,残った素数を綺麗に表にして出力しましょう.
数が大きくなると計算に時間がかかるので,始めは100までの素数の表とかから実験した方が良いでしょう.
このためには,次のように,マクロを定義しておくとわかりやすいプログラムになります.
#define MAXNUMBER 10001
*/
#include <stdio.h>
#define MAXNUM 10
#define PRIME 1
#define NON_PRIME 0
int main() {
    unsigned char prime[MAXNUM];
    int i, j;
    // 全てにPRIMEマークを付ける
    for (i = 2; i < MAXNUM; i++) {
        prime[i] = PRIME;
    }
    // 2から全ての倍数にNON_PRIMEマークを付ける
    for (i = 2; i < MAXNUM; i++) {
        for (j = i * 2; j < MAXNUM; j = j + i) {
            prime[j] = NON_PRIME;
            // printf("%d\n", j);
        }
    }
    // PRIMEとして残ったものを表示
    for (i = 2; i < MAXNUM; i++) {
        if (prime[i] == PRIME) {
            printf("%d\n", i);
        }
    }
    return 0;
}

/* その他 */
/*
#include <stdio.h>
 
#define N   100
 
void main(){
    //  Nまでの数の素数を表示する。
    int i,m,n;
    int data[N + 1], result[N + 1];
    //  配列の要素に1を入れる。
    for (i = 0; i < N+1; i++){
        data[i] = 1;
    }
    //  0と1は、最初から除外する
    data[0] = 0;
    data[1] = 0;
    m = 2;
    n = 0;
    do{
        //  素数の倍数をリストから削除する
        for (i = 2 * m; i < N + 1; i+=m){
            data[i] = 0;
        }
        //  結果を格納
        result[n] = m;
        n++;
        //  次の素数候補を見つける
        do{
            m++;
        }while (data[m] == 0 && m < N + 1);
    } while (m < N + 1);
    //  結果の出力
    for (i = 0; i < n; i++){
        //  10行ごとに改行
        printf("%3d ", result[i]);
        if ((i+1) % 10 == 0){
            printf("¥n");
        }
    }
    printf("¥n");
} 
*/