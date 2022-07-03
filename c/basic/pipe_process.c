#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

struct name {
    char first[10]; 
    char last[10]; 
};

int main() {
    size_t i;
    int n;
    int fd[2]; // ファイルディスクリプタを格納する配列 (fd[0]:読み取り, fd[1]]書き込み)
    pid_t pid, cpid;
    struct name read_data;

    // name構造体のの配列を定義
    struct name nlist[4] = {
        {"Taro", "Keio"},
        {"Hanako", "Keio"},
        {"Yuichi", "Fukuzawa"},
        {"Eiichi", "Shibusawa"}
    };

    if (pipe(fd) != 0) {
        perror("pipe");
        exit(1);
    }

    // printf("Now create new process\n");
    pid = fork();
    if (pid < 0) {
        printf("fork error\n");
        exit(1);
    }

    /* ---------- 子プロセス: データを受け取り表示 ---------- */
    if (pid == 0) {
        close(fd[1]); // パイプの不要ディスクリプタを閉じる
        // printf("child's process id = %d\n", (int)getpid());

        // データの数だけパイプから読み出す
        for (;;) {
            n = read(fd[0], &read_data, sizeof(read_data));
            if (n <= 0) {
                // printf("child termnating\n");
                exit(0);
            }
            else {
                printf("%s %s\n", read_data.first, read_data.last);
            }
        }
    }
    /* ---------- 親プロセス: データをパイプに書き込む ---------- */
    else {
        close(fd[0]);
        // printf("parent's prcess id = %d\n", (int)getpid());
        for (i = 0; i < sizeof(nlist) / sizeof(nlist[0]); i++) {
             // printf("%s %s\n", nlist[i].first, nlist[i].last);
             int res;
             res = write(fd[1], &nlist[i], sizeof(nlist[0]));
             // ファイル書き込み失敗
             if (res == -1) {
                fprintf(stderr, "ファイル書き込みエラー\n");
                return 1;
             }
             sleep(1);
        }
        close(fd[1]);
        int status;
        cpid = wait(&status);
        // printf("parent terminating\n");
        exit(0);
    }
    exit(0);
}
