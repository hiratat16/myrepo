/* 練習問題02-5.c */
/* 構造体の例題(structure-frac.c)で, 分数の加算プログラムを示しましたが,
このプログラムを構造体を使わないで書き直しなさい */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256
int main() {
    int ret;
    int fir_shi, fir_bo;
    int sec_shi, sec_bo;
    int res_shi, res_bo;
    char input[MAXLINE];

    printf("分数を入力して下さい\n");
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &fir_shi, &fir_bo);
    if (ret != 2) {exit(1);}
    printf("分数を入力して下さい\n");
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &sec_shi, &sec_bo);
    if (ret != 2) {exit(1);}

    res_shi = fir_shi * sec_bo + sec_shi * fir_bo;
    res_bo = fir_bo * sec_bo;

    printf("%d/%d + %d/%d = %d/%d\n",
        fir_shi, fir_bo,
        sec_shi, sec_bo,
        res_shi, res_bo);
}


/* structure-frac.c */
/* #include <stdio.h>
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
} */