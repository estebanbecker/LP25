#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *ent;
    struct stat buf;
    float size, size_bin, size_SI;
    
    char dirname[1000];
    if (argc != 2)
    {
        printf("Please give a repository in parameter");
        return -1;
    }

    

    dir = opendir(argv[1]);
    
    ent=readdir(dir);
    
    while (ent != NULL)
    {   
        strcpy(dirname, argv[1]);
        strcat(dirname, "/");
        strcat(dirname,ent->d_name);

        stat(dirname,&buf);
        size = buf.st_size;

        
        printf("%s %d", ent->d_name,buf.st_size);
        
        if (size > 1024)
        {
            size_bin = size / 1024;
            if (size_bin > 1024)
            {
                size_bin = size_bin / 1024;
                if (size_bin > 1024)
                {
                    size_bin = size_bin / 1024;
                    if (size_bin > 1024)
                    {
                        size_bin = size_bin / 1024;
                        printf(" %.2f Tio\n", size_bin);
                    }
                    else
                    {
                        printf(" %.2f Gio\n", size_bin);
                    }
                }
                else
                {
                    printf(" %.2f Mio\n", size_bin);
                }
            }
            else
            {
                printf(" %.2f Kio", size_bin);
            }
        }

        if (size > 1000)
        {
            size_SI = size / 1000;
            if (size_SI > 1000)
            {
                size_SI = size_SI / 1000;
                if (size_SI > 1000)
                {
                    size_SI = size_SI / 1000;
                    if (size_SI > 1000)
                    {
                        size_SI = size_SI / 1000;
                        printf(" %.2f To\n", size_SI);
                    }
                    else
                    {
                        printf(" %.2f Go\n", size_SI);
                    }
                }
                else
                {
                    printf(" %.2f Mo\n", size_SI);
                }
            }
            else
            {
                printf(" %.2f Ko", size_SI);
            }
        }

        printf("\n");
        ent = readdir(dir);
    }
    closedir(dir);
    
}