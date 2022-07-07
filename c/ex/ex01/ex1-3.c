/* 練習問題1.3 */
/* 鶴亀算を実行するプログラムを作りなさい */
#include <stdio.h>
#include <stdlib.h>

int main() {

    int tsuru, kame;
    int ashi, atama;

    printf("頭の数を入れてください\n");
    scanf("%d", &atama);
    printf("足の数を入れてください\n");
    scanf("%d", &ashi);

    kame = (ashi / 2) - atama;
    tsuru = atama - kame;

    if((kame + tsuru == atama) && (kame * 4 + tsuru * 2) && (kame >= 0) && (tsuru >= 0)) {
        printf("tsuru = %d\n", tsuru);
        printf("kame = %d\n", kame);
    } 
    else {
        printf("Error\n");
    }
    return 0;
}