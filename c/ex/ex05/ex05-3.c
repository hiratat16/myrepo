/* 練習問題5.3 */
/* コマンド引数にファイル名を指定して, その内容を標準出力に出すプログラムを作りなさい.
ファイルからの読み込みと, 標準出力への書き出しが必要です.
読み込むファイルの大きさは分からないので, 少し読み込んでは, 少し書き出すという
処理が必要です. */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#define DATASIZE 8192
int main(int argc, char *argv[]) {
    int fd, cc;
    char data[DATASIZE];

    if (argc < 2) {
        fprintf(stderr,"ファイル名が指定されていません\n");
        return 1;
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        if (errno == ENOENT) {
            fprintf(stderr, "No such file.\n");
        } else if (errno == EACCES) {
            fprintf(stderr, "Access Error.\n");
        } else {
            fprintf(stderr, "Error No = %u.\n", errno);
        }
        exit(0);
    }
    for (;;) {
        cc = read(fd, data, DATASIZE);
        if (cc == 0) {
            break;
        }
        write(1, data, cc);
        printf("\n");
    }
    return 0; 
}