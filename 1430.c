//Camila Fernanda e Silva Lima - RA: 176.165
//Composição de Jingles

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char entrada[300];
    char *token;
    
    while(1){
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        if(strcmp(entrada, "*") == 0) break;

        token = strtok(entrada, "/");
        int cont = 0;

        while (token != NULL){
            float time = 0;

            for(int i=0; token[i] != '\0'; i++){
                switch ((token[i])){
                    case 'W': time += 1; break;
                    case 'H': time += 0.5; break;
                    case 'Q': time += 0.25; break;
                    case 'E': time += 0.125; break;
                    case 'S': time += 0.0625; break;
                    case 'T': time += 0.03125; break;
                    case 'X': time += 0.015625; break;
                
                }
            }
            if (time == 1.0){
                cont++;
            }
            token = strtok(NULL, "/");
        }

        printf("%d\n", cont);
    }

    return 0;

}
