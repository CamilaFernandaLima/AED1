//Camila Fernanda e Silva Lima - RA: 176165
//Bem-vindos e Bem-vindas ao Inverno!

#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int mood;  

   
    if (a > b && b <= c) {
        mood = 1;  // Feliz
    }

    else if (a < b && b >= c) {
        mood = 0;  // Triste
    }
    
    else if (a < b && b < c) {
        int d = b - a;
        int e = c - b;
        if (e < d) {
            mood = 0;  // Triste
        } else {
            mood = 1;  // Feliz
        }
    }
    
    else if (a < b && b < c) {
        int d = b - a;
        int e = c - b;
        if (e >= d) {
            mood = 1;  // Feliz
        }
    }
   
    else if (a > b && b > c) {
        int d = b - a;
        int e = c - b;
        if (e > d) {
            mood = 1;  // Feliz
        } else {
            mood = 0;  // Triste
        }
    }

    else if (a > b && b > c) {
        int d = b - a;
        int e = c - b;
        if (e <= d) {
            mood = 0;  // Triste
        }
    }
    
    else if (a == b && b < c) {
        mood = 1;  // Feliz
    }
   
    else if (a == b && b >= c) {
        mood = 0;  // Triste
    }

    if (mood == 1) {
        printf(":)\n");
    } else {
        printf(":(\n");
    }

    return 0;
}
