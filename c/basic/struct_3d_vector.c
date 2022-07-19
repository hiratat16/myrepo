/* 二つの分数を入力して和を分数として表示するプログラムにならって,
二つの3次元ベクトル(つまり),(x,y,z)という3つの座標成分)を入力して,
その和と差を計算するプログラムを作成して下さい.
ただし,次の要件を満たすようにしてください.
・3次元ベクトルは,構造体とし,メンバーとして,int x;int y;int z;をもつようにする.
・入力は分数の例にならうが,スラッシュではなくコンマで区切るようにする
・そのため,sscanf()には,"%d,%d,%d"ような文字列で入力形式を指定する
・main()関数の中で入力した後,vector_add()のような関数(名前は何でも良いが,void型)を
呼び出す.分数の例のように,入力された3つの座標成分を2組と,結果の入る2組,
合わせて三つの構造体を使って呼び出された関数を計算する.
・関数の中で,ベクトルの加算を行う.つまり,(x1,y1,z1)と(x2,y2,z2)から,
(x1+x2,y1+y2,z1+z2)という座標の組を計算する.
・差についても,vector_sub()のような関数を同様に作成して計算する. 差は1番目に入力
された座標から2番目に入力された座標を引き算して計算する.
・計算結果はmain()の中で表示する.結果は,分数の場合に準じて,(1,1,1)+(2,3,4)=(3,4,5)
のように表示する.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

//3次元ベクトルは,構造体とし,メンバーそして,int x,y,zを持つ
struct vector{
    int x;
    int y;
    int z;
};

//関数の中で,ベクトルの加算を行う.つまり,(x1,y1,z1)と(x2,y2,z2)から,
//(x1+x2,y1+y2,z1+z2)という座標の組を計算する.
void vector_add(struct vector *p,
    struct vector *q,
    struct vector *r){

    r->x = p->x + q->x;
    r->y = p->y + q->y;
    r->z = p->z + q->z;
    return;
}


void vector_sub(struct vector *p,
    struct vector *q,
    struct vector *r){

    r->x = p->x - q->x;
    r->y = p->y - q->y;
    r->z = p->z - q->z;
    
    return;
}

int main(){
    int ret;
    char input[MAXLINE];
    struct vector a, b, c, d;

    //入力はコンマで区切る
    //sscanf():"%d,%d,%d"のような文字列で入力形式を指定する
    fgets(input, MAXLINE, stdin); 
    ret = sscanf(input, "%d,%d,%d", &a.x, &a.y, &a.z);
    if(ret != 3) {exit(1);}
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d,%d,%d", &b.x, &b.y, &b.z);
    if(ret != 3) {exit(1);}

    //main()関数の中で入力した後,vector_add()のような関数(void型)を呼び出す.
    //分数の例のように,入力された3つの座標成分を2組と,
    //結果の入る1組,合わせて三つの構造体を使って呼び出された関数を計算する
    //3つ目の引数として,結果を入れるための構造体(へのポイント)を渡す
    vector_add(&a,&b,&c);

    //差についても,vector_sub()のような関数を同様に作成して計算する.
    //差は1番目に入力された座標から2番目に入力された座標を引き算して計算する.
    vector_sub(&a,&b,&d);

    //計算結果はmain()の中で表示する.結果は,(1,1,1)+(2,3,4)=(3,4,5)
    //のように表示する
    printf("(%d,%d,%d)+(%d,%d,%d)=(%d,%d,%d)\n",
        a.x, a.y, a.z,
        b.x, b.y, b.z,
        c.x, c.y, c.z);

    printf("(%d,%d,%d)-(%d,%d,%d)=(%d,%d,%d)\n",
        a.x, a.y, a.z,
        b.x, b.y, b.z,
        d.x, d.y, d.z);

    exit(0); 
}

