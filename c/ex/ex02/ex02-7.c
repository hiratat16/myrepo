/* 練習問題2-7 */
/* 構造体の例題で, 分数の加算プログラムを示しましたが, 
減算, 乗算, 除算も計算し, 四則演算の結果を四つともすべて示す
プログラムを作成しなさい */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

struct frac {
    int shi;
    int bo;
    int tmp;
};

int main() {
    struct frac f, g;
    char input[MAXLINE];
    int ret;

    printf("1つ目の分数を入力して下さい\n");
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &f.shi, &f.bo);
    if (ret != 2) {exit(0);}
    printf("2つ目の分数を入力して下さい\n");
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &g.shi, &g.bo);
    if (ret != 2) {exit(0);}

    // ---------- 加算 ----------
    struct frac add;
    add.shi = f.shi * g.bo + f.bo * g.shi;
    add.bo = f.bo * g.bo;
    while(1) {
        add.tmp = add.bo % add.shi;
        if (add.tmp == 0) break;
        add.bo = add.shi;
        add.shi = add.tmp;
    }
    printf("%d/%d + %d/%d = %d/%d\n", 
        f.shi, f.bo, 
        g.shi, g.bo,
        add.shi/add.shi, add.bo/add.shi);
    // ---------- 減算 ----------
    struct frac sub;
    sub.shi = f.shi * g.bo - f.bo * g.shi;
    sub.bo = f.bo * g.bo;
    if (sub.shi == 0) printf("0\n");
    else {
        while(1) {
            sub.tmp = sub.bo % sub.shi;
            if (sub.tmp == 0) break;
            sub.bo = sub.shi;
            sub.shi = sub.tmp;
        }
        printf("%d/%d - %d/%d = %d/%d\n", 
        f.shi, f.bo, 
        g.shi, g.bo,
        sub.shi/sub.shi, sub.bo/sub.shi);
    }
    
    // ---------- 乗算 ----------
    struct frac mul;
    mul.shi = f.shi * g.shi;
    mul.bo = f.bo * g.bo;
    while(1) {
        mul.tmp = mul.bo % mul.shi;
        if (mul.tmp == 0) break;
        mul.bo = mul.shi;
        mul.shi = mul.tmp;
    }
    printf("%d/%d * %d/%d = %d/%d\n", 
        f.shi, f.bo, 
        g.shi, g.bo,
        mul.shi/mul.shi, mul.bo/mul.shi);
    // ---------- 除算 ----------
    struct frac div;
    div.shi = f.shi * g.bo;
    div.bo = g.shi * f.bo;
    while(1) {
        div.tmp = div.bo % div.shi;
        if (div.tmp == 0) break;
        div.bo = div.shi;
        div.shi = div.tmp;
    }
    printf("%d/%d ÷ %d/%d = %d/%d\n", 
        f.shi, f.bo, 
        g.shi, g.bo,
        div.shi/div.shi, div.bo/div.shi);
    
    exit(0);
}