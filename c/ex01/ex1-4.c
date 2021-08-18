/* 1.4
1と自分自身以外の数で割り切れない数を素数（prime number）といいます.たとえば,2とか7
とか19とかが素数です.ある数が素数かどうかを判定するプログラムex1-4.cを作りましょう.
素数の判定方法はいろいろあります.簡単な方法として,繰り返しを使い,ある数が2から（その数-1）
までで割り切れるかどうかを調べ,すべての場合に割り切れなければ素数だとわかります.
*/

#include <stdio.h>
int main() {
    int i, num, flag=0;

    printf("自然数 = ");
    scanf("%d", &num);

    for(i=2;i<num;++i) {
        if(num % i == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        printf("%dは素数です.\n", num);
    } else {
        printf("%dは素数ではありません.\n", num);
    }
    return 0;
}

/* memo
前置インクリメント演算子（++i）と後置インクリメント演算子（i++）
「前置インクリメント演算子（++i）」
_____________________________
int main() {
    int i = 10;
    printf("++i=[%d]\n",++i);
    printf("i=[%d]\n",i);
    return 0;
}
実行結果
++i=[11]
i=[11]
→ 「++i（前置インクリメント演算子）」の場合は「iに1を足した結果」を表示する

「後置インクリメント演算子（i++）」
_____________________________
int main() {
    int i = 10;
    printf("i++=[%d]\n", i++);
    printf("i=[%d]\n",i);
}
実行結果
i++=[10]
i=[11]

*/