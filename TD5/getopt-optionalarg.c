#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int opt = 0;
    while((opt = getopt(argc, argv, "oa:b::")) != -1) {
        switch (opt) {
            case 'o':
                /* Do something with 'o' flag */
                printf("o\n");
                break;

            case 'a':
                /* Do something with 'a' and the argument pointed by optarg */
                printf("a: %s\n", optarg);
                break;

            case 'b':
                if(optarg != NULL) {
                    /* Do something with 'b' and the argument pointed by optarg */
                    printf("b: %s\n", optarg);
                } else if (optind < argc && argv[optind][0] != '-') {
                    /* Do something with 'b' and the argument pointed by argv[optind] */
                    printf("b: %s\n", argv[optind]);
                    optind++;
                } else {
                    /* Do something with 'b' and no argument */
                    printf("b: rien\n");
                }

        }
    }
    return 0;
}