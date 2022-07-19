/* 練習問題4.5 */
/* 関数fibを再帰ではなくfor文を使って書き換えたプログラムを作って,
fib(100)まで計算してください */
#include <stdio.h>
#include <stdlib.h>
unsigned long long fib(unsigned long long n) {
    int i; unsigned long long res, f1, f2;
    f1 = 0; f2 = 1;
    for (i = 0; i < n; i++) {
        res = f1 + f2;
        f2 = f1;
        f1 = res;
        }
    return res;
}
int main() {
    unsigned long long answer;
    int i;
    for (i = 0; i < 100; i++) {
        answer = fib(i);
        printf("%lld\n", answer);
    }
    return 0;

}