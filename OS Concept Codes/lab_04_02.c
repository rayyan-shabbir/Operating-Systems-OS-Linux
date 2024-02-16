#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    execlp("ls", "myls", NULL);
    // execl("/usr/bin/echo", "echo", "I am echo", NULL);
    // execl("/usr/bin/echo", "I am echo", NULL);      // It will print nothing, bcz 2nd argument is incorrect it must be the name of command that will be executed. Like in above case it has to be echo.
    return 0;
}
