int i=3,j=5;
int *p, *q;
p = &i;
q = &j;

#### Determine o valor das seguintes expressões:

p == &i;
*p - *q; \**&p;
3 - *p/(\*q) + 7;

#### Respostas

> p == &i -> **Verdadeiro**

> *p - *q => **3 - 5 => -2**

> \*\*&p => **3**

> 3 - (*p/(*q)) + 7 => **3 - 0 + 7 => 10**
