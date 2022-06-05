#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 512

int main(int argc, char *argv[]){

    char buf[BUF_SIZE];
    int fd;
    int r, w;
    
    // argc による判定 (引数が指定されていない場合)
    if (argc < 2) {
        printf("Usage: command [file-name]\n");
        return 0;
    }
    
    // ファイルをopen()関数の読み書き両用でオープンする
    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror("open(): "); // ファイルのopenに失敗した場合
        exit(EXIT_FAILURE);
    } 

    else {
        // 繰り返しの中で 0 (ファイルを読み終わるまで) になるまでデータを読み込む
        while ((r = read(fd, buf, BUF_SIZE)) != 0){
            if (r == -1) {
                printf("ファイル読み込みエラー");
                exit(EXIT_FAILURE);
            }

            // printf("%d\n", r);

            // 標準出力に書き出す
            w = write(STDOUT_FILENO, buf, r);
            if (w == -1) { // ファイル書き込み失敗
                printf("ファイル書き込みエラー\n");
                exit(EXIT_FAILURE);
            }
            
            // printf("%d\n", w);
        }
    }
    
    // ファイルを閉じる
    close(fd);

    return 0;
        
}