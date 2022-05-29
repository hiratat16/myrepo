//signal.c の参考プログラム 
#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
  int fd[2]; // パイプ用
  int fds; // ファイル用
  pid_t pid;

  // 引数の確認
  if (argc < 2 ){
     fprintf(stderr,"filename required\n");
     return -1;
  }
  // 引数で指定されたファイルのオープン
  fds = open(argv[1],O_RDONLY);
  if(fds == -1){
    perror("open error");
    exit(1);
  }
  // パイプの作成
  if(pipe(fd)!=0){
    perror("pipe");
    exit(1);
  }

  // プロセスの生成
  pid = fork();
  if(pid < 0){
    printf("fork error");
    exit(1);
  }

  // 子プロセス //
  if(pid == 0){
    close(fd[1]);
    if(fd[0] != STDIN_FILENO){
      if(dup2(fd[0], STDIN_FILENO) != STDIN_FILENO){
        perror("dup2");
        exit(1);
      }
      close(fd[0]);
    }
    if( execl("/usr/bin/sort","sort", (char *)NULL) < 0 ){
      perror("execl");
      exit(1);
    }
  // 親プロセス //
  }else{
    int status, rcc;
    char buf[BUFSIZ]; // ファイルからの読み込み用
    close(fd[0]);
    for(;;){
      rcc = read(fds,buf,BUFSIZ);
      if(rcc == -1){
        perror("read");
        exit(1);
      }else if(rcc == 0){ // ファイル終了
        break;
      }else{
        write(fd[1],buf,rcc);
      }
    }
    close(fd[1]);
    (void) wait(&status);
    return 0;
  }
}