#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if(f == NULL)
    {
        printf("Error");
        return 1;
    }
    unsigned long long a;
    
    //Sort the binary file composed of unsigned long long with a bubble sort
    while(fread(&a, sizeof(unsigned long long), 1, f) == 1)
    {
        unsigned long long b;
        while(fread(&b, sizeof(unsigned long long), 1, f) == 1)
        {
            if(a > b)
            {
                unsigned long long tmp = a;
                a = b;
                b = tmp;
            }
            fseek(f, -2*sizeof(unsigned long long), SEEK_CUR);
        }
        fseek(f, -1*sizeof(unsigned long long), SEEK_CUR);
    }
    fclose(f);
    return 0;
}