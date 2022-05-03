Se i e j são variáveis inteiras e p e q ponteiros para int, quais das seguintes expressões de
atribuição são ilegais?

```c
    p = i;
    q = &j;
    p = &*&i;
    i = (*&)j;
    i = *&j;
    i = *&*&j;
    q = *p;
    i = (*p)++ + *q;
```

#### Resposta

> p = 1 é ilegal
> p = *p é ilegal
> i = (*&)j é ilegal
> q = *p é ilegal