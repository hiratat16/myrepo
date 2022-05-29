#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256 //1行の最大文字数（バイト数）
#define MAX_DICT 100

struct data {
    char key[N];
    char description[N];
};

int main(int argc, char *argv[]) {
    FILE *fp = NULL; // FILE型構造体
    char str[N], input[N];
    char *sp;
    int sp2;
    int index=0;
    int i;
    int diff;

    struct data dictionary[MAX_DICT];

    if(argc > 1){
        fp = fopen(argv[1], "r"); //ファイルを開く。失敗するとNULLを返す。
    }

    if(fp == NULL) {
        printf("%s file not open!\n", argv[1]);
        return -1;
    }

    while(fgets(str, N, fp) != NULL) {
        sp = strstr(str, ",");
        //printf("%s\n", sp);
        int key_len = sp - str;
        //memcpy：nバイトメモリブロックのコピー
        //strの先頭からn文字分を, dictionary[index].keyにコピー
        memcpy(dictionary[index].key, str, key_len);
        dictionary[index].key[key_len] = '\0'; //NULLで終端する
        sp++; //カンマ部分をスキップ
        strcpy(dictionary[index].description, sp);
        index++;
        if(index >= MAX_DICT) break;
    }

    fclose(fp); //ファイルを閉じる

    //入力受け付け
    while(1){
        printf("key> ");
        scanf("%s", input);
        for(i=0;i<index;i++){
            //文字列の検索
            diff = strcmp(dictionary[i].key, input);
            if(diff == 0){
                printf("%s\n", dictionary[i].description);
                break;
            }
        }
        if(i == index){
            printf("not found\n");
        }       
    }
}