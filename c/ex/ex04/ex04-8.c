/* 練習問題4.8 */
/* 1からkara1000までの整数の素因数分解の表を作成するプログラムを作りなさい.
出力は次のようにしましょう */
#include <stdio.h>
#include <math.h>
int inputNum(void){
    int num = 0;
    while (1){
        printf("素因数分解したい整数を入力：");
        scanf("%d", &num);
        if (num < 2)
            printf("2以上の整数にしてください\n\n");
        else
            break;
    }
    return num;
}
int findFactors(int num){
    int i, cnt = 0;
    printf("%d =", num);
    while (num % 2 == 0){ // 偶数の素数は2のみ
        cnt += 1;
        num /= 2;
    }
    if (cnt > 1)
        printf(" 2^%d *", cnt);
    else if (cnt == 1)
        printf(" 2 *");
    for (i = 3; i <= sqrt(num); i += 2){ // 他の奇数で割っていく
        cnt = 0;
        while (num % i == 0){
            cnt += 1;
            num /= i;
        }
        if (cnt > 1)
            printf(" %d^%d *", i, cnt);
        else if (cnt == 1)
            printf(" %d *", i);
    }
    // ここまでで num は1または sqrt(num) 以下で最大の素数
    if (num != 1) printf(" %d *", num); // 後者なら追記
    printf("\b \n");
    return 0;
}
int main(void){
    int num;
    num = inputNum();
    findFactors(num);
    return 0;
}