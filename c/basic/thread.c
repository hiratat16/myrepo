#include <stdio.h>
#include <string.h>
#include <pthread.h> // thread の利用の宣言

#define NUM_MAX 1000
#define NUM_THREAD 8

// param 構造体の定義
struct param {
    int sum; // 加算の和が入る変数
    pthread_mutex_t mutex; // 排他制御のためのロック用の変数
};

// thread が実行する関数の宣言
void *thread_func(void *arg){

    struct param *p = (struct param *)arg;

    for(int i=1; i <= NUM_MAX; i++){
        // mutex をロック
        pthread_mutex_lock(&p->mutex);
        p->sum += i;
        // mutex を解放する
        pthread_mutex_unlock(&p->mutex);
    }

    return NULL;

}

int main(int argc, char *argv[]){
    struct param p1;
    pthread_t t[NUM_THREAD];
    int i;

    memset(&p1, 0, sizeof(p1));
    // pthread_mutext_t 型の変数 mutex の初期化
    pthread_mutex_init(&p1.mutex, NULL);

    for(i=0; i < NUM_THREAD; i++){
        // thread_func を指定して, 新しい thread を生成
       pthread_create(&t[i], NULL, &thread_func, &p1);
    }

    for(i=0; i < NUM_THREAD; i++){
        // thread の終了を待つ
        pthread_join(t[i], NULL);
    }

    printf("%d\n", p1.sum);

    /* 答え合わせ用 *****************************************************************/
    int sum = 0;
    for(int i=1; i <= NUM_MAX; i++){
        sum += i;
    }
    printf("%d (= %d * %d)\n", sum * NUM_THREAD, sum, NUM_THREAD);
    /*****************************************************************/

    return 0;
}