/* sem-count.c */
/* 共有メモリに1を10回加算するプログラムで,2つ同時に動作させると結果が20になる
はずだが, 排他制御しないと, 結果が小さくなる */
#define _GNU_SOURCE
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    int fd_shm, ret, i;
    const char *shm_name = "semtest";
    long *shm_data;

    // 共有メモリオブジェクト作成
    fd_shm = shm_open(shm_name, O_CREAT|O_RDWR, 0600);
    if (fd_shm == -1) {
        perror("shm_open");
        exit(1);
    }
    // long型の領域を指定
    ret = ftruncate(fd_shm, sizeof(long));
    if (ret == -1) {
        perror("ftruncate");
        exit(1);
    }
    printf("ret = %d\n", ret);
    // 変数shm_dataに対応づけ
    shm_data = mmap(NULL, sizeof(long), 
    PROT_READ|PROT_WRITE, MAP_SHARED, fd_shm, 0);
    if (shm_data == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    if (*shm_data <= 0) {
        *shm_data = 0;
    }
    printf("data = %ld\n", *shm_data);
    for (i = 0; i < 10; i++) {
        long temp;
        // 共有メモリから読み込み
        temp = *shm_data + 1;
        // 同期ずれを起こす待ち(0-2秒)
        sleep(random()%3);
        // 待ち時間の後書き込み
        printf("data = %ld\n", temp);
        *shm_data = temp;
    }
    // オブジェクトを削除
    shm_unlink(shm_name);
}