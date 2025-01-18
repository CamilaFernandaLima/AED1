//Camila Fernanda e Silva Lima - RA: 176.165
//Pares e Ímpares 

#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para trocar elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Particionar o array para o Quick Sort
int particionar(int *v, int inicio, int fim, int crescente) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if ((crescente && v[j] <= pivo) || (!crescente && v[j] >= pivo)) {
            i++;
            trocar(&v[i], &v[j]);
        }
    }
    trocar(&v[i + 1], &v[fim]);
    return i + 1;
}

// Função Quick Sort
void quicksort(int *v, int inicio, int fim, int crescente) {
    if (inicio < fim) {
        int pivo = particionar(v, inicio, fim, crescente);
        quicksort(v, inicio, pivo - 1, crescente);
        quicksort(v, pivo + 1, fim, crescente);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *pares = malloc(n * sizeof(int));
    int *impares = malloc(n * sizeof(int));

    int num_pares = 0, num_impares = 0;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0) {
            pares[num_pares++] = x;
        } else {
            impares[num_impares++] = x;
        }
    }

    quicksort(pares, 0, num_pares - 1, 1);
    quicksort(impares, 0, num_impares - 1, 0);

    for (int i = 0; i < num_pares; i++) {
        printf("%d\n", pares[i]);
    }
    for (int i = 0; i < num_impares; i++) {
        printf("%d\n", impares[i]);
    }

    free(pares);
    free(impares);

    return 0;
}
