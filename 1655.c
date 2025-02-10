//Camila Fernanda e Silva Lima - RA: 176165
//106 Milhas Para Chicago

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 100
#define INF 0

// Estrutura para a lista de adjacência
typedef struct cel {
    int ver;
    double prob;
    struct cel *prox;
} ADJ;

typedef struct {
    ADJ *cabeca;
} VERTICE;

typedef struct {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;

GRAFO *criaGrafo(int v) {
    GRAFO *g = malloc(sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = malloc(v * sizeof(VERTICE));
    
    for (int i = 0; i < v; i++) {
        g->adj[i].cabeca = NULL;
    }
    return g;
}

ADJ *criaAdj(int v, double prob) {
    ADJ *novo = malloc(sizeof(ADJ));
    novo->ver = v;
    novo->prob = prob;
    novo->prox = NULL;
    return novo;
}

void criaAresta(int vi, int vf, double prob, GRAFO *g) {
    ADJ *novo = criaAdj(vf, prob);
    novo->prox = g->adj[vi].cabeca;
    g->adj[vi].cabeca = novo;
    
    novo = criaAdj(vi, prob);
    novo->prox = g->adj[vf].cabeca;
    g->adj[vf].cabeca = novo;
    
    g->arestas++;
}

double caminhoMaisSeguro(GRAFO *g, int origem, int destino) {
    double prob[MAX_VERTICES];
    bool visitado[MAX_VERTICES] = {false};
    
    for (int i = 0; i < g->vertices; i++) {
        prob[i] = INF;
    }
    prob[origem] = 1.0;
    
    for (int i = 0; i < g->vertices; i++) {
        int u = -1;
        double maxProb = INF;
        
        for (int j = 0; j < g->vertices; j++) {
            if (!visitado[j] && prob[j] > maxProb) {
                maxProb = prob[j];
                u = j;
            }
        }
        
        if (u == -1) break;
        visitado[u] = true;
        
        for (ADJ *atual = g->adj[u].cabeca; atual != NULL; atual = atual->prox) {
            int v = atual->ver;
            double novaProb = prob[u] * (atual->prob / 100.0);
            
            if (novaProb > prob[v]) {
                prob[v] = novaProb;
            }
        }
    }
    
    return prob[destino] * 100.0;
}

int main() {
    int n, m;
    
    while (scanf("%d %d", &n, &m) && n != 0) {
        GRAFO *g = criaGrafo(n);
        
        for (int i = 0; i < m; i++) {
            int a, b, p;
            scanf("%d %d %d", &a, &b, &p);
            criaAresta(a - 1, b - 1, p, g);
        }
        
        double resultado = caminhoMaisSeguro(g, 0, n - 1);
        printf("%.6lf percent\n", resultado);
        
        free(g);
    }
    
    return 0;
}
