#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char lista1[2000], lista2[2000];
    char amigo[200];

    gets(lista1);
    gets(lista2);
    gets(amigo);

    if (strcmp(amigo, "nao") == 0) {
        strcat(lista1, " ");
        strcat(lista1, lista2);
        printf("%s\n", lista1);
    } else {
        char *p = strstr(lista1, amigo);

        if (p != NULL) {
            int antes = p - lista1;
            char resultado[4000];

            strncpy(resultado, lista1, antes);
            resultado[antes] = '\0';

            strcat(resultado, lista2);

            strcat(resultado, " ");
            strcat(resultado, lista1 + antes);

            printf("%s\n", resultado);
        }
    }

    return 0;
}

