/* 練習問題3.8 */
/* 第2回の分数の四則演算の結果を表す練習問題2.7で, 加算, 減算, 乗算, 除算を
それぞれ関数にし, それらの関数を構造体へのポインタをわたして呼び出すようにし,
四則演算の結果を四つともすべて示すプログラムを作りなさい */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

typedef struct {
    int shi;
    int bo;
} Bunsuu;

void Add(Bunsuu *p, Bunsuu *q, Bunsuu *r) {
    r->shi = p->shi * q->bo + p->bo * q->shi;
    r->bo = p->bo * q->bo;
    return;
}
void Sub(Bunsuu *p, Bunsuu *q, Bunsuu *r) {
    r->shi = p->shi * q->bo - p->bo * q->shi;
    r->bo = p->bo * q->bo;
    return;
}
void Mul(Bunsuu *p, Bunsuu *q, Bunsuu *r) {
    r->shi = p->shi * q->shi;
    r->bo = p->bo * q->bo;
    return;
}
void Div(Bunsuu *p, Bunsuu *q, Bunsuu *r) {
    r->shi = p->shi * q->bo;
    r->bo = p->shi * q->bo;
    return;
}

int main() {
    char input[MAXLINE];
    int ret;
    Bunsuu a, b;
    Bunsuu add, sub, mul, div;

    printf("1つ目の分数を入力して下さい(例1/4)\n");
    if (fgets(input, MAXLINE, stdin) == NULL) {
        *input = '\0';
    }
    ret = sscanf(input, "%d/%d", &a.shi, &a.bo);
    if (ret != 2) {exit(0);}
    printf("2つ目の分数を入力して下さい(例1/4)\n");
    if (fgets(input, MAXLINE, stdin) == NULL) {
        *input = '\0';
    }
    ret = sscanf(input, "%d/%d", &b.shi, &b.bo);
    if (ret != 2) {exit(0);}

    Add(&a, &b, &add);
    // while(1) {
    //     int tmp;
    //     tmp = add.bo % add.shi;
    //     if (tmp == 0)
    //     add.bo = add.shi;
    //     add.shi = tmp;
    // }
    Sub(&a, &b, &sub);
    // if (sub.shi == 0) { printf("0\n"); } 
    // else {
    //     while(1) {
    //     int tmp;
    //     tmp = sub.bo % sub.shi;
    //     if (tmp == 0)
    //     sub.bo = sub.shi;
    //     sub.shi = tmp;
    //     }
    // }
    Mul(&a, &b, &mul);
    // while(1) {
    //     int tmp;
    //     tmp = mul.bo % mul.shi;
    //     if (tmp == 0)
    //     mul.bo = mul.shi;
    //     mul.shi = tmp;
    // }
    Div(&a, &b, &div);
    // while(1) {
    //     int tmp;
    //     tmp = div.bo % div.shi;
    //     if (tmp == 0)
    //     div.bo = div.shi;
    //     div.shi = tmp;
    // }

    printf("足し算: %d/%d\n", add.shi, add.bo);
    printf("引き算: %d/%d\n", sub.shi, sub.bo);
    printf("掛け算: %d/%d\n", mul.shi, mul.bo);
    printf("割り算: %d/%d\n", div.shi, div.bo);

    exit(0);
}

/* 練習問題2-7 */
/* 構造体の例題で, 分数の加算プログラムを示しましたが, 
減算, 乗算, 除算も計算し, 四則演算の結果を四つともすべて示す
プログラムを作成しなさい */

/* 構造体の例題 */
/*
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
*/