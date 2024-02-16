#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp) {
    int cpid = fork();

    if(cpid == 0) {
        execl("/home/rayan/myfolder/bonus7.out", "bonus7", NULL);
        printf("Child...");
    } else {
        wait(NULL);
        printf("Parent...");
    }

}