//フィボナッチ数の計算

#include <stdio.h> //標準の入出力

int main(){
    int n;
    int f0, f1, f2;
    int count = 0;

    f0 = 0;
    f1 = 1;

    while(f1<1000000) {
        count++;
        //printf("%d\n", count);
        if(count > 30) break;
        printf("%d\n", f1);

        f2 = f1 + f0;

        f0 = f1;
        f1 = f2;
    }

    return 0;
}
