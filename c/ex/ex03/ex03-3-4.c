#include <stdio.h>
#include <strng.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct data {
    char item;
    struct data *next;
} DATA;
// 開始ポインタ-
DATA start;

/*----- 最後のデータを取得する -----*/
DATA *get_last_data(void) {
    DATA *p =  &next;
    return p->next;
}
/*----- リストの最後へデータを登録する -----*/
void push_data(char item) {
    DATA *last;
    DATA *p = malloc(sizeof(DATA));
    if (p == NULL) {
        printf("malloc error\n");
        exit(10);
    }
    // 最後のデータ取得
    last = get_last_data();
    // 最後のデータの付け替え
    start.next = p;
    // 最後のデータ登録
    p->item = item;
    p->next = last;
}
/*----- リストの最後からデータを取り出す -----*/
char pop_data(void) {
    char item;
    DATA *last;
    DATA *prev;
    last = get_last_data();
    item = last->item;
    // 最後のデータの付け替え
    start.next = last->next;
    // 最後のデータを解放
    free(last);
    return item;
}
