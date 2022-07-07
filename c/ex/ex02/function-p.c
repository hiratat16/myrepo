/* function-p.c */
#include <stdio.h>
#include <stdlib.h>

void multi2(int a, int b) {
    b = a * 2;
    printf("In multi2: a = %d, b = %d\n", a, b);
    printf("%p, %p\n", &a, &b);
    printf("%ld, %ld\n", sizeof(a), sizeof(b));
    return;
}

int main() {
    int p = 0, q = 0;

    p = 10; q = 0;
    multi2(p, q);
    printf("In main: p=%d, q=%d\n", p, q);
    printf("%p, %p\n", &p, &q);
    printf("%ld, %ld\n", sizeof(p), sizeof(q));
    exit(0);
}