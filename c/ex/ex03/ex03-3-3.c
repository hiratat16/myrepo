#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct data {
    char item;
    struct data *next;
    struct data *back;
} DATA;

// 開始ポインター
DATA start;

/*---------- 最後のデータを取得する ----------*/
DATA *get_last_data(void) {
    DATA *p = &start;
    while (p->next != NULL) {
        p = p->next;
    }
    return p;
}
/*---------- リストの最後へデータを登録する ----------*/
void push_data(char item) {
    DATA *last;
    DATA *p = malloc(sizeof(DATA));
    if (p == NULL) {
        printf("malloc error\n");
        exit(10);
    }
    // 最後のデータ取得
    last = get_last_data();
    // nextの付け替え
    last->next = p;
    // 最後のデータ登録
    p->item = item;
    p->next = NULL;
    p->back = last;
}

/*---------- リストの最後へデータを取り出す ----------*/
char pop_data(void) {
    char item;
    DATA *last;
    DATA *prev;
    last = get_last_data();
    // 1つ前のデータのnextをNULLに設定
    item = last->back;
    prev->next = NULL;
    // 最後のデータを解放
    free(last);
    return item;
}

int main(void) {
    char buff[4096];
    int i;
    int len;
    char item;
    int hantei = 1;

    /*----- リストの開始設定 -----*/
    start.next = NULL;
    start.back = NULL;
    start.item = NULL;
    printf("Input data=>");
    gets(buff);
    len = strlen(buff);
    // 先頭から1文字ずつスタックに登録
    for (i = 0; i < len; i++) {
        push_data(buff[i]);
    }
    // 先頭から順に1文字ずつ取り出し, 比較する文字をスタックから1文字ずつ取り出す
    for (i = 0; i < len; i++) {
        item = pop_data();
        // 文字が不一致なら回文でない
        // if (toupper(buff[i]) != toupper(item))
        if (buff[i] != item) {
            hantei = 0;
            break;
        }
    }
    if (hantei == 1) {
        printf("palindrome\n");
    }
    else {
        printf("not palindrome\n");
    }
    return 0;
}
