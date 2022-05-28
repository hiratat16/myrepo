#include <stdio.h>

// プロトタイプ宣言
int change(int n, int k);

int main() {
    int i;
    int ret;

    // 支払う金額を1円から200円まで1円刻みで繰り返す
    for (i = 1; i <= 200; i++) {
    // for (i = 0; i <= 200; i++) {

        // ret = change(i, 1);
        ret = change(i, 100);
        printf("%d円 = %d通り\n", i, ret);

    }
}

int change(int n, int k) {

    if (n < 0) {
        return 0;
    }
    if (k == 1) {
        return 1;
    }
    else if (k == 5) {
        return change(n - 5, 5) + change(n, 1);
    }
    else if (k == 10) {
        return change(n - 10, 10) + change(n, 5);
    }
    else if (k == 50) {
        return change(n - 50, 50) + change(n, 10);
    }
    else if (k == 100) {
        return change(n - 100, 100) + change(n, 50);
    }
    printf("error (k = %d)\n", k);
    return 0;

}