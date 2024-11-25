//Camila Fernanda e Silva Lima - RA: 176165
//Lista de Chamada (usando MergeSort)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

void intercala(int inicio, int meio, int fim, char *nome[]){
    int i, j, k;

    char *temp[fim - inicio+1];
    i = inicio;
    j = meio+1;
    k = 0;

    while (i<=meio && j<=fim){
        if(strcmp(nome[i], nome[j]) < 0){
            temp[k++] = nome[i++];
        } else{
            temp[k++] = nome[j++];
        }
    }
    while (i<=meio) temp[k++] = nome[i++];
    while (j<=fim) temp[k++] = nome[j++];

    for (i=inicio; i<=fim; i++){
        nome[i] = temp[i-inicio];
    }
}

void mergesort(char *nome[], int inicio, int fim){
    int meio;

    if (inicio<fim){
        meio = (inicio+fim)/2;

        mergesort(nome, inicio, meio);
        mergesort(nome, meio+1, fim);
        
        intercala(inicio, meio, fim, nome);
    }
}

int main(){
    int k;

    scanf("%d", &n);
    scanf("%d", &k);
    char *nome[n];

    getchar();

    for (int i=0; i<n; i++){
        nome[i] = (char *)malloc(30 * sizeof(char));
        fgets(nome[i], 30, stdin);
        nome[i][strcspn(nome[i], "\n")] = 0;
    }

    mergesort(nome, 0, n-1);

    printf("%s\n", nome[k-1]);

    for(int i=0; i<n; i++){
        free(nome[i]);
    }

    return 0;
}
