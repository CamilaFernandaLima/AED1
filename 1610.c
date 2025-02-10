//Camila Fernanda e Silva Lima - RA: 176165
//Dudu Faz Serviço

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct cel {
    int vertice;
    struct cel *prox;
} ADJ;

typedef struct ver{
    ADJ *cabeca;
} VERTICE;

typedef struct gr{
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;

GRAFO *criagrafo(int v){
    GRAFO *g = malloc(sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = malloc(v * sizeof(VERTICE));
    for(int i=0; i<v; i++){
        g->adj[i].cabeca = NULL;
    }
    return g;
}

ADJ *criaadj(int v){
    ADJ *temp = malloc(sizeof(ADJ));
    temp->vertice = v;
    temp->prox = NULL;
    return temp;
}

void criaAresta(GRAFO *g, int vi, int vf){
    ADJ *novo = criaadj(vf);
    novo->prox = g->adj[vi].cabeca;
    g->adj[vi].cabeca = novo;
    g->arestas++;
}

bool dfs(GRAFO *g, int v, int *visitado) {
    visitado[v] = 1; 

    for (ADJ *atual = g->adj[v].cabeca; atual != NULL; atual = atual->prox) {
        int vizinho = atual->vertice;
        if (visitado[vizinho] == 1) return true; // Encontramos um ciclo
        if (visitado[vizinho] == 0 && dfs(g, vizinho, visitado)) return true;
    }

    visitado[v] = 2; // Marcamos como "visitado"
    return false;
}

int main(){
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);

        GRAFO *g = criagrafo(n);
        int *visitado = calloc(n, sizeof(int));

        for(int i=0; i<m; i++){
            int a,b;
            scanf("%d %d", &a, &b);
            criaAresta(g, a-1, b-1);
        }

        bool ciclo = false;
        for(int i=0; i<n; i++){
            if(visitado[i] == 0 &&dfs(g, i, visitado)){
                ciclo = true; 
                break;
            }
        }

        if(ciclo){
            printf("SIM\n");
        } else 
            printf("NAO\n");
    }
    return 0;
}
