#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_MAX 50
#define PARAMETER_BUFFER_SIZE 16

typedef enum {IS_INT, /* Data is integer or derived */
              IS_DEC, /* Data is float or double */
              IS_STRING /* Data is a string */
              } e_data_type;

typedef union {long long integer;
               double decimal;
               char str[STR_MAX];
               } data_wrapper;

typedef struct {e_data_type data_type;
                data_wrapper data;
                } s_any_data;

int is_int(char *str);
int is_float(char *str);

int main(int argc, char *argv[]) {
    //décomposition d'une chaîne de caractères en nombre
    s_any_data my_parameters[PARAMETER_BUFFER_SIZE];
    
    char chaine[1000];
    fgets(chaine, 1000, stdin);
    int nombre=0,j,k;
    char buffer[STR_MAX];
    int void1;
    float void2;
    
    int vide;


    for(int i = 0; i< strlen(chaine); i++)
    {
        if(chaine[i]==';'){
            nombre++;
        }
    }

    k=0;
    for(int i = 0;i < nombre+1;i++){
        j=0;
        while (chaine[j+k] != ';')
        {   
        
            j++;
        }

        strncpy(buffer,&chaine[k],j);
        buffer[j]='\0';

        printf("%s\n",buffer);

        if(is_int(buffer)){
            my_parameters[i].data_type=IS_INT;
            my_parameters[i].data.integer=atoi(buffer);
        }
        else if(is_float(buffer)){
            my_parameters[i].data_type=IS_DEC;
            my_parameters[i].data.decimal=atof(buffer);
        }
        else{
            my_parameters[i].data_type=IS_STRING;
            strcpy(my_parameters[i].data.str,buffer);
        }
        
        k=k+j+1;
    }

    for(int i = 0; i< nombre+1; i++){
        if(my_parameters[i].data_type==IS_INT){
            printf("%lld\n",my_parameters[i].data.integer);
        }
        else if(my_parameters[i].data_type==IS_DEC){
            printf("%f\n",my_parameters[i].data.decimal);
        }
        else if(my_parameters[i].data_type==IS_STRING){
            printf("%s\n",my_parameters[i].data.str);
        }
    }
    

    return 0;
}


int is_int(char *str)
{
    int i=0;
    while(str[i] != '\0')
    {
        if(!(str[i] <='9') || !(str[i] >='0'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int is_float(char *str)
{
    int i=0;
    while(str[i] != '\0')
    {
        if(!(str[i] <='9') || !(str[i] >='0'))
        {
            if(str[i] == '.')
            {
                i++;
                while(str[i] != '\0')
                {
                    if(!(str[i] <='9') || !(str[i] >='0'))
                    {
                        return 0;
                    }
                    i++;
                }
            }else{
                return 0;
            }
        }
        i++;
    }
    return 1;
}