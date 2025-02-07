//Camila Fernanda e Silva Lima - RA: 176.165
//Desenhando Labirintos

#include <stdio.h>

int adj[50][50];
int visitado[50];
int passos;

void dfs(int v, int n){
    visitado[v] = 1;

    for(int i=0; i<n; i++){
        if(adj[v][i] == 1){
            passos++;
            adj[v][i] = adj[i][v] = 0;
            dfs(i, n);
            passos++;
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int inicio, n, m;
        scanf("%d", &inicio);
        scanf("%d %d", &n, &m);

        for (int i = 0; i <n ; i++){
            for (int j = 0; j < n; j++){
                adj[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
            visitado[i] = 0;

        passos = 0;

        for(int i=0; i<m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v] = adj[v][u] = 1;
        }

        dfs(inicio, n);
        printf("%d\n", passos);
    }
    return 0;
}
