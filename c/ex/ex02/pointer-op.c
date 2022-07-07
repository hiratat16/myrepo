#include <stdio.h>
#include <stdlib.h>
int main() {
    int a[10]; int *p;
    int i;

    for (i = 0; i < 10; i++) {
        a[i] = i;
    }
    printf("&a[0]=%p, &i=%p, &p=%p\n", &a[0], &i, &p);
    p = a;
    printf("p=%p, *p=%d, sizeof(%ld)\n", p, *p);
    p++;
    printf("p=%p, *p=%d\n", p, *p);
    exit(0);
}
