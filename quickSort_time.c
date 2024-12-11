//Camila Fernanda e Silva Lima - RA: 176165

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int TAM; //constante para tamanho do vetor

int separa (int p, int r, int v[]){
    int c, j, k, t;
    c = v[r];
    j = p;

    for (k=p; k<r; k++){
        if(v[k] <=c){
            t = v[j];
            v[j] = v[k]; 
            v[k] = t;
            j++;
        }
    }
    v[r] = v[j];
    v[j] = c;
    return j;
}

void quicksort (int p, int r, int v[]){
    int j;
    if(p < r){
        j = separa (p,r,v);
        quicksort(p, j-1, v);
        quicksort(j+1, r, v);
    }
}

int main(){
    clock_t t; //variável para armazenar tempo

    for(TAM = 0; TAM <= 400000; TAM = TAM + 20000){
        int vetor[TAM];
        //semente de aleatoriedade
        srand((unsigned)time(NULL));

        //geração aleatório dos valores do vetor
        for(int a = 0; a < TAM; a++)
            vetor[a] = rand() % TAM;

        //Verificando tempo de execução do insertion sort=> t2
        t = clock(); //armazena tempo
        quicksort(0, TAM, vetor);
        t = clock() - t; //tempo final - tempo 

        //imprime o tempo na tela
        printf("Tempo de execucao: %lf s\n", ((double)t)/((CLOCKS_PER_SEC))); //conversão para double
    }
}
