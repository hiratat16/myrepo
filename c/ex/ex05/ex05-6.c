/* 練習問題5.6 */
/* catコマンドの機能を調べて,同じ動作をするプログラムを作りなさい.
まずは次のような機能があります.
・cat file1, file2 ... のように複数のファイルをつなぎあわせる(concatenate)機能
・引数がなかった場合にファイルではなく標準入力から読み込む機能 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define DATASIZE 8192
int main(int argc, char *argv[]) {
    char data[DATASIZE];
    int i, fd, cc;
    // 引数が無い場合ファイルではなく標準入力から読み込む機能
    if (argc == 1) {
        for(;;) {
            if (fgets(data, DATASIZE, stdin) == NULL) {
                exit(0);
            } 
        }
    }
    // 引数が一つの場合, ファイルの中身を読み込んで表示
    if (argc > 1) {
        for (i = 0; i < argc; i++) {
            fd = open(argv[i], O_RDWR);
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
            for(i = 0; i < argc; i--) {
                cc = read(fd, data, DATASIZE);
                if (cc == 0) {
                    break;
                }
                write(1, data, cc);
                printf("\n");
            }
        }   
    }
    close(fd);
    return 0;
}