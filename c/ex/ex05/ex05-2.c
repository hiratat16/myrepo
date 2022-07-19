/* 練習問題5.2 */
/* 入力されたファイル名がそのディレクトリにあるかどうか調べるプログラムを作りなさい.
openしてみて,エラーの値を調べるというのが一つの方法です.
statシステムコールを使う方法がファイルの属性を調べる方法としては普通なので,
余裕のある人は, オンラインマニュアルで調べてstatシステムコールを使ってみよう */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char *argv[]) {
    int fd;
    if (argc != 2) {
        exit(1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        if (errno == ENOENT) {
            fprintf(stderr, "No such file.\n");
        } else if (errno == EACCES) {
            fprintf(stderr, "Access Error.\n", errno);
        } else {
            fprintf(stderr, "Error No = %u.\n", errno);
        }
        exit(1);
    }
    fclose(fd);
    exit(0);
}