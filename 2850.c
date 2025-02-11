//Camila Fernanda e Silva Lima - RA: 176165
//Papagaio Poliglota

#include <stdio.h>
#include <string.h>

int main() {
    char estado[20];
    
    // Leitura contínua dos casos de teste
    while (scanf("%s", estado) != EOF) {
        if (strcmp(estado, "nenhuma") == 0) {
            printf("portugues\n");
        } else if (strcmp(estado, "esquerda") == 0) {
            printf("ingles\n");
        } else if (strcmp(estado, "direita") == 0) {
            printf("frances\n");
        } else if (strcmp(estado, "as") == 0) {
            scanf("%s", estado); // Para ler "duas" corretamente
            if (strcmp(estado, "duas") == 0) {
                printf("caiu\n");
            }
        }
    }
    
    return 0;
}
