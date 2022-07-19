/* train10.c */
/* 関数へのポインタを使ったライブラリ関数qsort()を使って,
次のようなname構造体に記憶された(名,姓)の組を姓の順序に並び替え, 
姓がが同じ場合には名前の順序で並び替えるプログラムを作成してください 
struct name {
    char first[10];
    char last[10];
};
データは,main()関数の先頭で,次のように4要素の配列を定義し,それをqsort()関数に
渡すようにしてください.
struct name nlist[4] = {
    {"Taro", "Keio"},
    {"Hanako", "Keio"},
    {"Yuichi", "Fukuzawa"},
    {"Eiichi", "Shibusawa"}
};
qsort()で使う名前を比較する関数は自分で定義してください.
文字列の比較には,標準ライブラリのstrcmp/strncmp関数を使って構いません.

並び替えの前と後で,それぞれnlist[0]からnlist[3]を適切な形式で表示させてください.
並べ替えの前の表示は次のようになるはずです.
Taro Keio
Hanako Keio
Yuichi Fukuzawa
Eiichi Shibusawa */
#include <stdio.h>
#include <string.h>
typedef struct {
    char first[10];
    char last[10];
} Name;

int charcmp(const void *a, const void *b) {
    Name *name1 = (Name*)a;
    Name *name2 = (Name*)b;
    
    int lastcmp = strncmp(name1->last, name2->last, sizeof(name1->last));
    // printf("sizeof(name1->last)=%ld, &name1->last=%p\n", sizeof(name1->last),  &name1->last);
    // printf("sizeof(name2->last)=%ld, &name2->last=%p\n", sizeof(name2->last),  &name2->last);
    

    if (lastcmp != 0) {
        return lastcmp;
    }
    // printf("sizeof(name1->first)=%ld, &name1->first=%p\n", sizeof(name1->first), &name1->first);
    // printf("sizeof(name2->first)=%ld, &name2->first=%p\n", sizeof(name2->first), &name2->first);
    return strncmp(name1->first, name2->first, sizeof(name1->first));


}

int main() {
    int num, i;
    Name nlist[4] = {
        {"Taro", "Keio"},
        {"Hanako", "Keio"},
        {"Yuichi", "Fukuzawa"},
        {"Eiichi", "shibusawa"}
    };
    num = sizeof(nlist) / sizeof(nlist[0]);
    printf("%d\n", num);
    /*----- 並べ替え前 -----*/
    for (i = 0; i < num; i++) {
        printf("%.10s %.10s\n", nlist[i].first, nlist[i].last);
    }
    printf("\n");

    qsort(nlist, num , sizeof(nlist[0]), charcmp);
    // printf("\n");
    // printf("sizeof(nlist[0]) = %ld, &nlist[0]=%p\n", sizeof(nlist[0]), &nlist[0]);
    // printf("sizeof(nlist[1]) = %ld, &nlist[1]=%p\n", sizeof(nlist[1]), &nlist[1]);
    // printf("sizeof(Name) = %ld\n",sizeof(Name));
    // printf("\n");
    /*----- 並べ替え後 -----*/
    for (i = 0; i < num; i++) {
        printf("%.10s %.10s\n", nlist[i].first, nlist[i].last);
    }
    return 0;
}