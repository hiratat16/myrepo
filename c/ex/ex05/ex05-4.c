/* 練習問題5.4 */
/* コマンド引数にファイル名を2個指定して, どちらのファイルが大きいかを表示する
プログラムを作りなさい. statシステムコールを使えば, 指定されたファイルの大きさ
を直接調べられますが, ここでは, ファイルを全部読み込んで何バイトあるか数える
方法で構いません. */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define BUF_SIZE 512
int main(int argc, char *argv[]) {
    int fd1, fd2;
    char a[BUF_SIZE], b[BUF_SIZE];
    if (argc > 3) {
        printf("入力がおかしいです\n");
        exit(1);
    }
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);
    if (fd1 == -1 || fd2 == -1) {
        if (errno == ENOENT) {
            fprintf(stderr, "No such file.\n");
        } else if (errno == EACCES) {
            fprintf(stderr, "Access Error.\n");
        } else {
            fprintf(stderr, "Error No = %u.\n", errno);
        }
        exit(1);
    }
    read(fd1, a, BUF_SIZE);
    read(fd2, a, BUF_SIZE);

    if (strlen(a) > strlen(b)) {
        printf("%sより%sの方が大きいです\n", argv[1], argv[2]);
    } else {
        printf("%sより%sの方が大きいです\n", argv[2], argv[1]);
    }
    return -1;
}