//Camila Fernanda e Silva Lima - RA: 176.165
//Desvio de Rota

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cidade, custo;
} no;

typedef struct {
    no heap[250*250];
    int tamanho;
} mheap;

void inicializaHeap (mheap *h){
    h->tamanho = 0;
}

void insereHeap (mheap *h, int cidade, int custo){
    int i = h->tamanho++;

    while(i > 0 && custo < h->heap[(i-1)/2].custo){
        h->heap[i] = h->heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->heap[i].cidade = cidade;
    h->heap[i].custo = custo;
}

no removeHeap (mheap *h){
    no raiz = h->heap[0];
    no ultimo = h->heap[--h->tamanho];
    int i=0, filho;

    while(2*i + 1 < h->tamanho){
        filho = 2*i + 1;

        if (filho + 1 < h->tamanho && h->heap[filho+1].custo < h->heap[filho].custo){
            filho++;
        }

        if(ultimo.custo <= h->heap[filho].custo) break;
        h->heap[i] = h->heap[filho];
        i = filho;
    }
    h->heap[i] = ultimo;
    return raiz;
}

int dijkstra (int N, int C, int K, int grafo[250][250]){
    mheap heap;
    inicializaHeap(&heap);

    int dist[250];
    for(int i=0; i<N; i++){
        dist[i] = __INT_MAX__; 
    }

    dist[K] = 0;
    insereHeap(&heap, K, 0);

    while(heap.tamanho > 0){
        no atual;
        atual = removeHeap(&heap);
        int cidade = atual.cidade;
        int custo = atual.custo;

        if (cidade == C-1) return custo;
        if (custo > dist[cidade]) continue; //caminho ignorado.

        if (cidade < C-1){
            int prox = cidade + 1;
            if(dist[prox] > custo + grafo[cidade][prox]){
                dist[prox] = custo + grafo[cidade][prox];
                insereHeap(&heap, prox, dist[prox]);
            }
        }

        else{
            for(int vizinho=0; vizinho<N; vizinho++){
                if(grafo[cidade][vizinho] != __INT_MAX__){
                    int novo = custo + grafo[cidade][vizinho];
                    if(dist[vizinho] > novo){
                        dist[vizinho] = novo;
                        insereHeap(&heap, vizinho, novo);
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    int N, M, C, K;
    while(1){
        scanf("%d %d %d %d", &N, &M, &C, &K);
        if (N==0 && M==0 && C==0 && K==0) break;

        int grafo[250][250];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                grafo[i][j] = __INT_MAX__;
            }
        }

        for(int i=0; i<M; i++){
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);
            grafo[U][V] = P;
            grafo[V][U] = P;
        }
        int resultado = dijkstra(N, C, K, grafo);
        printf("%d\n", resultado);
    }
    return 0;
}
