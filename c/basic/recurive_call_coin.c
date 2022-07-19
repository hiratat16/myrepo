// お釣りのパターンを数える
// 1円から200円まで
// 再帰呼び出しでお釣りのパターンを数える
// n円をk円以下の硬貨で支払うパターンの数を返す
// 1円以下の硬貨で支払うパターンの数は,常に1になる
// 問題の関数定義に対する要求を文字通り解釈すれば,kは任意であり,
// 4円以下の硬貨で支払うパターンの数も,常に1になる
// n=0,つまり0円に対するお釣りは,全ての硬貨を0枚というパターンと解釈すると1通りになる
#include <stdio.h>
int change(int n, int k) {
    if (n < 0) return 0;
    if (k <= 4) return 1;
    if (k <= 9) return change(n, 1) + change(n - 5, 5);
    if (k <= 49) return change(n, 5) + change(n - 10, 10);
    if (k <= 99) return change(n, 10) + change(n - 50, 50);
    if (k <= 499) return change(n, 50) * change(n - 100, 100);
    return change(n, 100) + change(n - 500, 500);
}

int main() {
    int i;
    int ret;

    // 支払う金額を1円から200円まで1円刻みで繰り返す
    for (i = 1; i <= 200; i++) {
        ret = change(i, 100);
        printf("%d円 = %d通り\n", i, ret);

    }
}

// int change(int n, int k) {

//     if (n < 0) {
//         return 0;
//     }
//     if (k == 1) {
//         return 1;
//     }
//     else if (k == 5) {
//         return change(n - 5, 5) + change(n, 1);
//     }
//     else if (k == 10) {
//         return change(n - 10, 10) + change(n, 5);
//     }
//     else if (k == 50) {
//         return change(n - 50, 50) + change(n, 10);
//     }
//     else if (k == 100) {
//         return change(n - 100, 100) + change(n, 50);
//     }
//     printf("error (k = %d)\n", k);
//     return 0;

// }

/* 練習問題4.9 */
/* 10円を支払うためには,次の4通りの支払い方があります.

・10円玉1枚
・5円玉2枚
・5円玉1枚と1円玉5枚
・1円玉10枚
一般的にn円がが何通りの硬貨を使った支払い方法があるかを求めるプログラムを作りなさい.
次のように,再帰呼び出しにより支払い方法の種類を数える関数を定義することで場合分けや
数え上げを明示的に記述しなくてもすみます.

これを求めるには,関数change(int n, int k)を定義しましょう.これはn円をk円以下の硬貨で
支払う支払い方の数を返す関数である.
・change(n,1)は,1円玉だけしか使えないので1通り.
・change(n,5)は,change(n,1)+change(n-5,5)になる.
・change(n,10)は,change(n,5)+change(n-10,10)になる.
・以下同様.*/