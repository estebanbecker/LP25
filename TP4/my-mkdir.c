#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int i=1,j=0,pos, param_p=0;
    char folder[50];
    int buffer;

    if (argc == 2) {
        mkdir(argv[1], 0777);
    } else if(argc == 3) {
        while(i<3 && !param_p){
            if(argv[i][0] == '-'){
                if(argv[i][1] == 'p'){
                    param_p = 1;
                }
            }
            i++;
        }
        if(param_p){
            
            while (argv[1][j] != '\0'){
                if(argv[1][j] == '/'){
                    j++;
                }
                pos=j;
                while (argv[1][j] != '\0' && argv[1][j] != '/'){
                    j++;
                }
                strncpy(folder, &argv[1][pos],j- pos);
                folder[j-pos] = '\0';
                printf("%s\n", folder);
                if(chdir(folder) == -1){
                    mkdir(folder, 0777);
                }
                chdir(folder);
                
            }
            
        }
        

    }
return 0;
}