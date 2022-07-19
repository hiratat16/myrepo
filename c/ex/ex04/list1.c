/* list1.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    list *p;
    char *next;
} list;

int main() {
    list *p, *q;

    p = malloc(sizeof(list));
    p->name = malloc(sizeof(char)*6);
    strcpy(p->name, "START");
    q = malloc(sizeof(list));
    p->next = q;
    q->next = NULL;
    q->name = malloc(sizeof(char)*4);
    strcpy(q->name, "END");
    exit(0);
}