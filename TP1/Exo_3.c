#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Programme that check if the argument is a palindrome or not
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

    //Lowercase the string
    for (int i = 0; i < j; i++)
    {
        concat[i] = tolower(concat[i]);
    }

    //Check if the argument is a palindrome
    int i=0,k=j-1,result=0;

    while(i<k && result==0){
        
        if(concat[i]!=concat[k]){
            result=1;
        }
        i++;
        k--;
    }
    if(result==0){
        printf("%s is a palindrome\n",concat);
    }
    else{
        printf("%s is not a palindrome\n",concat);
    }

}