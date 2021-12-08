#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Please give a repository in parameter");
    }

    DIR *dir;

    dir = opendir(argv[1]);
    struct dirent *ent;
    ent=readdir(dir);
    
    while (ent != NULL)
    {
        printf("%s\n", ent->d_name);
        ent = readdir(dir);
    }
    closedir(dir);
    
}