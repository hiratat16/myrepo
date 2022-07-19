/* 練習問題4.6 */
/* 二重階乗
階乗はn!でしたが,n!!というものもあります.これは次のように定義されます.
0!! = (-1)!! = 1
n!! = n * (n - 2)!!
1から15までのn!!を計算するプログラムを作りなさい */
#include <stdio.h>
#include <stdlib.h>
unsigned long long factorial(unsigned long long n) {
    if (n == 0) { return 1; }
    else if (n == 1 || n == 2) { return n; }
    else {
        return n * factorial(n - 2);
    }
}

int main() {
    unsigned long long ret; int i;
    for (i = 0; i < 15; i++) {
        ret = factorial(i);
        printf("%lld\n", ret);
    }
    exit(0);
}

