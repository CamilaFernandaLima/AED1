#include <stdio.h>

int main(){
    int n;
    scanf("%i", &n);

    int a,b,c;
    a = 0;
    b = 1;
    if (0<n<46){
        for (int i = 0; i<n; i++){
            if(i == 0){
                printf("%i", a);
            } else if(i == 1){
                printf(" %i", b);
            } else{
                c = a+b;
                printf(" %i", c);
                a = b;
                b = c;
            }
        
        }
    }

    printf("\n");
    return 0;
}
