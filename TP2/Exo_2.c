#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   
    char chaine[1000];
    scanf("%s",&chaine);
    int nombre=0,j,k;
    char **tableau;
    
    int vide;


    for(int i = 0; i< strlen(chaine); i++)
    {
        if(chaine[i]==';'){
            nombre++;
        }
    }


    tableau=(char**)malloc(sizeof(char)*(nombre+1));
    k=0;
    for(int i = 0;i < nombre+1;i++){
        j=0;
        while (chaine[j+k] != ';')
        {   
        
            j++;
        }
        tableau[i]=(char*)malloc(sizeof(char)*(j+1));
        strncpy(tableau[i],&chaine[k],j);
        
        k=k+j+1;
    }

    for(int i = 0;i<nombre+1;i++){
        printf("%s\n",tableau[i]);
    }
}

