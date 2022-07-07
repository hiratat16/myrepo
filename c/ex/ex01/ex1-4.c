/* 練習問題1.4 */
/* ある数が素数かどうかを判定するプログラムを作りなさい. */
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int i, num;

    printf("数字を入力してください\n");
    scanf("%d", &num);

    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            printf("%d は素数ではありません\n", num);
            printf("%d\n", i);
            return 1;
        }
    }
    printf("%d は素数です\n", num);
    return 0;
}