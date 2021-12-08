#include <stdio.h>
#include <signal.h>

#define BUFFER_SIZE 150

volatile sig_atomic_t sigint_trigerred;

void sigint_handler(int signal);

int main(int argc, char *argv[]) {

    struct sigaction sigint_action;
    sigint_action.sa_handler = sigint_handler;
    sigint_action.sa_flags = SA_RESETHAND;
    sigint_action.sa_restorer = NULL;
    

    FILE *f = fopen("dump.txt", "w");

    sigaction(SIGINT, &sigint_action, NULL);

    if (f) {
        char buffer[BUFFER_SIZE];
        do {
            fgets(buffer, BUFFER_SIZE, stdin);
            if(!sigint_trigerred) {
                fprintf(f, "%s", buffer);
                buffer[0] = '\0';
            }
        } while (!sigint_trigerred);
    }
    fclose(f);
    return 0;
}

void sigint_handler(int signal){
    sigint_trigerred = 1;
}