/* struct-p.c */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

typedef struct {
    int shi;
    int bo;
}Bunsuu;
Bunsuu keisan(Bunsuu p, Bunsuu q) {
    Bunsuu r;
    r.shi = p.shi * q.bo + p.bo * q.shi;
    r.bo = p.bo * q.bo;
    return r;
}
int main(void) {
    int ret;
    char input[MAXLINE];
    Bunsuu a, b, c;
    printf("1つ目の分数を入力して下さい\n");
    if (fgets(input, MAXLINE, stdin) == NULL) {
        *input = '\0'; 
    }
    ret = sscanf(input, "%d/%d", &a.shi, &a.bo);
    if (ret != 2) { (exit(0)); }
    printf("2つ目の分数を入力して下さい\n");
    if (fgets(input, MAXLINE, stdin) == NULL) {
        *input = '\0'; 
    }
    ret = sscanf(input, "%d/%d", &b.shi, &b.bo);
    if (ret != 2) { (exit(0)); }
    c = keisan(a, b);
    printf("%d/%d + %d/%d = %d/%d\n", a.shi, a.bo, b.shi, b.bo, c.shi, c.bo);
    return 0;
}
