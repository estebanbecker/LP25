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
        printf("%s %d\n", ent->d_name,buf.st_mode);
        ent = readdir(dir);
    }
    closedir(dir);
    
}