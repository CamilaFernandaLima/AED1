//Camila Fernanda e Silva Lima - RA: 176.165
//Notas da Prova 

#include <stdio.h>

int main(){
    int nota;
    scanf("%d", &nota);

    if(nota == 0){
        printf("E\n");
    }
    else if(1 <= nota && nota < 36){
        printf("D\n");
    }
    else if(36 <= nota && nota < 61){
        printf("C\n");
    }
    else if(61 <= nota && nota < 86){
        printf("B\n");
    }
    else if(86 <= nota && nota < 100){
        printf("A\n");
    }

    return 0;
}
