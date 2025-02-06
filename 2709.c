//Camila Fernanda e Silva Lima - RA: 176165
//As Moedas de Robbie

#include <stdio.h>

int primo(int num){
    if(num < 2) return 0;
    for(int i=2; i*i<= num; i++){
        if(num%i == 0) return 0;
    }
    return 1;
}

int main(){
    int m, n;
    int vetor[20];

    while (scanf("%d", &m) != EOF){
        for (int i=0; i<m; i++){
            scanf("%d",&vetor[i]);
        }

        int soma = 0;
        scanf("%d", &n);

        for(int i=m-1; i>=0; i-=n){
            soma += vetor[i]; 
        }
        
        if(primo(soma)){
            printf("You’re a coastal aircraft, Robbie, a large silver aircraft.\n");
        } else{
            printf("Bad boy! I’ll hit you.\n");
        }
    
    }
    return 0;
}
