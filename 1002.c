//Camila Fernanda e Silva Lima - RA: 176.165
//Área do Círculo

#include <stdio.h>
 
int main () {
    
    double raio, area;
    scanf("%lf", &raio);
    area = 3.14159 * (raio * raio);
    
    printf("A=%.4lf\n", area);

    return 0;
}

