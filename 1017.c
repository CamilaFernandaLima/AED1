//Camila Fernanda e Silva Lima - RA: 176.165
//Gasto de Combustível

#include <stdio.h>

int main(){
    int t, v;
    float litros;

    scanf("%d", &t);
    scanf("%d", &v);

    litros = (t*v);
    litros = litros/12;
    printf("%.3f\n litros); 

    return 0;
}
