#include <unistd.h>
#include <stdio.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    int opt = 0, i;
    struct option my_opts[] = {
        {.name="color",.has_arg=2,.flag=0,.val='c'},
        {.name="tree",.has_arg=0,.flag=0,.val='t'},
        {.name="config",.has_arg=0,.flag=0,.val='g'},
        {.name="set",.has_arg=1,.flag=0,.val='s'},
        {.name="jump",.has_arg=2,.flag=0,.val='j'},
        {.name="reboot",.has_arg=0,.flag=0,.val='r'},
        {.name="program",.has_arg=1,.flag=0,.val='p'},
        {0,0,0,0}
    };
    while((opt = getopt_long(argc, argv, "", my_opts, NULL)) != -1) {
        switch (opt) {
            case 'c':
                if(optind < argc && argv[optind][0] != '-') {
                    printf("Robot is lightning to R=%c%c V=%c%c B=%c%c\n", argv[optind][1], argv[optind][2], argv[optind][3], argv[optind][4], argv[optind][5], argv[optind][6]);
                } else {
                    printf("Please specify a color\n");
                }
                break;
            case 't':
                printf("Robots are running spanning tree protocol\n");
                break;
            case 'g':
                printf("Robot is sending its configuration\n");
                break;
            case 's':
                i=0;
                printf("Robot is setting: ");
                while (optarg[i] != '=' && optarg != NULL) {
                    printf("%c", optarg[i]);
                    i++;
                }
                printf(" to ");
                i++;
                while (optarg[i] != '\0') {
                    printf("%c", optarg[i]);
                    i++;
                }
                printf("\n");
                break;
            case 'j':
                if(optind < argc && argv[optind][0] != '-') {
                    printf("Robot jumps to application at address 0x%s\n", argv[optind]);
                } else {
                    printf("Robot jumps to application at address 0x8010000\n");
                }
                break;
            case 'r':
                printf("Robot is rebooting\n");
                break;
            case 'p':
                printf("Robot is programming application: %s\n", optarg);
                break;
        }
    }  
                
    return 0;
}