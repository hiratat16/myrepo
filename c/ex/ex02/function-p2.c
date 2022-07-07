/* function-p2.c */
#include <stdio.h>
#include <stdlib.h>

/* 引数を受け取るほうは, 記憶場所を示すアドレスがわたされ, その記憶場所に整数型の値が
入っているとして処理する. */
void multi2(int *a, int *b) {
    *b = *a * 2;
    printf("In multi2: a = %d, b = %d\n", *a, *b);
    printf("&a = %p, &b = %p\n", &a, &b);
    return;
}

int main() {
    int p, q;

    p = 10; q = 0;
    multi2(&p, &q);
    printf("In main: p = %d, q = %d\n", p, q);
    printf("&p = %p, &q = %p\n", &p, &q);
    exit(0);
}