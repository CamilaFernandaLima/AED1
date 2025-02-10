//Camila Fernanda e Silva Lima - RA: 176165
//Aaah!

#include <stdio.h>
#include <string.h>

int main(){
    char entrada1[1000];
    fgets(entrada1, sizeof(entrada1), stdin);

    char entrada2[1000];
    fgets(entrada2, sizeof(entrada2), stdin);

    int i, j;
    while(entrada1[i] == 'a'){
        i++;
    }
    while(entrada2[j] == 'a'){
        j++;
    }

    if(i>=j){
        printf("go\n");
    } else{
        printf("no\n");
    }
    return 0;
}
