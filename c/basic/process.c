#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

#define P_MAX 3 // プロセス数
#define COUNT 5 // カウント数

int main() {
    pid_t pid;
    int i;

    for (i = 1; i <= P_MAX; i++) {
        // P_MAX個のプロセスを作成
        pid = fork();

        switch (pid) {
            // プロセスの作成に失敗した場合
            case -1: 
                fprintf(stderr, "Cann't fork, error %d\n", errno);
                exit(EXIT_FAILURE);

            /*------------- 確認用 -------------*/
            // case 0:
            //     fprintf(stdout, "Child Process START (pid %d = %d)\n", i, (int)getpid());
            //     sleep(i * 3);
            //     break;
            default:
                break;
        }
        
        /*------------- Child Process -------------*/
        if (pid == 0) {
            int j;

            for (j = 1; j < (COUNT + i); j++) {
                printf("Process %d(%d)%d\n", i, (int)getpid(),j);

                sleep(1);
            }
            exit(EXIT_FAILURE);
        }   
    }

    /*------------- Parent Process -------------*/
    if (pid != 0) {
        int status;
        int child_pid;
        i = 0;
        
        while (i < P_MAX) {
            child_pid = wait(&status);
            if (child_pid > 0) {
                i++;
            }
        }
        printf("All process terminated.\n");
    }
    return 0;
}