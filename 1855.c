//Camila Fernanda e Silva Lima - RA: 176.165
//Mapa do Meistre 

#include <stdio.h>
#include <string.h>

int main(){
    int x,y,i,j, aux = 0, starti, startj;

    scanf("%d", &x);
    scanf("%d", &y);
    char matriz[100][100];

    for(i=0; i<y; i++){
        for(j=0; j<x; j++){
            scanf(" %c", &matriz[i][j]);
            if(matriz[i][j] == '*'){
                aux++;
                starti = i;
                startj = j;
            }
        }
    }

    if(aux != 1){
        printf("!\n");
        return 0;
    }

    i = starti;
    j = startj;
    

    while (i >= 0 && i<y &&  j >= 0 && j<x){
        if(matriz[i][j] == '*'){
            printf("*\n");
            return 0;
        }    

        if(matriz[i][j] == '>'){
            j++;
            while (matriz[i][j] == '.') j++;
            
        } else if(matriz[i][j] == '<'){
            j--;
            while (matriz[i][j] == '.') j--;

        } else if(matriz[i][j] == '^'){
            i--;
            while (matriz[i][j] == '.') i--;

        } else if(matriz[i][j] == 'v'){
            i++;
            while (matriz[i][j] == '.') i++;

        } else{
            printf("!\n");
            return 0;
        }
    } 
        
    printf("!\n");
    return 0;
}
