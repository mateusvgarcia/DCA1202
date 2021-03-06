#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int ***mat;
    int line, column, depth, r1, r2, r3, elipsoide, plan;
    int centrox, centroy, centroz;

    printf("Digite o numero de linhas: ");
    scanf("%d", &line);
    printf("Digite o numero de colunas: ");
    scanf("%d", &column);
    printf("Digite o numero de profundidade: ");
    scanf("%d", &depth);

    printf("Digite a altura da elipsoide : ");
    scanf("%d", &r1);
    printf("Digite a largura da elipsoide : ");
    scanf("%d", &r2);
    printf("Digite a profundidade da elipsoide : ");
    scanf("%d", &r3);
    printf("Digite o plano que deseja ver (use -1 para ver todos os planos): ");
    scanf("%d", &plan);
    if (plan > line || plan > column || plan > depth)
    {
        printf("O plano digitado nao existe, tente novamente\n");
        return 0;
    }

    mat = malloc(line * sizeof(int **));

    centrox = line / 2;
    centroy = column / 2;
    centroz = depth / 2;

    for (int i = 0; i < line; i++)
    {
        mat[i] = malloc(column * sizeof(int *));
        for (int j = 0; j < column; j++)
        {
            mat[i][j] = malloc(depth * sizeof(int));
            for (int k = 0; k < depth; k++)
            {
                elipsoide = (pow(i - centrox, 2) / pow(r1, 2)) + (pow(j - centroy, 2) / pow(r2, 2)) + (pow(k - centroz, 2) / (pow(r3, 2)));
                // printf("%d\n", elipsoide);
                if (elipsoide >= 1)
                {
                    mat[i][j][k] = 0;
                }
                else
                {
                    mat[i][j][k] = 1;
                }
                // mat[i][j][k] = 0;
            }
        }
    }

    if (plan == -1)
    {
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                for (int k = 0; k < depth; k++)
                {
                    printf("%d ", mat[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                {
                    printf("%d ", mat[i][j][plan]);
                }
            }
            printf("\n");
        }
    }

    free(mat);
}
