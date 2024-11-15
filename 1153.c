//Camila Fernanda e Silva Lima - RA: 176.165
//Fatorial

#include <stdio.h>

int fat(n){

    int fatorial;
    fatorial = n;

    if(0<n<13){
        for (int i=1; i<n; i++){
            fatorial = fatorial * (n-i);
        } 
    }

    return fatorial;
}

int main(){
    int n, f;
    scanf("%i", &n);

    f = fat(n);
    printf("%i\n", f);

    return 0;
}
