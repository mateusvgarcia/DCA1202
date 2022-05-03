Suponha que as seguintes declarações tenham sido realizadas:

~~~~c
    float aloha[10], coisas[10][5], *pf, value = 2.2;
    int i=3;
~~~~
Identifique quais dos seguintes comandos é válido ou inválido:

~~~~c
    aloha[2] = value;
    scanf("%f", &aloha);
    aloha = value";
    printf("%f", aloha);
    coisas[4][4] = aloha[3];
    coisas[5] = aloha;
    pf = value;
    pf = aloha;
~~~~

#### Resposta

> Válido
> Válido
> Inválido
> Válido
> Válido
> Válido
> Inválido
> Válido