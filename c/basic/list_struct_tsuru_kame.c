/*------------------------------------------------------- 
問題
次のような仕様で、つるかめ算の答えを求めるプログラムを作成してください。

main()とsolve()の2つの関数だけを定義する
solve()は、次のようなプロトタイプ宣言にしたがうものとする
int solve(unsigned int atama, unsigned int ashi, struct kotae *p);
int solve()は、次のようなstruct kotae型の構造体につるかめ算の答えを入れる。
また、答えが見つかった場合には1を返し、見つからなかった場合には、0を返す。main()の中ではこの戻値を判定して、適切な表示を行う
struct kotae {
  unsigned int tsuru;
  unsigned int kame;
};
最初の頭と足の数の入力は、標準入力から、10,24 のように1行で入力し、
fgetsで読み込んだ後、sscanf()で解析する
------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 265

struct kotae {
    unsigned int tsuru;
    unsigned int kame;
};

int solve(unsigned int atama, unsigned int ashi, struct kotae *p);


int main() {
    int ret;
    char input[MAXLINE];
    unsigned int atama, ashi;
    struct kotae a;


    // 標準入力から頭と足の数の入力 (10, 24のように1行で入力)
    fgets(input, MAXLINE, stdin);
    // fgest() で読み込んだ文字列を,変換指定文字(%d:10進数)に変換後,
    // 変数atama, ashi のアドレスに入力データを格納
    ret = sscanf(input, "%d,%d", &atama, &ashi);


    // solve()の答えば見つかった場合 (戻り値が 1 の場合)
    if(solve(atama, ashi, &a) == 1){
        printf("tsuru=%d\n", a.tsuru);
        printf("tsuru=%d\n", a.kame);
    }
    else{
        printf("ERROR\n");
    }
    
    exit(0);
}

// 計算
int solve(unsigned int atama, unsigned int ashi, struct kotae *p){

    p->kame = (ashi / 2) - atama;
    p->tsuru = atama - p->kame;

    if ((atama == p->kame + p->tsuru) && (ashi == 2 * p->tsuru + 4 * p->kame)) {
        return 1;
    } else {
        return 0;
    }

    if (p->kame || p->tsuru < 0) {
        exit(EXIT_FAILURE);
    }

    return 0;

}


/*
次のように、表示がおかしい場合があります 
%./kadai4 10,16 tsuru=12 tsuru=-2
適切なError処理を書きなさい.

構造体ポインタの初期化:
struct Number *p = mallloc(sizeof(struct Number));
p->value = 9; //初期化
https://marycore.jp/prog/c-lang/declare-struct/
*/