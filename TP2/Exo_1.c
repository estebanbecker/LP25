#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *tableau;
    int check=1,i=0;
    while(argv[1][i] != '\0' )
    {
        if(!(argv[1][i] <='9') || !(argv[1][i] >='0'))
        {
            check = 0;
        }
        i++;
    }

    if(check == 1){
    int nb_elements=atoi(argv[1]);
    tableau = (int*)malloc(sizeof(int)*nb_elements);

    for( i = 0; i< nb_elements; i++)
    { tableau[i] = i+1; }

    for(int i = 0; i< nb_elements; i++)
    { printf("%d\n", tableau[i]); }
    }else{
        printf("Erreur de saisie");
    }
}
