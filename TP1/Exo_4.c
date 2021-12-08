#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Programe that sort a list of strings

int main(int argc, char *argv[])
{   
    char** liste;
    int nb_elem,a, max=0;
    int check=0;
    char *temp;
    
    nb_elem=argc-1;
    //determine the lengest string
    for(int i=1;i<=nb_elem;i++)
    {
        if(strlen(argv[i])>max)
        {
            max=strlen(argv[i]);
        }
    }

    temp=malloc(sizeof(char)*(max+1));
    
    liste=malloc(sizeof(char*)*(nb_elem));
    for(int i=0;i<nb_elem;i++)
    {
        
        liste[i]=malloc(sizeof(char)*(max+1));
        strcpy(liste[i],argv[i+1]);
    }


    //Sort the list
    while(check==0)
    {
        check=1;
        for(int i=0;i<nb_elem-1;i++)
        {
            if(strcmp(liste[i],liste[i+1])>0)
            {
                temp=liste[i];
                liste[i]=liste[i+1];
                liste[i+1]=temp;
                check=0;
            }
        }
    }

    //Print the list
    for(int i=0;i<nb_elem;i++)
    {
        printf("%s\n",liste[i]);
    }
    return 0;
}