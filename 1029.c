//Camila Fernanda e Silva Lima - RA: 176.165
//Fibonacci, Quantas Chamadas?

#include <stdio.h>

int calls; 

int fibonacci(int num){
    calls++;
    if (num == 0){
        return 0;
    } else if(num == 1){
        return 1;
    } else{
        return fibonacci(num-1) + fibonacci(num-2);
    }
}

int main(){
    int x,num;
    
    scanf("%d", &x);
    for (int i=0; i<x; i++){
        calls = -1;
        scanf("%d", &num);
        int result = fibonacci(num);
        printf("fib(%d) = %d calls = %d\n", num, calls, result);    
    }
    
    return 0;
}
