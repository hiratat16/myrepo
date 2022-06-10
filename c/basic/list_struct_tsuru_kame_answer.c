#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 256

// 答えを入れる構造体の定義
struct kotae {
  unsigned int tsuru;
  unsigned int kame;
};

// 答えを求める関数の定義
int solve(unsigned int atama, unsigned int ashi, struct kotae *p) {

  // 頭と足の組み合わせががおかしい場合を調べて0を返す
  if(atama * 4 < ashi || ashi < atama * 2 || ashi % 2 != 0) {
    return 0;
  }
  // 答えば求まる場合にその答えを計算して, 構造体に入れて 1 を返す
  p->kame = (ashi - atama*2)/2;
  p->tsuru = atama - p->kame;
  return 1;
}

int main() {
  int ret;
  char input[MAXLINE];
  int atama, ashi;
  struct kotae tk;

  // メッセージを表示して1行入力する
  // fgets()の返す値を無視するのでvoid型に明示的にキャストする
  (void)fgets(input, MAXLINE, stdin);

  // sscanf()で,区切りの整数値を入力
  // 負の値が入力された場合などは調べていない
  ret = sscanf(input, "%d,%d", &atama, &ashi);
  if (ret =! 2) {
    printf("入力が正しくありません\n");
    return -1;
  } 

  printf("頭%u, 足%u\n", atama, ashi);
  // retに代入せずif()の中に直接solve()を書く方法もある
  if(ret == 0) {
    printf("答えは計算できません.\n");
  } else {
    printf("つる%u匹,かめ%u匹です.\n", tk.tsuru, tk.kame);
  }
  return 0;

}

/* 問題
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
*/