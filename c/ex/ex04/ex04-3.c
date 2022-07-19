/* 練習問題4.3 */
/* 例題の階乗を計算する関数factorial()を使って,
1から20までの階乗を表示するプログラムを作りなさい. */
#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(unsigned long long n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
int main() {
    unsigned long long i, ret;
    for (i = 1; i <= 20; i++) {
        ret = factorial(i);
        printf("%lld\n", ret);
    }
    exit(0);
}