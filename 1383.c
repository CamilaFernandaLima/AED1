//Camila Fernanda e Silva Lima - RA: 176.165
//Sudoku

#include <stdio.h>
#include <stdbool.h>

bool verifica(int matriz[9][9]) {
    int existe[10]; // Array para rastrear números de 1 a 9

    // Verifica linhas e colunas
    for (int i = 0; i < 9; i++) {
	    
        // Verifica linha
        for (int j = 1; j <= 9; j++) existe[j] = false;
        for (int j = 0; j < 9; j++) {
            if (matriz[i][j] >= 1 && matriz[i][j] <= 9) {
                if (existe[matriz[i][j]]) return false; // Duplicado
                existe[matriz[i][j]] = true; // Marca como existente
            }
        }

        // Verifica coluna
        for (int j = 1; j <= 9; j++) existe[j] = false;
        for (int j = 0; j < 9; j++) {
            if (matriz[j][i] >= 1 && matriz[j][i] <= 9) {
                if (existe[matriz[j][i]]) return false; // Duplicado
                existe[matriz[j][i]] = true; // Marca como existente
            }
        }
    }

    // Verifica submatrizes 3x3
    for (int subi = 0; subi < 3; subi++) {
        for (int subj = 0; subj < 3; subj++) {
            for (int j = 1; j <= 9; j++) existe[j] = false;
            for (int i = subi * 3; i < subi * 3 + 3; i++) {
                for (int j = subj * 3; j < subj * 3 + 3; j++) {
                    if (matriz[i][j] >= 1 && matriz[i][j] <= 9) {
                        if (existe[matriz[i][j]]) return false; // Duplicado
                        existe[matriz[i][j]] = true; // Marca como existente
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
