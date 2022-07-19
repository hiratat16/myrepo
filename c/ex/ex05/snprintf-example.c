/* snprintf-example.c */
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    char name[100];
    int i;
    for (i = 0; i <=5; i++) {
        snprintf(name, 100, "file%d", i);
        printf("Creatint %s\n", name);
        fp = fopen(fp, "%d\n", i);
        fclose(fp);
    }
    exit(0);
}