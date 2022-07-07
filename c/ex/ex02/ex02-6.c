/* 練習問題2-6 */
/* 構造体の例題で, 分数の加算プログラムを示しましたが, 
2/5 + 2/5 が 20/25 になって, 4/5 になりません.
既約分数で計算結果が表示されるプログラムを作りなさい. 
約分するにはどうすればいいかを考えましょう. */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

struct frac {
    int shi;
    int bo;
    int tmp;
};

int main() {
    struct frac f, g, h;
    char input[MAXLINE];
    int ret;

    printf("1つ目の分数を入力して下さい\n");
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &f.shi, &f.bo);
    if (ret != 2) {exit(0);}
    printf("2つ目の分数を入力して下さい\n");
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &g.shi, &g.bo);

    h.shi = f.shi * g.bo + g.shi * f.bo;
    h.bo = f.bo * g.bo;

    printf("---------- 約分前 ----------\n");
    printf("%d/%d + %d/%d = %d/%d\n",
        f.shi, f.bo,
        g.shi, g.bo,
        h.shi, h.bo);

    // 最大公約数を求める, 分子,分母を最大公約数の値で割る.
    while (1) {
        h.tmp = h.bo % h.shi;
        if (h.tmp == 0) break;
        h.bo = h.shi;
        h.shi = h.tmp;
    }

    printf("---------- 約分後 ----------\n");
    printf("%d/%d + %d/%d = %d/%d\n",
        f.shi, f.bo,
        g.shi, g.bo,
        h.shi/h.shi, h.bo/h.shi);

    exit(0);
}

/* 構造体の例題 */
/* structure-frac.c */
/*
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
*/
