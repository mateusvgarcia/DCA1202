#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char **mat;
    int x, y;
    x = 8;
    y = 8;

    mat = malloc(x * sizeof(unsigned char *));

    for (int i = 0; i < x; i++)
    {
        mat[i] = malloc(y * sizeof(unsigned char));
        for (int j = 0; j < y; j++)
        {
            mat[i][j] = rand() % 2; // gera um número aleatório entre 0 e 1
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d", mat[i][j]); // imprime o valor da matriz
            // printf("%d", (i >> j) & 0x01U); // imprime o valor da matriz
        }
        printf(" ");
    }

    for (int i = 0; i < x; i++)
    {
        free(mat[i]); // libera a memória alocada para a matriz
    }
    free(mat); // libera a memória alocada para a matriz

    return 0;
}

// clear && gcc -o q2 q2.c && ./q2