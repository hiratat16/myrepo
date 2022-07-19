/* struct-p2.c */
/* ポインタを使ったわたし方 */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256
typedef struct {
    int shi;
    int bo;
} Bunsuu;

void keisan(Bunsuu *p, Bunsuu *q, Bunsuu *r) {
    r->shi = p->shi * q->bo + p->bo * q->shi;
    r->bo = p->bo * q->bo;
    return;
}

int main() {
    int ret;
    char input[MAXLINE];
    Bunsuu a,b,c;

    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &a.shi, &a.bo);
    if (ret != 2) {exit(1);}
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &b.shi, &b.bo);
    if (ret != 2) {exit(1);}

    keisan(&a, &b, &c);
    printf("%d/%d + %d/%d = %d/%d\n",
        a.shi, a.bo, b.shi, b.bo, c.shi, c.bo);
    exit(0);
}