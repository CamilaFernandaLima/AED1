//Camila Fernanda e Silva Lima - RA: 176.165

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int const TAM = 400000; //constante para tamanho do vetor

void intercala(int inicio, int meio, int fim, int v[]){
    int i, j, k, *w;
    w = malloc ((fim-inicio) * sizeof(int));
    i = inicio;
    j = meio;
    k = 0;
    while (i<meio && j<fim){
        if(v[i] <= v[j]){
            w[k++] = v[i++];
        } else{
            w[k++] = v[j++];
        }
    }
    while (i<meio) w[k++] = v[i++];
    while (j<fim) w[k++] = v[j++];

    for (i=inicio; i<fim; i++){
        v[i] = w[i-inicio];
    }
    free(w);
}

void mergesort(int v[], int inicio, int fim){
    int meio; 
    if (inicio<fim-1){
        meio = (inicio+fim)/2;

        //chama a função para as duas metades.
        mergesort(v, inicio, meio);
        mergesort(v, meio, fim);

        //intercala as duas metades ordenadas.
        intercala(inicio, meio, fim, v);
    }
}

int main(){
    clock_t t; //variável para armazenar tempo
    int vetor[TAM];
    
    //semente de aleatoriedade
    srand((unsigned)time(NULL));

    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    //Verificando tempo de execução do insertion sort=> t2
    t = clock(); //armazena tempo
    mergesort(vetor, 0, TAM);
    t = clock() - t; //tempo final - tempo 

    //imprime o tempo na tela
    printf("Tempo de execucao do MergeSort: %lf s\n", ((double)t)/((CLOCKS_PER_SEC))); //conversão para double

    return 0;
}
