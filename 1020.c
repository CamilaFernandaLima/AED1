//Camila Fernanda e Silva Lima - RA: 176.165
//Idade em dias

#include <stdio.h>
 
int main() {
    
    int dias;
    scanf ("%i", &dias);
    
    int ano, mes, dia;
    ano = dias/365;
    mes = (dias%365)/30;
    dia = ((dias%365)%30);
    
    printf ("%i ano(s)\n", ano);
    printf ("%i mes(es)\n", mes);
    printf ("%i dia(s)\n", dia);
    
    return 0;
}