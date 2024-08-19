#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  char x[100];
  char y, z;
  int tamanho;
  
  
  fgets(x, sizeof(x), stdin);
  tamanho = strlen(x);
    if (x[tamanho - 1] == '\n') {
        x[tamanho - 1] = '\0';
    }
   scanf("%c", &y);
   getchar();
   scanf("%c", &z);
  
  
  for(int i=0; i<strlen(x); i++) {
      if(x[i] == y) {x[i] = z; break;}
  }
  printf("%s\n", x);
  return 0; 
}