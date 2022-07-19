/* 練習問題5.5 */
/* random関数を使って乱数列を作成し,
乱数10,000個が書かれたファイルを作成するプログラムを作りなさい 
random関数および乱数の扱いについては,付録を参照してください*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    int i, num;

    /* Open File */
    fp = fopen("rand", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open rand\n");
        exit(1);
    }
    for (i = 0; i < 100; i++) {
        num = rand() % 10;
        if (fwrite(&num, sizeof(int), 1, fp) != 1) {
            fprintf(stderr, "Write error.\n");
            exit(1);
        }
    }
    fclose(fp);
}

// #define _GNU_SOURCE
// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <errno.h>
// #include <string.h>
// #include <unistd.h>
// #define MAXLEN 100
// int main() {
//     int fd;
//     int data[MAXLEN];
//     int byte_num;

//     FILE *fd = fopen("random", O_WRONLY|O_CREAT, 0644);
//     if (fd == -1) {
//         if (errno == ENOENT) {
//             fprintf(stderr, "No such file.\n");
//         } else if (errno == EACCES) {
//             fprintf(stderr, "Access Error.\n");
//         } else {
//             fprintf(stderr, "Error No = %u.\n", errno);
//         }
//     }
//     for (int i = 0; i < 10; i++) {
//         data[i] = random() % 10 + 1;
//         printf("%d\n", data[i]);
//         byte_num = write(fd, &data[i], 10);
//         if (byte_num == -1) {
//             fprintf(stderr, "ファイル書き込みエラー\n");
//             exit(1);
//         }
//     }
    
//     fprintf(stdout, "ファイルに%dバイト書き込みました\n", byte_num);
//     data[byte_num] = '\0';
//     for (int i = 0; i < 10; i++) {
//         fprintf(stdout, "書き込んだ文字列:%d\n", data[i]);
//     }
    
//     close(fd);
//     exit(0);
// }