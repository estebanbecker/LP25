#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int find(char *dir, char *pattern);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <dir> <extension>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    find(argv[1], argv[2]);
}

int find(char *dir, char *pattern)
{
    DIR *d;
    struct dirent *dir_entry;
    char path[1024];

    d = opendir(dir);
    dir_entry = readdir(d);

    while (dir_entry != NULL)
    {   
        if (strcmp(dir_entry->d_name,pattern) == 0)
        {
            printf("%s/%s\n",dir, dir_entry->d_name);
        }
        else if( dir_entry->d_type == DT_DIR && dir_entry->d_name[0] != '.')
        {   
            strcpy(path, dir);
            strcat(path, "/");
            strcat(path, dir_entry->d_name);


            find(path, pattern);
        }
        dir_entry = readdir(d);
    }
    
}