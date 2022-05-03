Reimplemente o programa da questão anterior utilizando a função qsort() do C. Comente o seu
código, explicando o que faz cada uma das linhas.

~~~c
#include <stdio.h>
#include <stdlib.h>

int comparador(const void *a, const void *b) {
   return ( *(int*)a - *(int*)b );
}

int comparador2(const void *a, const void *b) {
   if (*(int*)a > *(int*)b) {
      return 1;
   } else if (*(int*)a < *(int*)b) {
      return -1;
   } else {
      return 0;
   }
}

int main () {
   int i, val[] = { 15, 30, 10, 20, 25 }; // valores para serem organizados

   qsort(val, 5, sizeof(int), comparador); // chama função qsort para ordenar a array

   for( i = 0 ; i < 5; i++ ) {
      printf("%i ", val[i]);  //printa o array
   }

   return(0);
}

~~~