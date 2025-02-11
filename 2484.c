//Camila Fernanda e Silva Lima - RA: 176165
//Abracadabra

#include <stdio.h>
#include <string.h>

int main() {
    char palavra[101];  // A palavra pode ter até 100 caracteres + 1 para o '\0'
    
    while (scanf("%s", palavra) != EOF) {
        int tam = strlen(palavra);
        
        // Construir o triângulo invertido
        for (int i = 0; i < tam; i++) {
            // Imprimir o deslocamento de espaços à esquerda
            for (int j = 0; j < i; j++) {
                printf(" ");
            }

            // Imprimir as letras da linha
            for (int j = 0; j < tam - i; j++) {
                if (j != 0) {
                    printf(" ");  // Imprimir espaço entre as letras
                }
                printf("%c", palavra[j]);
            }

            printf("\n");  // Nova linha após cada linha do triângulo
        }
        
        // Linha em branco após cada caso de teste
        printf("\n");
    }

    return 0;
}
