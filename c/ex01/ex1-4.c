//素数

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

/* 学習用
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