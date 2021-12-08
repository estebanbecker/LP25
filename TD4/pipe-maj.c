#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    FILE *f;
    char buf[BUFSIZE];

    if(argc != 2)
    {
        while (fgets(buf, BUFSIZ, stdin) != NULL)
        {
            for( int i = 0; i < strlen(buf); i++)
            {   
                buf[i] = toupper(buf[i]);
            }
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
            for( int i = 0; i < strlen(buf); i++)
            {
                buf[i] = toupper(buf[i]);
            }
            printf("%s", buf);
        }
        fclose(f);
    }
}