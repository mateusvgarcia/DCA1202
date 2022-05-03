Determine o que será mostrado pelo seguinte programa (compile-o, execute-o e verifique se
foram obtidas as respostas esperadas).

~~~~c

int main(void){
  float vet[5] = {1.1,2.2,3.3,4.4,5.5};
  float *f;
  int i;
  f = vet;
  printf("contador/valor/valor/endereco/endereco");
  for(i = 0 ; i <= 4 ; i++){
  printf("\ni = %d",i);
  printf("vet[%d] = %.1f",i, vet[i]);
  printf("*(f + %d) = %.1f",i, *(f+i));
  printf("&vet[%d] = %X",i, &vet[i]);
  printf("(f + %d) = %X",i, f+i);
  }
}

~~~~

#### Resposta

> __contador/valor/valor/endereco/endereco__
> __i = 0vet[0] = 1.1*(f + 0) = 1.1&vet[0] = C2475070(f + 0) = C2475070__
> __i = 1vet[1] = 2.2*(f + 1) = 2.2&vet[1] = C2475074(f + 1) = C2475074__
> __i = 2vet[2] = 3.3*(f + 2) = 3.3&vet[2] = C2475078(f + 2) = C2475078__
> __i = 3vet[3] = 4.4*(f + 3) = 4.4&vet[3] = C247507C(f + 3) = C247507C__
> __i = 4vet[4] = 5.5*(f + 4) = 5.5&vet[4] = C2475080(f + 4) = C2475080__