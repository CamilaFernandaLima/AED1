//Camila Fernanda e Silva Lima - RA: 176165
//Conversa Internacional

#include <stdio.h>
#include <string.h>

int main() {
    int N; // Número de casos de teste
    scanf("%d", &N);
    
    while (N--) {
        int K; // Número de pessoas no grupo
        scanf("%d", &K);
        
        char idiomas[100][21]; // Array para armazenar os idiomas nativos
        for (int i = 0; i < K; i++) {
            scanf("%s", idiomas[i]);
        }
        
        // Verificar se todos os idiomas são iguais
        int todos_iguais = 1; // Flag para verificar se todos os idiomas são iguais
        for (int i = 1; i < K; i++) {
            if (strcmp(idiomas[i], idiomas[0]) != 0) {
                todos_iguais = 0; // Encontrou um idioma diferente
                break;
            }
        }
        
        // Imprimir o resultado
        if (todos_iguais) {
            printf("%s\n", idiomas[0]); // Todos os idiomas são iguais
        } else {
            printf("ingles\n"); // Idiomas diferentes
        }
    }
    
    return 0;
}
