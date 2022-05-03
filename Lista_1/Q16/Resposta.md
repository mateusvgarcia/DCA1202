Procure na internet mecanismos que possibilitem medir tempos de execução de rotinas
computacionais. Geralmente, estas medidas são realizadas com o auxílio de funções em C que
lêem a hora no sistema (sistemas Unix e Windows geralmente usam funções diferentes).
Utilizando os conhecimentos que você obteve com sua pesquisa, meça os tempos de execução
das implementações que você criou para os dois problemas de ordenação anteriores e compare
os resultados obtidos.


~~~c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10000

int RandomInteger(int low, int high)
{
    int k;
    srand( (unsigned)time(NULL) );
    k = (rand() % high) + low;
    return k;
}

void bubbleSort (int v[TAM]) {
    int a, b, aux;
    for (a=TAM-1; a>=1; a--) {
        for (b=0; b<a; b++) {
            if (v[b]>v[b+1]) {
                aux = v[b];
                v[b] = v[b+1];
                v[b+1] = aux;
            }
        }
    }
}

int main(){
 clock_t t; //variável para armazenar tempo
 int vetor[TAM]; //vetor com 10000 posições
 int p, r, a;
 p = 0;
 r = TAM;

  //geração aleatório dos valores do vetor
 for(a = 0; a < TAM; a++)
  vetor[a] = RandomInteger(0, TAM);

    //Verificando tempo de execução do bubble sort=> t2
 t = clock(); //armazena tempo
 bubbleSort(vetor);
 t = clock() - t; //tempo final - tempo inicial
 //imprime o tempo na tela
 printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
}

~~~

#### Resposta

> O mecanismo QSORT é o mais rapido para ordenação