/* 練習問題4.2 */
/* 練習問題4.1とほとんど同じですが,自己参照構造体を使ってキーワードとなる単語と
その意味(中身)を登録するプログラムを作りましょう.キーワードとその中身に対して
mallocでメモリ領域を確保する必要があります */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 256
typedef struct list {
    struct list *next;
    char *name;
    char *meaning;
} list;
int main() {
    char input[MAXLINE]; char meaning[MAXLINE];
    char *s;
    list *p, *q, *r;
    p = NULL; q = NULL;
    for (;;) {
        printf("Please input Keyword:\n");
        if (fgets(input, MAXLINE, stdin) == NULL) {
        break;
        } 
        s = strchr(input, '\n');
        if (s != NULL) {
        *s = '\0';
        }
        printf("Please input meaning\n");
        if (fgets(meaning, MAXLINE, stdin) == NULL) {
        break;
        } 
        s = strchr(meaning, '\n');
        if (s != NULL) {
        *s = '\0';
        }
        r = malloc(sizeof(list));
        r->name = malloc(sizeof(char)*(strlen(input)+1));
        strcpy(r->name, input);
        r->meaning = malloc(sizeof(char)*(strlen(meaning)+1));
        strcpy(r->meaning, meaning);
        r->next = NULL;
        if (q != NULL) {
            q->next = r;
            q = r;
        } else {
            q = r;
            p = q;
        }
    }
    for (q = p; p != NULL; q = q->next) {
        printf("Keyword: %s\nMeaning: %s\n", 
            q->name, q->meaning);
    }
}