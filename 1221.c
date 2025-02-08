//Camila Fernanda e Silva Lima - RA: 176165
//Primo Rápido

#include <stdio.h>

int ehprimo(int num){
    if(num<2) return 0;
    if(num == 2 || num == 3) return 1;
    if(num%2 == 0 || num%3 == 0) return 0;

    for(int i=5; i*i <= num; i++){
        if (num%i == 0 || num%(i+2) == 0) 
            return 0;
    }

    return 1;
}

int main(){
    int teste;
    scanf("%d", &teste);

    while(teste--){
       int n;
        scanf("%d", &n);

        int i = ehprimo(n);
        if(i == 1){
            printf("Prime\n");
        } else{
            printf("Not Prime\n");
        } 
    }
    return 0;
}
