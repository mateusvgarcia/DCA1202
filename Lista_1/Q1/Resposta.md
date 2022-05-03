int i=3,j=5;
int *p, *q;
p = &i;
q = &j;

Determine o valor das seguintes expressões:
p == &i;
*p - *q;
**&p;
3 - *p/(*q) + 7;

p == &i -> __Verdadeiro__

*p - *q  => __3 - 5 => -2__

**&p  => __3__

3 - (*p/(*q)) + 7 => __3 - 0 + 7 => 10__
