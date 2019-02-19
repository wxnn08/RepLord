### Aula 02

### else if

>  Na Universidade Federal do DEF existe um sistema de notas um pouco diferente criado para dificultar a vida dos estudantes: ao invés de notas de 0 a 10, os alunos são avaliados com os caracteres A, B, C, D e F. Apesar de diferente, as notas podem ser relacionadas da seguinte maneira:
>
> - $9 < A \le 10$
> - $8 < B \le 9$
> - $7 < C \le 8$
> - $6 < D \le 7$
> - $0 \le F \le 6$
>
> Guidobsky sempre estudou escolas com o sistema numérico e está tendo dificuldades para converter suas notas. Dada a nota $n$ ($0 \leq n \leq 10$) de Guidobsky, imprima o caractere que a representa nesse novo sistema.

**Primeira abordagem:**

```c++
#include<stdio.h>
int main() {
	int n;
    scanf(" %d", &n);
    if(n > 9 and n <= 10)
        printf("A");
    if(n > 8 and n <= 9)
        printf("B");
    if(n > 7 and n <= 8)
        printf("C");
    if(n > 6 and n <= 7)
        printf("D");
    if(n >= 0 and n <= 6)
        printf("F");
}
```

**Segunda abordagem:**

```c++
#include<stdio.h>
int main() {
	int n;
    scanf(" %d", &n);
    if(n <= 6)
        printf("F");
    else if(n <= 7)
        printf("D");
    else if(n <= 8)
        printf("C");
    else if(n <= 9)
        printf("B");
    else if(n <= 10)
        printf("A");
}
```

Na linguagem C++, podemos ignorar o uso das chaves `{` `}` em if's e elses. Caso optemos por isso, somente o primeiro comando após o condicional será considerado como "dentro" da condição.

Lembrando que uma vez que a condição de um `if` é verdadeira, a execução entra dentro do `if` e não continua testando os outros `else if` e `else` (A não ser que um novo `if` apareça embaixo).

### Aninhamento

Em muitos casos é útil/necessário aninhar condicionais:

```c++
// Negativo ou positivo?
#include<stdio.h>
int main() {
	int x, y;
    scanf(" %d %d", &x, &y);
    if(x < 0) {
        if(y < 0) {
            printf("x negativo, y negativo\n");
        } else {
            printf("x negativo, y positivo\n");
        }
    } else {
        if(y < 0) {
            printf("x positivo, y negativo\n");
        } else {
            printf("x positivo, y positivo\n");
        }
    }
	return 0;
}
```

### Loops

#### while

O `while` é um loop, ou seja, ele fica repetindo até que sua condição seja falsa (uma forma de interpretar o loop `while` é como um `if` que se repete).

```c++
// Contando de 0 a 10
#include<stdio.h>
int main() {
	int i = 0;
    while(i <= 10) {
        printf("%d\n", i);
        i = i+1; // incrementa o contador
    }
    return 0;
}
```



#### for

O `for` é um `while` de maneira mais organizada. O formato seu formato é:

`for(valor_inicial; condição_de_parada; valor_do_incremento)`

```c++
// Contando de 0 a n
#include<stdio.h>
int main() {
    int n;
    scanf(" %d", &n);
    for(int i = 0; i <= n; i++) {
        printf(" %d\n", i);
    }
    return 0;
}
```

### Strings



### Tipos de entradas

