//Camila Fernanda e Silva Lima - RA: 176.165
//Salário

#include <stdio.h>

int main(){
    int num, h;
    float valor, salario;

    scanf("%d", &num);
    scanf("%d", &h);
    scanf("%f", &valor);
    salario = h*valor;

    printf("NUMBER = %d\nSALARY = U$ %.2f\n", num, salario);

}
