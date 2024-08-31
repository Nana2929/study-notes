#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();
    switch(pid){
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            printf("child process takes hold, its process id is %d\n", getpid());
            execlp("/bin/ls", "ls", NULL); // execute ls command
            break;
        default:
            printf("parent process takes hold, its process id is %d\n", getpid());
            wait(NULL); // wait for child process to finish
            printf("child process has finished the ls command\n");
            break;
    }

}