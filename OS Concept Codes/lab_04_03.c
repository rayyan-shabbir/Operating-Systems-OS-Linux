#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>

int main(void)
{
    printf("I am Parent okkkk\n");
    // int cp1 = 5;

    // printf("T am dead %d", cp1);

    int cp = fork();


    if (!cp)
    {
        printf("%d", cp);
        execl("/usr/bin/echo", "I am the child", NULL);
    }
    else
    {
        printf("%d", cp);
        wait(NULL);
        execlp("/usr/bin/echo", "I am Parent child is terminated", NULL);
    }
    return 0;
}
