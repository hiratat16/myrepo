/* 練習問題1-2 */
/*
example1.cを参考にして, 2つの数の最大公約数と最小公倍数を求めるプログラムを書きなさい.
*/
#include <stdio.h>
#include <stdlib.h>

int mygcd(int a, int b) {

    int res;
    res = a % b;
    while (res != 0) {
        a = b;
        b = res;
        res = a % b;
    }
    return b;
}

int main(int argc, char *argv[]) {

    int a, b, tmp, x;

    if (argc < 3) {
        exit(1);
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    x = a * b;

    // 自然数 a > b を確認・入替
    if (a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    int gcd;
    gcd = mygcd(a, b);

    printf("最大公約数 = %d\n", gcd);
    printf("最小公倍数 = %d\n", x/gcd);
    return 0;
}


/*
example1.c
#include <stdio.h>
#include <stdlib.h>

int mygcd(int a, int b) {
    int c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(int argc, char *argv[]) {
    int i, j, k;
    i = 1000;
    j = 35;
    k = mygcd(i, j);
    printf("最大公約数は%dです\n", k);
    exit(0);
}
*/