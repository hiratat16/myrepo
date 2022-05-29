#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int int_count = 0;

void handler(int sig){
    int_count++;
    printf("%d\n", int_count);
}

int main(int argc, char *argv[]){

    struct sigaction act;

    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = NULL;
    if(sigaction(SIGUSR1,&act,NULL) < 0){
        perror("sigaction");
        exit(1);
    }
    while(1){
        sleep(1000);
    }
    exit(0);
}


