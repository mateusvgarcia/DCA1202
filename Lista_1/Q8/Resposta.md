O que fazem os seguintes programas em C?

~~~~c
int main(){
  int vet[] = {4,9,13};
  int i;
  for(i=0;i<3;i++){
  printf("%d ",*(vet+i));
  }
}
~~~~
~~~~c
int main(){
  int vet[] = {4,9,13};
  int i;
  for(i=0;i<3;i++){
  printf("%X ",vet+i);
  }
}
~~~~


#### Reposta

> Varre o vetor printando o elemento da posição I + 1
> Varre o vetor printando o endereço da posição I + 1