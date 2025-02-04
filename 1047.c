//Camila Fernanda e Silva Lima - RA: 176.165
//Tempo de Jogo com Minutos

#include <stdio.h>

int main(){
    int hi, mi, hf, mf;

    scanf("%d %d %d %d", &hi, &mi, &hf, &mf);

    int inicial = hi*60 + mi;
    int final = hf*60 + mf;

    if(final <= inicial){
        final = final + 24*60;
    }

    int total = final - inicial;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", total/60, total%60);

    return 0;
}
