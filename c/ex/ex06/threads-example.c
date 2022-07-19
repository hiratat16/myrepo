/* threads-example.c */
/* 3つのスレッドを生成し, それぞれが, 2秒, 3秒, 5秒間隔で回数を記録する変数
count を 1 ずつ増やしていく.
1番目のスレットは, 最初表示後, 2,4,6,8 秒後に表示を行い
2番目のスレッドは, 3,6,9,12 秒後に表示を行い,
3番目のスレッドは, 5,10,15,20 秒後に表示を行う */
#include <pthread.h> /* スレッドの利用の宣言 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 3
int param[NUM_THREADS] = {2,3,5};

void *do_work(void *); /* スレッドが実行する関数の宣言 */

int i;
pthread_t tid[NUM_THREADS]; /* スレッドIDを保持する配列 */

int main() {
    /* スレッドの生成 */
    pthread_create(&tid[0], NULL, do_work, &param[0]);
    pthread_create(&tid[1], NULL, do_work, &param[1]);
    pthread_create(&tid[2], NULL, do_work, &param[2]);
    /* スレッドの終了を待つ */
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }
    printf("all threads terminated\n");
    return (0);
}

void *do_work(void *arg) {
    int j, *sleep_time;
    sleep_time = arg;
    for (j = 0; j < 5; j++) {
        printf("Thread %ld:%d\n", (long)pthread_self(), j);
        sleep(*sleep_time);
    }
    return (NULL);
}