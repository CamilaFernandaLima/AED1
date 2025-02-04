//Camila Fernanda e Silva Lima - RA: 176.165
//Imposto de Renda

#include <stdio.h>

int main(){
    double x;
    double y = 0;
    scanf("%lf", &x);

    if (x>4500.00){
        y += (x-4500)*0.28;
        x = 4500;
    }
    if(x>3000.00){
        y += (x-3000)*0.18;
        x = 3000;
    } 
    if(x>2000.00){
        y += (x-2000)*0.08;
    } 

    
    if (y == 0){
        printf("Isento\n");
    } else{
        printf("R$ %.2lf\n", y);
    }

    return 0;
}
