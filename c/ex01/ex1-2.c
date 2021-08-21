#include <stdio.h>
#include <stdlib.h>

//最大公倍数
int mygcd(int a, int b) {
    int c;
    while(b != 0) {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

//最大公約数
/*
2つの自然数a,bの最大公約数をGCDとすると
最小公倍数LCMは次の公式から求めることができる
LCM = a*b/GCD
*/
int mylcm(int a, int b) {
    return a*b / mygcd(a, b);
}

int main(int argc, char *argv[]) {
    int i, j, k, l;
    i = 1000;
    j = 35;
    k = mygcd(i, j);
    l = mylcm(i, j);
    printf("最大公約数は%dです\n", k);
    printf("最大公約数は%dです\n", l);
    exit(0);
}