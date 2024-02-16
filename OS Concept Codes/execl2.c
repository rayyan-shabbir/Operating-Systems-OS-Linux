#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int cpid = fork();
    if (cpid == 0)
    {
        execl("/usr/bin/gnome-calculator", "mycalc", NULL);
        printf("This line will not be printed\n");
    }
    else
    {
        wait(NULL);
        printf("Hello I m Parent.\n");
    }
    return 0;
}
