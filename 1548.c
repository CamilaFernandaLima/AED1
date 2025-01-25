//Camila Fernanda e Silva Lima - RA: 176.165
//Fila do Recreio

#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *prox;
} fila;

// Insere um número na fila
void insere(int num, fila *entra) {
    fila *novo = malloc(sizeof(fila));
    novo->valor = num;
    novo->prox = NULL;

    if (entra->prox == NULL) {
        entra->prox = novo;
    } else {
        fila *aux = entra;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

// Conta os alunos que não mudaram de posição após a ordenação
int conta_nao_trocados(fila *entrada) {
    // Copia os valores da fila para um array
    int tamanho = 0;
    fila *aux = entrada->prox;
    while (aux != NULL) {
        tamanho++;
        aux = aux->prox;
    }

    int *notas = malloc(tamanho * sizeof(int));
    aux = entrada->prox;
    for (int i = 0; i < tamanho; i++) {
        notas[i] = aux->valor;
        aux = aux->prox;
    }

    // Ordena o array em ordem decrescente (bubble sort)
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (notas[j] < notas[j + 1]) {
                int temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }

    // Compara o array ordenado com a fila original
    int contador = 0;
    aux = entrada->prox;
    for (int i = 0; i < tamanho; i++) {
        if (notas[i] == aux->valor) {
            contador++;
        }
        aux = aux->prox;
    }

    free(notas); // Libera a memória alocada para o array
    return contador;
}

// Libera a memória da fila
void libera_fila(fila *entrada) {
    fila *aux = entrada->prox;
    while (aux != NULL) {
        fila *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    entrada->prox = NULL;
}

int main() {
    int n, m, num;
    fila *fila = malloc(sizeof(fila));
    fila->prox = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &num);
            insere(num, fila);
        }

        // Conta os alunos que não mudaram de posição e imprime o resultado
        int resultado = conta_nao_trocados(fila);
        printf("%d\n", resultado);

        // Libera a fila para o próximo caso de teste
        libera_fila(fila);
    }

    free(fila); // Libera o nó cabeça
    return 0;
}
