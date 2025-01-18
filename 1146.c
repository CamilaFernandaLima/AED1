//Camila Fernanda e Silva Lima - RA: 176.165
//Sequências Crescentes

#include <stdio.h>

int main(){
    while(1){
        int x;
        scanf("%d", &x);
        if(x != 0){
            for(int i=1; i<x; i++) printf("%d ", i);
        } else{
            return 0;
        }
        printf("%d\n", x);
    } 
    
}
