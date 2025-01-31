//Camila Fernanda e Silva Lima - RA: 176.165
//Notas e Moedas

#include <stdio.h>

void calcular(double valor){
    int notas[] = {100, 50, 20, 10, 5, 2};
    int moedas[] = {100, 50, 25, 10, 5, 1};
    int quantidade, i;

    printf("NOTAS:\n");
    for (i=0; i<6; i++){
        quantidade = (int) valor / notas[i];
        printf("%d nota(s) de R$ %.2f\n", quantidade, (double) notas[i]);
        valor = valor - quantidade * notas[i];
    }

    valor = valor*100;
    quantidade = 0;
    printf("MOEDAS:\n");
    for (i=0; i<6; i++){
        quantidade = (int) valor / moedas[i];
        printf("%d moeda(s) de R$ %.2f\n", quantidade, ((double) moedas[i]/100));
        valor = valor - quantidade * moedas[i];
    }
}

int main(){
    double valor;
    scanf("%lf", &valor);

    calcular(valor);
    return 0;
}
