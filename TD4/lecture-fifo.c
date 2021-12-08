#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void sigint_handler(int signal);

int main()
{
    int fd1, fd2;
    char buffer[BUFFER_SIZE];

    fd1=open("fifo1", O_READONLY | O_NONBLOCK);
    fd2=open("fifo2", O_READONLY | O_NONBLOCK);

    signal(SIGINT, sigint_handler);

    while(1)
    {
        if(read(fd1, buffer, BUFFER_SIZE)>0)
        {
            printf("%s", buffer);
        }
        for(int i=0; i<BUFFER_SIZE; i++)
        {
            buffer[i]='\0';
        }
        if(read(fd2, buffer, BUFFER_SIZE)>0)
        {
            printf("%s", buffer);
        }
        for(int i=0; i<BUFFER_SIZE; i++)
        {
            buffer[i]='\0';
        }
    }
}

void sigint_handler(int signal)
{
    printf("\nGood Bye\n");
    exit(0);
}