//Camila Fernanda e Silva Lima - RA: 176165
//Diamantes e Areia

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char vetor[1000];
    int topo;
} pilha;

void empilha(char valor, pilha *pilha){
    if (pilha->topo <1000){
        pilha->vetor[pilha->topo] = valor;
        pilha->topo++;
    }
}

void desempilha(pilha *pilha){
    if (pilha->topo >0){
        pilha->topo --;
    }
}

int main(){

    char entrada[1000];
    pilha p;
    p.topo = 0;
    int n, cont;

    scanf("%d\n", &n);

    while(n--){
        fgets(entrada, sizeof(entrada), stdin);
        int tam = strlen(entrada);
        p.topo = 0;
        cont = 0;

        for(int i=0; i<tam; i++){
            if(entrada[i] == '<'){
                empilha('<', &p);
            } else if(entrada[i] == '>'){
                if(p.topo > 0){
                    desempilha(&p);
                    cont ++;
                } 
            }
            
        }
        printf("%d\n", cont);

    }
    
    return 0;
}
