#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name {
    char first[10]; 
    char last[10]; 
};

/* ---------- 名前を比較する関数 ---------- */
int charcmp(const void *a, const void *b) {

    struct name *aa = (struct name *)a;
    struct name *bb = (struct name *)b;

    // まずLast Nameを比較
    int lastcmp = strncmp(aa->last, bb->last, sizeof(aa->last));

    // Last Nameが異なる場合は,その結果を返す
    if (lastcmp != 0)
        return lastcmp;

    // Last Nameが同一ならばFirstNameを比較
    return strncmp(aa->first, bb->first, sizeof(aa->first));

}

int main() {
    size_t i;
    
    // 4要素の配列を定義
    struct name nlist[4] = {
        {"Taro", "Keio"},
        {"Hanako", "Keio"},
        {"Yuichi", "Fukuzawa"},
        {"Eiichi", "Shibusawa"}
    };

    // 並べ替え前の表示
    printf("----- 並べ替え前の表示 -----\n");
    // 配列の要素数 = 配列の要素全体の大き朝 / 配列の要素1つ分の大きさ
    for(i = 0; i < sizeof(nlist) / sizeof(nlist[0]); i++) {
        printf("%s %s\n", nlist[i].first, nlist[i].last);
    }

    // クイックソート
    qsort(nlist, sizeof(nlist) / sizeof(nlist[0]), sizeof(nlist[0]), charcmp);

    
    // 並び替え後の表示
    printf("----- 並べ替え後の表示 -----\n");
    for(i = 0; i < sizeof(nlist) /sizeof(nlist[0]); i++) {
        printf("%s %s\n", nlist[i].first, nlist[i].last);
    }
    return 0;
}
