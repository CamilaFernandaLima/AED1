//Camila Fernanda e Silva Lima - RA: 176165
//Revisão de Contrato

#include <stdio.h>
#include <string.h>

int main() {
  char N[101];
  char D;      
    
  while (1) {
      scanf(" %c %s", &D, N);
      if (D == '0' && strcmp(N, "0") == 0) {
          break;
      }
       
      int len = strlen(N);
      int i, j = 0;
      char result[101]; 

      for (i = 0; i < len; i++) {
          if (N[i] != D) {
              result[j++] = N[i];
          }
      }
      result[j] = '\0'; 

      if (j == 0) {
          printf("0\n");
      } else {
          int start = 0;
          while (result[start] == '0' && result[start] != '\0') {
              start++;
          }

          if (result[start] == '\0') {
              printf("0\n");
          } else {
              printf("%s\n", &result[start]);
          }
      }
  }
    
  return 0;
}
