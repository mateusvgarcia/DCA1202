Mostre o que será impresso por programa supondo que i ocupa o endereço 4094 na memória.

```c
    int i=5, *p;
        p = &i;
        printf("%x %d %d %d %d", p,*p+2,**&p,3**p,**&p+4);
    }
```

#### Resposta

> 596231cc 7 5 15 9
