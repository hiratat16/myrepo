/* structure-frac.c */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256
struct frac {
    int shi;
    int bo;
};
int main() {
    int ret;
    char input[MAXLINE];
    struct frac f, g, h;

    printf("分数を入力して下さい\n");
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d\n", &f.shi, &f.bo);
    if (ret != 2) {exit(1);}
    printf("分数を入力して下さい\n");
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d\n", &g.shi, &g.bo);
    if (ret != 2) {exit(1);}

    h.shi = f.shi * g.bo + g.shi * f.bo;
    h.bo = f.bo * g.bo;
    printf("%d/%d + %d/%d = %d/%d\n", f.shi, f.bo, g.shi, g.bo, h.shi, h.bo);
    exit(0);
}