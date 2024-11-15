//Camila Fernanda e Silva Lima - RA: 176.165
//Fila

#include <stdio.h>
#include <stdlib.h>

typedef struct elementoLista {
    int valor;
    struct elementoLista *proximo;
} item;

void inserir(item *cabeca, int num){
    item *novo;
    novo = malloc(sizeof(item));

    novo->valor = num; 
    novo->proximo = NULL;

    //inserção sempre no final
    //verificar se a fila esta vazia:
    
    item *atual = cabeca;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    
    atual->proximo = novo;
}

void imprimir(item *cabeca){
    item *atual = cabeca->proximo;

    while(atual != NULL){ 
        printf("%d ", atual->valor); 
        atual = atual->proximo; 
    }
    printf("\n");

}

void remover(item *cabeca, int num){
    item *no = cabeca;
    item *anterior = NULL;

    while(no != NULL && no->valor != num){
        anterior = no;
        no = no->proximo;
    }

    if (no != NULL){
        if(anterior != NULL){
            anterior->proximo = no->proximo;
        } else{
            cabeca->proximo = no->proximo;
        }
        free(no);
    }
}

int main(){

    item *cabeca = (item*)malloc(sizeof(item));
    cabeca->proximo = NULL;

    int n, m, ident_n, ident_m;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &ident_n);
        inserir(cabeca, ident_n);
    }

    scanf("%d", &m);
    for(int j=0; j<m; j++){
        scanf("%d", &ident_m);
        remover(cabeca, ident_m);
    }

    imprimir(cabeca);

    return 0;

}
