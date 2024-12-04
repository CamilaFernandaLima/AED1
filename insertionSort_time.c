//Camila Fernanda e Silva Lima - RA: 176.165

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int const TAM = 400000; //constante para tamanho do vetor

void InsertionSort (int v[]) {
    int i, j, x;
    for (j = 1; j < TAM; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--){
            v[i+1] = v[i];
        }
        v[i+1] = x;
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
    InsertionSort(vetor);
    t = clock() - t; //tempo final - tempo 

    //imprime o tempo na tela
    printf("Tempo de execucao do InsertionSort: %lf s\n", ((double)t)/((CLOCKS_PER_SEC))); //conversão para double

    return 0;
}
