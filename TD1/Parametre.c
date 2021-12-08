#include <stdio.h>

int main(int argc, char *argv[]) {
    /*
     Compléter ici pour vérifier qu'il y a un argument suivant le nom du programme.
     Si l'argument n'est pas présent, renvoyer 1 (erreur du programme)
     Sinon, afficher "Hello, %s!" en substituant %s par la valeur de l'argument n°2
    */
    if (argc < 2) {
        return 1;
    }
    printf("Hello, %s!\n", argv[1]);
    return 0;
}