//Camila Fernanda e Silva Lima - RA: 176165
//Ordenação por tamanho

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct {
    char entrada[51];
    int posicao;
} string;

int compare(const void *a, const void *b){
    string *str1 = (string *)a;
    string *str2 = (string *)b;

    int len1 = strlen(str1->entrada);
    int len2 = strlen(str2->entrada);

    if(len1 != len2){
        return len2 - len1;
    }

    return str1->posicao - str2->posicao;
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    
    while(n--){
        char linha[2600];
        fgets(linha, sizeof(linha), stdin);

        string palavras[50];
        int count=0;

        linha[strcspn(linha, "\n")] = '\0';

        char *token = strtok(linha, " ");
        while(token != NULL){
            strcpy(palavras[count].entrada, token);
            palavras[count].posicao = count;
            count++;

            token = strtok(NULL, " ");
        }

        qsort(palavras, count, sizeof(string), compare);

        for (int i=0; i<count; i++){
            printf("%s", palavras[i].entrada);
            if(i< count-1) printf(" ");
        }

        printf("\n");
    }
    return 0;
}
