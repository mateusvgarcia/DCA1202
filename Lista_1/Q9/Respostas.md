Seja x um vetor de 4 elementos, declarado da forma TIPO x[4];. Suponha que depois da
declaração, x esteja armazenado no endereço de memória 4092 (ou seja, o endereço de x[0]).
Suponha também que na máquina seja usada uma variável do tipo char ocupa 1 byte, do tipo
int ocupa 2 bytes, do tipo float ocupa 4 bytes e do tipo double ocupa 8 bytes. 
Quais serão os valores de x+1, x+2 e x+3 se:
◦ x for declarado como char?
◦ x for declarado como int?
◦ x for declarado como float?
◦ x for declarado como double?

#### Reposta
> x+1 > 4093 | 4092 | 4096 | 4100
> x+2 > 4094 | 4096 | 4098 | 4101
> x+3 > 4095 | 4097 | 4099 | 4102
