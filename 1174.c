//Camila Fernanda e Silva Lima - RA: 176165
//Seleção em Vetor I

#include <stdio.h>

int main() {
    float A[100];  
    float a;       

    for (int i = 0; i < 100; i++) {
        scanf("%f", &a);  
        A[i] = a;         
    }

    for (int i = 0; i < 100; i++) {
        if (A[i] <= 10) { 
            printf("A[%d] = %.1f\n", i, A[i]);  
        }
    }

    return 0;
}
