//Camila Fernanda e Silva Lima - RA: 176.165

#include <stdio.h>

int main() {
    int m, n, menor, maior;
    
    scanf("%d", &m);
    scanf("%d", &n);
    
    if (m > n) {
        menor = n;
        maior = m;
    } else {
        menor = m;
        maior = n;
    }
  
    for (int i = menor + 1; i < maior; i++) {
        if (i % 5 == 3 || i % 5 == 2) {
            printf("%d\n", i);
        }
    }

    return 0;
}
