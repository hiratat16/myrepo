/* 練習問題4.1 */
/* 自己参照構造体を使って単語を登録するプログラムを作りなさい.
whileまたはforを使って繰り返しの中でfgetsを使って単語を入力します.
Control-D(キーボードでCtrlあるいはControlキーを押しながらdのキーを押して入力します)
が入力されたら繰り返しから抜け出し,登録した単語を順番に表示します.あらかじめ繰り返しの数が
分かっていないので,動的にメモリを確保する必要があります.Control-Dが入力されると,fgetsは
ファイル(標準入力)が終わりになったと判断し,NULLポインタを返すので,それによって入力の終了を
プログラム中で検出できます */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 256
typedef struct list {
    struct list *next;
    char *name;
} list;
int main() {
    char input[MAXLINE];
    // pは常にリスト構造の先頭を示し,最初にmallocの戻り値を代入された後は,変更されない
    // q,rは,リスト構造の連結に使われるため,下記かわる
    list *p, *q, *r;
    char *s;

    // リストの先頭を最初NULLポインタにしておく
    p = NULL;
    // 順番に動かすポインタqをNULLにしておく
    q = NULL;
    // fgetsでcontrol-Dが入力されるまで繰り返し
    for(;;) {
        if (fgets(input, MAXLINE, stdin) == NULL) {
            break;
        }
        // 行末の改行文字を終端文字に置き換える
        s = strchr(input, '\n');
        if (s != NULL) {
            *s = '\0';
        }
        // list構造体の記憶場所を確保
        // 以下,malloc()がNULLを返したときのエラー処理は省略
        r = malloc(sizeof(list));
        // 入力された文字列を入れる記憶場所を確保し複製する
        r->name = malloc(sizeof(char)*(strlen(input)+1));
        strcpy(r->name, input);
        r->next = NULL;
        // qがNULLでなければ, つまり2回目以降の繰り返しだったら,
        // 現在のqの次に,新たに確保したrを付け足す
        // qがNULLならば,1回目の繰り返しなので,rをそのままqにして
        // それをpにも入れる
        // qは繰り返しのたびに変化するので,最初がどこかを覚えておかないと
        // 後でたどれなくなる
        if (q != NULL) {
            q->next = r;
            q = r;
        } else {
            q = r;
            p = q;
        }
    }
    // 入力された文字列の表示
    for (q = p; q != NULL; q = q->next) {
        printf("%s\n", q->name);
    }
}