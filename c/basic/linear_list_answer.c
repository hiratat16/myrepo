/* 練習問題4.1に関して,次のようなプログラムを作成してください.
また,コメント行で,動作を説明し,とくに自己参照構造体でどのように,
任意の行数を順番に処理しているかを記述してください. 

・プログラムを動作させ, キーボードから何行か入力して最後にcontrol-dを入力すると,
入力された文字列がそのまま入力した行の順番に表示される
% ./train05
ABC
123
^D
ABC
123
%
・1行入力はfgetsを用い,行末の改行文字(\n)は,テキストの例のように,strchr()
を用いて検出し,取り除いてから処理する 
・control-dの検出は,fgets()の返り値をNULLと比較して行う
char *p;
...
for(;;) {
    p = fgets(...);
    if (p == NULL){ break; }
} */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024 // 入力できる最大の文字列

// リスト構造のための構造体の定義

struct list {
    struct list *next; // 次のリストを示すポインタ
    char *name; // データを格納するポインタ
};

int main() {

    // p は,常にリスト構造の先頭を示し,最初にmallocの戻り値を代入された後は,変更されない
    // q,r は,リスト構造の連結に使われるため,書き換わる

    struct list *p, *q, *r;
    char input[MAXLINE];
    int *s, *t;
    // int len;

    // リストの先頭を最初 NULL ポインタにしておく
    p = NULL;
    // 順番に動かすポインタ q を NULL にしておく
    q = NULL;

    // fgets で control-D が入力されるまで繰り返し
    for (;;) {
        t = fgets(input, MAXLINE, stdin);
        // control-D が入力されたら break で繰り返しを抜け出す
        if (t == NULL) {
        break;
        }
    }

    // 行末の改行文字を終端文字に置き換える
    s = strchr(input, '\n');
    if (s != NULL) {
        *s = '\0';
    }

    // list 構造体の記憶場所を確保
    r = malloc(sizeof(struct list));
    if (r == NULL) {
        printf("メモリが確保できません\n");
        exit(EXIT_FAILURE);
    }

    // 入力された文字列を入れる記憶場所の確保し複製する
    r -> name = malloc(sizeof(char)*(strlen(input)+1));
    if (r -> name == NULL) {
        return EXIT_FAILURE;
    }

    strcpy(r -> name, input);

    r -> next = NULL;

    // q が NULL でなければ, つまり2回目以降の繰り返しだったら
    // 現在の q の次に, 新たに確保した r を付け足す
    // q が NULL ならば, 1回目の繰り返しなので, r をそのまま q にして
    // それを q にも入れる
    // q は繰り返しの度に変化するので, 最初がどこかを覚えておかないと
    // 後で辿れなくなる
    if (q != NULL) {
        q -> next = r;
        q = r;
    } else {
        q = r;
        p = q;
    }
    // 入力された文字列の表示
    for (q = p; q != NULL; q = q -> next) {
        printf("%s\n", q -> name);
    }
}

/* 練習問題4.1 */
/* 自己参照構造体を使って単語を登録するプログラムを作りなさい.
whileまたはforを使って繰り返しの中でfgetsを使って単語を入力します.
Control-D(キーボードでCtrlあるいはControlキーを押しながらdのキーを押して入力します)
が入力されたら繰り返しから抜け出し,登録した単語を順番に表示します.あらかじめ繰り返しの数が
分かっていないので,動的にメモリを確保する必要があります.Control-Dが入力されると,fgetsは
ファイル(標準入力)が終わりになったと判断し,NULLポインタを返すので,それによって入力の終了を
プログラム中で検出できます */