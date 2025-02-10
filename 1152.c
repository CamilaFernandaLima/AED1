//Camila Fernanda e Silva Lima - RA: 176165
//Estradas Escuras

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vi, vf, peso;
} ARESTA;

typedef struct {
    int *pai, *aux;
} UNIONFIND;

int compara(const void *a, const void *b) {
    return ((ARESTA*)a)->peso - ((ARESTA*)b)->peso;
}

UNIONFIND *criaUnionFind(int n) {
    UNIONFIND *uf = malloc(sizeof(UNIONFIND));
    uf->pai = malloc(n * sizeof(int));
    uf->aux = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->pai[i] = i;
        uf->aux[i] = 0;
    }
    return uf;
}

int find(UNIONFIND *uf, int v) {
    if (uf->pai[v] != v)
        uf->pai[v] = find(uf, uf->pai[v]);
    return uf->pai[v];
}

void unionSets(UNIONFIND *uf, int a, int b) {
    a = find(uf, a);
    b = find(uf, b);
    if (a != b) {
        if (uf->aux[a] < uf->aux[b])
            uf->pai[a] = b;
        else if (uf->aux[a] > uf->aux[b])
            uf->pai[b] = a;
        else {
            uf->pai[b] = a;
            uf->aux[a]++;
        }
    }
}

int kruskal(ARESTA *arestas, int m, int n) {
    qsort(arestas, n, sizeof(ARESTA), compara);
    UNIONFIND *uf = criaUnionFind(m);
    int totalMST = 0, edgesUsed = 0;
    
    for (int i = 0; i < n && edgesUsed < m - 1; i++) {
        if (find(uf, arestas[i].vi) != find(uf, arestas[i].vf)) {
            unionSets(uf, arestas[i].vi, arestas[i].vf);
            totalMST += arestas[i].peso;
            edgesUsed++;
        }
    }
    
    free(uf->pai);
    free(uf->aux);
    free(uf);
    return totalMST;
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) && (m || n)) {
        ARESTA *arestas = malloc(n * sizeof(ARESTA));
        int total = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].vi, &arestas[i].vf, &arestas[i].peso);
            total += arestas[i].peso;
        }
        
        printf("%d\n", total - kruskal(arestas, m, n));
        free(arestas);
    }
    return 0;
}
