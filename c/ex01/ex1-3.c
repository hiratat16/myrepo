//鶴亀算

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