#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    FILE *f;
    char buf[BUFSIZE];

    if(argc != 2)
    {
        while (fgets(buf, BUFSIZ, stdin) != NULL)
        {
            printf("%s", buf);
        }
        
    }
    else{
        f = fopen(argv[1], "r");
        if(f == NULL)
        {
            printf("File not found\n");
            exit(1);
        }
        while(fgets(buf, BUFSIZ, f) != NULL)
        {
            printf("%s", buf);
        }
        fclose(f);
    }
}