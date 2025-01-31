//Camila Fernanda e Silva Lima - RA: 176.165
//Linha na Matriz

#include <stdio.h>

int main(){
    int L;
    double matriz[12][12];
    char T;

    scanf("%d %c", &L, &T);

    for (int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }

    double soma = 0.0;
    for(int i=0; i<12; i++){
        soma += matriz[L][i];
    }  
    
    if(T == 'M'){
        soma = soma/ 12.0; 
    }    

    printf("%.1f\n", soma); 
    return 0;
}
