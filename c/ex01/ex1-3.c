/* 1.3
小学校で鶴亀算を勉強したと思いますが,鶴亀算を実行するプログラムex1-3.cを作りましょう.
鶴と亀の数をいろいろ変えてコンパイル実行してみましょう.
*/

#include <stdio.h>

int main() {
    int tsuru, kame, head, foot;

    scanf("%d", &head);
    scanf("%d", &foot);

    kame = (foot / 2) - head;
    tsuru = head - kame;

    if((head == kame + tsuru) && (foot == 2*tsuru + 4 *kame)) {
        printf("tsuru=%d\n", tsuru);
        printf("kame=%d\n", kame);
    } else {
        printf("ERROR\n");
    }
    return 0;

}