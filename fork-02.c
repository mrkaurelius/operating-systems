#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define MAX_COUNT 200

void ChildProcess();
void ParentProcess();

int main(int argc, char *argv[])
{

    pid_t pid;
    pid = fork();
    if (pid == 0)
        ChildProcess();
    else 
        ParentProcess();
        
    

    return 0;
}

void ChildProcess(void)
{
    int i;

    for (int i = 0; i < MAX_COUNT; ++i) {
        printf(" this line is from child value = %d\n", i);
    }
    
    printf(" *** child proces is done ***\n ");
}

void ParentProcess(void)
{
    int i;

    for (int i = 0; i < MAX_COUNT; ++i) {
        printf(" this line is from parent value = %d\n", i);
    }
    
    printf(" *** parent proces is done ***\n ");
}
