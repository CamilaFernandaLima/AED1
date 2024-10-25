//Camila Fernanda e Silva Lima - RA: 176165
//Sudoku

#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool verifica(int matriz[SIZE][SIZE]) {
    int existe[SIZE + 1]; // Rastreia números de 1 a 9

    // Verifica linhas e colunas
    for (int i = 0; i < SIZE; i++) {
        // Verifica linha
        for (int j = 1; j <= SIZE; j++) existe[j] = false;
        for (int j = 0; j < SIZE; j++) {
            if (matriz[i][j] >= 1 && matriz[i][j] <= 9) {
                if (existe[matriz[i][j]]){
                  return false; // Indica que é duplicado
                } else existe[matriz[i][j]] = true; // Marca como existente
            }
        }

        // Verifica coluna
        for (int j = 1; j <= SIZE; j++) existe[j] = false;
        for (int j = 0; j < SIZE; j++) {
            if (matriz[j][i] >= 1 && matriz[j][i] <= 9) {
                if (existe[matriz[j][i]]){
                  return false; // Duplicado
                } else existe[matriz[j][i]] = true; // Marca como existente
            }
        }
    }

    // Verifica submatrizes 3x3
    for (int sub_i = 0; sub_i < 3; sub_i++) {
        for (int sub_j = 0; sub_j < 3; sub_j++) {
            for (int j = 1; j <= SIZE; j++) existe[j] = false;
            for (int i = sub_i * 3; i < sub_i * 3 + 3; i++) {
                for (int j = sub_j * 3; j < sub_j * 3 + 3; j++) {
                    if (matriz[i][j] >= 1 && matriz[i][j] <= 9) {
                        if (existe[matriz[i][j]]){
                          return false; // Duplicado
                        } else existe[matriz[i][j]] = true; // Marca como existente
                    }
                }
            }
        }
    }

    return true; // Se a matriz é válida
}

int main() {
    int n;
    scanf("%i", &n);

    int num = 1;
    while(num<=n){
		  int matriz[9][9];
		  int i,j;
		
		  for (i=0; i<9; i++){
			  for (j=0; j<9; j++){
				  scanf ("%i", &matriz[i][j]);
			  }
		  }       
		
      printf("Instancia %i\n", num);
      if (verifica(matriz)) {
          printf("SIM\n\n");
      } else  printf("NAO\n\n");	
		
      num++; 
    }
	
	  return 0;
}
