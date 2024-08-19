/*
 Laboratorio 1 - Atividade 3

 * PDS1 - Turma  TW
 * Aluno: Leonardo Mendes Antero

*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int x, y, z;

   scanf("%d", &x);
   scanf("%d", &y);
   scanf("%d", &z);

  if (x % y == 0 && x % z == 0){
      printf("O número é divisível\n");
 } else {
      printf("O número não é divisível\n");
 }
 return 0;
}
