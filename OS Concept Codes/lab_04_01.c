#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
write(1, "I am learning OS", 17);
write(1, "I know what is syscall", 23);
write(1, "I am going to run the echo command", 35);
execl("/usr/bin/echo", "echo", "i am here", NULL);
write(1, "Should i be printed on screen or not", 37);
return 0;
}
