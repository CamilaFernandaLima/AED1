//Camila Fernanda e Silva Lima - RA: 176165
//Polícia e Ladrão

#include <stdio.h>
#include <stdlib.h>

#define N 5
#define TRUE 1
#define FALSE 0

// Estrutura para representar um ponto na matriz
typedef struct {
    int x, y;
} Ponto;

// Movimentos possíveis (cima, baixo, esquerda, direita)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Função para verificar se uma posição é válida
int posicaoValida(int x, int y, int labirinto[N][N], int visitado[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && labirinto[x][y] == 0 && !visitado[x][y]);
}

// Função BFS para verificar se há um caminho até (4,4)
int bfs(int labirinto[N][N]) {
    int visitado[N][N] = {0};
    Ponto fila[N * N];
    int frente = 0, tras = 0;
    
    // Começa a busca na posição (0,0)
    fila[tras++] = (Ponto){0, 0};
    visitado[0][0] = TRUE;
    
    while (frente < tras) {
        Ponto atual = fila[frente++];
        
        // Se chegarmos ao destino, a polícia vence
        if (atual.x == 4 && atual.y == 4) {
            return TRUE;
        }
        
        // Testa todos os movimentos possíveis
        for (int i = 0; i < 4; i++) {
            int nx = atual.x + dx[i];
            int ny = atual.y + dy[i];
            
            if (posicaoValida(nx, ny, labirinto, visitado)) {
                fila[tras++] = (Ponto){nx, ny};
                visitado[nx][ny] = TRUE;
            }
        }
    }
    
    return FALSE;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int labirinto[N][N];
        
        // Lendo a matriz 5x5
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &labirinto[i][j]);
            }
        }
        
        // Verifica se a polícia consegue alcançar (4,4)
        if (bfs(labirinto)) {
            printf("COPS\n");
        } else {
            printf("ROBBERS\n");
        }
    }
    
    return 0;
}
