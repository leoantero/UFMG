/*
 Laboratorio 1 - Atividade 4

 * PDS1 - Turma  TW
 * Aluno: Leonardo Mendes Antero

*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int x, y, z, a, b, c, d, e;

   scanf("%d", &x);
   y = x/100;
   x %= 100;

   z = x/50;
   x %= 50;

   a = x/20;
   x %= 20;

   b = x/10;
   x %=10;

   c = x/5;
   x %= 5;

   d = x/2;
   x %= 2;

   e = x;

    printf("100: %d\n", y);
    printf("50: %d\n", z);
    printf("20: %d\n", a);
    printf("10: %d\n", b);
    printf("5: %d\n", c);
    printf("2: %d\n", d);
    printf("1: %d\n", e);

    return 0;
}
