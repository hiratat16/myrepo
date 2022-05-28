#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#define MAXLINE 1024

// リスト構造のための構造体の定義

struct list {
  struct list *next;
  char *name;
};

int main(){
  //
  // pは、常にリスト構造の先頭を示し、最初にmallocの戻り値を代入された後は、変更されない
  // q,rは、リスト構造の連結に使われるため、書き換わる
  struct list *p, *q, *r;

  char input[MAXLINE];
  char *s, *t;

  // リストの先頭を最初NULLポインタにしておく
  p = NULL;
  // 順番に動かすポインタqをNULLにしておく
  q = NULL;
  // fgetsでcontrol-Dが入力されるまで繰り返し
  for(;;){
    t = fgets(input,MAXLINE,stdin);
    // control-Dが入力されたら break で繰り返しを抜け出す
    if(t == NULL){
      break;
    }
    // 行末の改行文字を終端文字に置き換える
    s = strchr(input,'\n');
    if(s!=NULL){
      *s = '\0';
    }
    // list 構造体の記憶場所を確保
    // 以下、malloc()がNULLを返したときのエラー処理は省略
    r = malloc(sizeof(struct list));
    // 入力された文字列を入れる記憶場所を確保し複製する
    r->name = malloc(sizeof(char)*(strlen(input)+1));
    strcpy(r->name,input);
    r->next = NULL;
    // qがNULLでなければ、つまり2回目以降の繰り返しだったら
    // 現在のqの次に、新たに確保したrを付け足す
    // qがNULLならば、1回目の繰り返しなので、rをそのままqにして
    // それをpにも入れる
    // qは繰り返しのたびに変化するので、最初がどこかを覚えておかないと
    // 後でたどれなくなる
    if(q != NULL){
      q->next = r;
      q = r;
    }else{
      q = r;
      p = q;
    }
  }
  // 入力された文字列の表示
 for(q = p; q != NULL; q = q->next){
    printf("%s\n",q->name);
  }
}