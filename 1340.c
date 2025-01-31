//Camila Fernanda e Silva Lima - RA: 176.165
//Eu posso adivinhar a estrutura de dados!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int valor;
    struct no *prox;
} no;

void insere_fila(int v, no **cabeca) {
    no *novo = malloc(sizeof(no));
    novo->valor = v;
    novo->prox = NULL;

    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        no *aux = *cabeca;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

int remove_fila(no **cabeca) {
    if (*cabeca == NULL) return -1;  
    no *aux = *cabeca;
    int x = aux->valor;
    *cabeca = aux->prox;
    free(aux);
    return x;
}

void insere_pilha(int v, no **cabeca) {
    no *novo = malloc(sizeof(no));
    novo->valor = v;
    novo->prox = *cabeca;
    *cabeca = novo;
}

int remove_pilha(no **cabeca) {
    if (*cabeca == NULL) return -1;  
    no *aux = *cabeca;
    int x = aux->valor;
    *cabeca = aux->prox;
    free(aux);
    return x;
}

void insere_p(int v, no **cabeca) {
    no *novo = malloc(sizeof(no));
    novo->valor = v;

    if (*cabeca == NULL || (*cabeca)->valor < v) {
        novo->prox = *cabeca;
        *cabeca = novo;
    } else {
        no *aux = *cabeca;
        while (aux->prox != NULL && aux->prox->valor >= v) {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}

void libera_lista(no **cabeca) {
    while (*cabeca != NULL) {
        no *aux = *cabeca;
        *cabeca = (*cabeca)->prox;
        free(aux);
    }
}

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {  
        bool is_stack = true, is_queue = true, is_pq = true;
        no *pilha = NULL, *fila = NULL, *pq_i = NULL;

        for (int i = 0; i < n; i++) {
            int comando, x;
            scanf("%d", &comando);

            if (comando == 1) {
                scanf("%d", &x);
                if (is_stack) insere_pilha(x, &pilha);
                if (is_queue) insere_fila(x, &fila);
                if (is_pq) insere_p(x, &pq_i);
            } else if (comando == 2) {
                scanf("%d", &x);

                if (is_stack) {
                    if (pilha == NULL || remove_pilha(&pilha) != x) {
                        is_stack = false;
                    }
                }
                if (is_queue) {
                    if (fila == NULL || remove_fila(&fila) != x) {
                        is_queue = false;
                    }
                }
                if (is_pq) {
                    if (pq_i == NULL || remove_pilha(&pq_i) != x) {  
                        is_pq = false;
                    }
                }
            }
        }

        if (is_stack + is_queue + is_pq > 1) {
            printf("not sure\n");
        } else if (is_stack) {
            printf("stack\n");
        } else if (is_queue) {
            printf("queue\n");
        } else if (is_pq) {
            printf("priority queue\n");
        } else {
            printf("impossible\n");
        }

        // Liberar memória antes de processar o próximo caso de teste
        libera_lista(&pilha);
        libera_lista(&fila);
        libera_lista(&pq_i);
    }

    return 0;
}
