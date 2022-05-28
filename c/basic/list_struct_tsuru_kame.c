#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 265

struct kotae {
    unsigned int tsuru;
    unsigned int kame;
};

int solve(unsigned int atama, unsigned int ashi, struct kotae *p);


int main() {
    int ret;
    char input[MAXLINE];
    unsigned int atama, ashi;
    struct kotae a;

    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d,%d", &atama, &ashi);

    if(solve(atama, ashi, &a)==1){
        printf("tsuru=%d\n", a.tsuru);
        printf("tsuru=%d\n", a.kame);
    }
    else{
        printf("ERROR\n");
    }
    
    exit(0);
}


int solve(unsigned int atama, unsigned int ashi, struct kotae *p){

    p->kame = (ashi / 2) - atama;
    p->tsuru = atama - p->kame;

    if ((atama == p->kame + p->tsuru) && (ashi == 2 * p->tsuru + 4 * p->kame)) {
        return 1;
    } else {
        return 0;
    }

    return 0;

}


/*
次のように、表示がおかしい場合があります 
%./kadai4 10,16 tsuru=12 tsuru=-2
*/