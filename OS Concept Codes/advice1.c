#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("/tmp/fake", O_RDONLY);
    perror("ARM: Cant open file");
    printf("Ever wanted to be a Hacker?\n");
    printf("If Yes, Work hard and learn how OS throws errors to other files.\n");
    return 0;
}
