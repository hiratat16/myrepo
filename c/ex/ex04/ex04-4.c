/* 練習問題4.4 */
/* フィボナッチ数は,次のように定義されます.
fib(0)=fib(1)=1
fib(n)=fib(n-1)+fib(n-2) (n⩾2)
フィボナッチ数列の最初のいくつかは次のようになります.
1,1,2,3,5,8,13,21,34,55,89,144,...
nが与えられてフィボナッチ数列fib(n)を計算する関数fibを定義し,
それを使ってfib(0)からfib(40)を計算するプログラムを作りなさい.
どのくらいの大きさになるか考えて,各変数の型で表現できる数の範囲に注意しましょう. */
#include <stdio.h>
#include <stdlib.h>
unsigned long fib(unsigned long n) {
    unsigned long f;
    switch (n) {
        case 0:
            f = 0;
            break;
        case 1: case 2:
            f = 1;
            break;
        default:
            f = fib(n - 1) + fib(n - 2);
            break;
    }
    return f;
    // if (n == 0) {
    //     return 0;
    // } else if (n == 1) {
    //     return 1;
    // } else if (n == 2) {
    //     return 1;
    // } else {
    //     return fib(n - 1) + fib(n - 2);
    // }
}
int main() {
    int i; unsigned long ret;
    for (i = 0; i <40; i++) {
        ret = fib(i);
        printf("%ld\n", ret);
    }
    exit(1);
}