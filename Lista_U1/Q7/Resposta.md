Considerando a declaração int mat[4], *p, x;, quais das seguintes expressões são válidas?
Justifique.

~~~~c
    p = mat + 1;
    p = mat++;
    p = ++mat;
    x = (*mat)++;
~~~~


#### Resposta

> p = mat + 1 __é valida__
> x = (*mat)++ __é valida__