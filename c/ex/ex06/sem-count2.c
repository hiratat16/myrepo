/* sem-count2.c */
#define _GNU_SOURCE
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>   /* mode 定数用 */
#include <fcntl.h>  /* O_* 定数の定義用 */
#include <semaphore.h>
#include <errno.h>

int main() {
    int fd_shm, ret, i;
    const char *shm_name = "semtest";
    long *shm_data;
    const char *mutex_name = "mysemaphore";
    sem_t *mutex;

    // セマフォ作成
    mutex = sem_open(mutex_name, O_CREAT, 0600, 1);
    if (mutex == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }
    // 共有メモリオブジェクト作成
    fd_shm = shm_open(shm_name, O_CREAT|O_RDWR, 0600);
    if (fd_shm == -1) {
        perror("shm_open");
        exit(1);
    }
    // long型の領域を設定
    ret = ftruncate(fd_shm, sizeof(long));
    if (ret == -1) {
        perror("ftruncate");
        exit(1);
    }
    // 変数shm_dataに対応付け
    shm_data = mmap(NULL, sizeof(long),
                PROT_READ|PROT_WRITE,
                MAP_SHARED, fd_shm, 0);
    if (shm_data == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    // ロック獲得
    // mutexの値が0だったら待つ
    // 0より大きえれば1減らして処理を続ける
    sem_wait(mutex);
    if(*shm_data <= 0) {
        *shm_data = 0;
    }
    // ロック解除
    // mutexの値を１増やす
    sem_post(mutex);

    printf("data = %ld\n", *shm_data);
    for (i = 0; i < 10; i++) {
        long temp;
        // ロック
        sem_wait(mutex);
        // 共有メモリから読み込み
        temp = *shm_data + 1;
        // 同期ずれを起こす待ち(0-2秒)
        sleep(random()%2);
        // 待ち時間の後書き込み
        printf("data = %ld\n", temp);
        *shm_data = temp;
        // ロック解除
        sem_post(mutex);
        // 解除後すぐに次のロックをしない
        sleep(random()%2);
    }
    // セマフォの使用を停止
    sem_unlink(mutex_name);
    // オブジェクトを削除
    shm_unlink(shm_name);
}