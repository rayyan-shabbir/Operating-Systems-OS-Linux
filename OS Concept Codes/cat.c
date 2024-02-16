#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
    write(1, "Hi, I am your own cat ;)\n", 31);
    int fd = 0;
    if(argc > 1)
    {
        fd = open(argv[1], O_RDONLY);
    }
    int rv = 0;
    char buff[1024];
    while(rv = read(fd, buff, 1024))
    {
        write(1, buff, rv);
    }
    return 0;
}