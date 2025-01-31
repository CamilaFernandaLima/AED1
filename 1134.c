//Camila Fernanda e Silva Lima - RA: 176.165
//Tipo de Combustível

#include <stdio.h>

int main(){
    int valor, a = 0, g = 0, d = 0;
    
    do{
        scanf("%d", &valor);
        switch (valor)
        {
        case 1:
            a += 1;
            break;
        case 2:
            g += 1;
            break;
        case 3:
            d += 1;
            break;
        }
    } while (valor != 4);

    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\nGasolina: %d\nDiesel: %d\n", a, g, d);
}
