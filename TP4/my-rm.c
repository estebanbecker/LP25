#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char *argv[])
{
    struct stat st;
    for(int i=1;i<argc;i++)
    {
        if(0 == stat(argv[i],&st))
            {
                remove(argv[i]);
            }
        
    }
    return 0;
}