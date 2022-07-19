// 構造体をqsort()を使って並べ替える.
#include <stdio.h>
#include <string.h>
typedef struct {
    char first[10];
    char last[10];
} Name;

// qsortにわたす関数
// 最初にlastを比較して,strncmpの返す値をそのまま返す
int namecmp(Name *name1, Name *name2) {
    int ret;
    ret = strncmp(name1->last, name2->last, 10);
    if (ret > 0) {
        return 1;
    } else if (ret < 0) {
        return -1;
    } else {
        ret = strncmp(name1->first, name2->first, 10);
        if (ret > 0) {
            return 1;
        } else if (ret < 0) {
            return -1;
        } else {
            return 0;
        }
    }
}

int main() {
    int i, num;
    Name nlist[4] = {
        {"Taro", "Keio"},
        {"Hanako", "Keio"},
        {"Yuichi", "Fukuzawa"},
        {"Eiichi", "Shibusawa"}
    };

    num = sizeof(nlist)/sizeof(Name);
    printf("%d\n", num);
    // 最初の状態
    for (i = 0; i < num; i++) {
        printf("%.10s %.10s\n", nlist[i].first, nlist[i].last);
    }
    printf("\n");
    // 並べ替えのためにqsort()を呼び出す
    // 第一引数:qsortにName型配列nlistを渡す(並べ替え対象となる配列データへの先頭番地)
    qsort((void *)nlist, num, sizeof(Name), (void *)namecmp);

    // 並べ替えた後の状態
    for (i = 0; i < num; i++) {
        printf("%.10s %.10s\n", nlist[i].first, nlist[i].last);
    }
    return 0;
}