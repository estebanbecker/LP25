#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int j=0;
    // Know the size of all arguments
    for (int i = 1; i < argc; i++){
        j = j + strlen(argv[i]);
    }
    char *concat=malloc(sizeof(char)*(j+1));

    //Concatenate the arguments
    for (int i = 1; i < argc; i++)
    {
        strcat(concat, argv[i]);
    }

    printf("%s\n", concat);
}