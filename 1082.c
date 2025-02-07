//Camila Fernanda e Silva Lima - RA: 176165
//Componentes Conexos

#include <stdio.h>
#include <stdlib.h>

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

    ADJ *novo2 = criaadj(vi);
    novo2->prox = g->adj[vf].cabeca;
    g->adj[vf].cabeca = novo2;
    g->arestas++;
}

int visitado[26]; // Máximo de 26 vértices (a-z)
char componente[26];
int tamanho;

void dfs(GRAFO *g, int v) {
    visitado[v] = 1;
    componente[tamanho++] = v + 'a';

    ADJ *aux = g->adj[v].cabeca;
    while (aux) {
        if (!visitado[aux->vertice]) {
            dfs(g, aux->vertice);
        }
        aux = aux->prox;
    }
}

int main(){
    int n, caso = 1;;
    scanf("%d", &n);

    while (n--){
        int v,e;
        scanf("%d %d", &v, &e);
        GRAFO *g = criagrafo(v);

        for(int j = 0; j<e; j++){
            char i,f;
            scanf(" %c %c", &i, &f);
            criaAresta(g, i - 'a', f - 'a');
        }

        
        printf("Case #%d:\n", caso);
        int componentes = 0;
        for(int i=0; i<v; i++){
            visitado[i] = 0;
        }

        for (int i = 0; i < v; i++) {
            if (!visitado[i]) {
                tamanho = 0;
                dfs(g, i);

                for (int j = 0; j < tamanho - 1; j++) {
                    for (int k = j + 1; k < tamanho; k++) {
                        if (componente[j] > componente[k]) {
                            char temp = componente[j];
                            componente[j] = componente[k];
                            componente[k] = temp;
                        }
                    }
                }
                for (int j = 0; j < tamanho; j++) {
                    printf("%c,", componente[j]);
                }
                printf("\n");
                componentes++;
            }
        }
        printf("%d connected components\n", componentes);
        printf("\n");
        caso++; 
    }
    return 0;
}
