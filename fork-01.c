#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define MAX_COUNT 200
#define BUFFER_SIZE 100

int main(int argc, char *argv[])
{
    
    pid_t pid;
    int i;
    char buf[BUFFER_SIZE];

    // after a new child process is creted, both processes will execute the 
    // next instruction following the fork() systemcall
    fork();
    pid = getpid();

    for (i = 1; i < MAX_COUNT; ++i) {
        sprintf(buf, "This line is from pid: %d, value = %d\n",pid, i);
        write(1, buf, strlen(buf));
        // whaw is thre reason of using write rather than printf?
        // it is because printf() is "buffered", meaning printf() will
        // group the output of processes together 
    }


    return 0;
}
