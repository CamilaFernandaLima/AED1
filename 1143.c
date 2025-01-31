//Camila Fernanda e Silva Lima - RA: 176.165
//Quadrados e cubos

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        printf("%d %d %d\n", i, i*i, i*i*i);
    }

    return 0;
}
