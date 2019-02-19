### Aula 1 - 14/02

#### Navegação no terminal

| Comando                | Função                                                       |
| ---------------------- | ------------------------------------------------------------ |
| cd *ex_diretorio*      | Acessa o diretório de nome "ex_diretorio".                   |
| cd ..                  | Volta para diretório anterior.                               |
| clear                  | Limpa terminal.                                              |
| ls                     | Exibe conteúdo do diretório.                                 |
| touch *ex_arquivo.cpp* | Cria arquivo com o nome "ex_arquivo" e extensão .cpp         |
| gedit *ex_arquivo.cpp* | Abre com o gedit (editor de texto padrão) o arquivo "ex_arquivo.cpp" |

#### Estrutura de um programa em C++

``` c++
//Inclusão de bibliotecas, como por exemplo a stdio.h
#include <stdio.h>

// Declaração da função principal
int main() {
    // Inserir código aqui:
    
	return 0;
}
```

1. Bibliotecas: uma coleção de classes, funções e variáveis escritas na própria linguagem para facilitar o desenvolvimento de aplicações. ([Wikipédia](https://pt.wikipedia.org/wiki/Biblioteca_padr%C3%A3o_do_C%2B%2B))
2. Função principal: serve como o ponto de partida para a execução do programa. Em geral, ela controla a execução direcionando as chamadas para outras funções no programa. ([Microsoft docs](https://docs.microsoft.com/en-us/cpp/c-language/main-function-and-program-execution?view=vs-2017))

#### Bibliotecas

​	Existem algumas bibliotecas que são bastante utilizadas, como:

| Biblioteca | Algumas funções                          |
| ---------- | ---------------------------------------- |
| stdio.h    | printf, scanf, getc, gets, fopen, fclose |
| math.h     | sqrt, sin, cos, tan, log10               |
| iostream   | cin, cout                                |

#### Tipos de variáveis

| Variável  | Tamanho | Alcance                                                  |
| --------- | ------- | -------------------------------------------------------- |
| bool      | 1 byte  | 0 ou 1                                                   |
| char      | 1 byte  | Caracteres                                               |
| int       | 4 bytes | $-2.10^{9}$ a $2.10^{9}$                                 |
| long long | 8 bytes | $-9.10^{18}$ a $9.10^{18}$                               |
| float     | 4 bytes | $-1.10^{37}$ a $1.10^{37}$                               |
| double    | 8 bytes | $-1.10^{37}$ a $1.10^{37}$, porém mais preciso que float |

#### Escrita e leitura: printf/scanf

#### printf

```c++
#include <stdio.h>

int main() {
	printf("Ola GRUB!\n");
	return 0;
}
```

É possível, também, imprimir valores de variáveis utilizando o símbolo % seguido de um caractere.

```c++
#include <stdio.h>

int main() {
	int x = 3;
	printf("x = %d\n", x);
	return 0;
}
```

#### scanf

```c++
#include <stdio.h>

int main() {
	int x;
	scanf("%d", &x);
	printf("x = %d\n", x);
	return 0;
}
```
| Variável  | Caractere |
| --------- | --------- |
| char      | c         |
| int       | d         |
| long long | lld       |
| float     | f         |
| double    | lf        |

#### Operadores

Seja a = 1,  b = 2 e c = 3.

| Operador |                  |
| -------- | ---------------- |
| +        | Soma             |
| -        | Subtração        |
| /        | Divisão          |
| *        | Multiplicação    |
| %        | Resto da divisão |

Uma propriedade interessante da divisão é que, para variáveis do tipo **int**, caso haja um valor decimal ele é ignorado, por exemplo:

```c++
#include <stdio.h>

int main() {
	int a = 3, b = 2;
	int v = a/b;
	printf("a/b = %d\n", v); // a/b = 1
}
```

Mesmo v sendo um double o valor de v é o mesmo! 

```c++
#include <stdio.h>

int main() {
	int a = 3, b = 2;
	double v = a/b;
	printf("a/b = %lf\n", v); // a/b = 1.000000
}
```

Para que o valor seja dado corretamente é necessário que seja feito um *cast*, ou seja, é necessário que forcemos o tipo de dado resultante em a/b.

```c++
#include <stdio.h>

int main() {
	int a = 3, b = 2;
	double v = (double)a/b;
	printf("a/b = %lf\n", v); // a/b = 1.500000
}
// é possivel limitar o número de casas decimais escrevendo:
// printf("a/b = %.2lf, v);
// assim, estaremos limitando em 2 casas o valor que é impresso.
```

#### Condicionais: if/else

#### if

​	O condicional **if** executa certo trecho de código se determinada condição for cumprida.

```c++
#include <stdio.h>

int main() {
	int x;
	scanf("%d", &x);
	if(x == 3) {
       // Se x for igual a 3, executa o código abaixo
		printf("x eh igual a 3\n");
	}
	return 0;
}
```

```c++
#include <stdio.h>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if(x > 3) {
       // Se x for maior que 3, executa o código abaixo
		printf("x eh maior que 3\n");
       if(x + y < 5) {
           // Se x+y for menor que 5, executa o código abaixo
           printf("x+y eh menor que 5\n");
       }
	}
	return 0;
}
```

Operações que podem ser feitas dentro do if:

| Operador |                                   |
| -------- | --------------------------------- |
| A == B   | compara se A é igual a B          |
| A != B   | compara se A é diferente de B     |
| A > B    | compara se A é maior que B        |
| A < B    | compara se A é menor que B        |
| A >= B   | compara se A é maior ou igual a B |
| A <= B   | compara se A é menor ou igual a B |

Além disso, é possivel utilizar as cláusulas **and** e **or** para inserir mais condições em um if:

```c++
#include <stdio.h>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if(x + y > 5 and x > 0 and y > 0) {
       // Se x e y forem positivos e x+y > 5, executa o código abaixo
		printf("Condicoes atendidas\n");
	}
	return 0;
}
```



#### else

Para toda condição **if** é possível inserir uma condição **else**, a qual será executada SEMPRE que a condição **if** acima dela não for.

```c++
#include <stdio.h>

int main() {
	int x;
	scanf("%d", &x);
	if(x == 3) {
		printf("x é igual a 3\n");
	}
	else {
		printf("x não é igual a 3\n");
	}
	return 0;
}
```

​	Para a condição **else** não é necessário inserir parenteses, pois a sua condição de execução depende do condicional **if** acima.

#### Outros exemplos

```c++
// par ou impar?
#include <stdio.h>

int main() {
	int n;
	scanf(" %d", &n);
	if(n%2 == 0) {
		printf("Eh par\n");
    } else {
        printf("Eh impar\n");
    }
	return 0;
}
```

### Sites para treino

Segue alguns links de informações e treino.

#### Problemas para treinar

<a target="_blank" href="http://www.codcad.com/course/1">Codcad</a> (indicado para iniciantes)
<a target="_blank" href="http://wiki.maratona.dcc.ufmg.br/index.php/Roteiros">Roteiros de estudo - DCC UFMG</a> (contém alguns problemas selecionados por temas)
<a target="_blank" href="https://a2oj.com/ladders">A2 Online Judge</a> (existem centenas de problemas na aba Ladders que podem ser feitos segundo seu ranking no Codeforces)
<a target="_blank" href="http://uva.onlinejudge.org/">UVa</a> (site bugado, mas possui diversos problemas interessantes)

#### Contests

<a target="_blank" href="http://codeforces.com/">Codeforces</a> (principal site para competições curtas (2 horas))
<a target="_blank" href="http://codechef.com/">CodeChef</a>  (interessante para competições longas (alguns dias de duração))

#### Informações gerais

<a target="_blank" href="https://www.ime.usp.br/~maratona/miscelania/comecando-a-treinar">Como começar a treinar - MaratonIME</a>
<a target="_blank" href="http://maratona.ime.usp.br/">Site da Maratona de Programação</a>
<a target="_blank" href="https://chat.whatsapp.com/C3oCB2Dp7u74YL3c66vEaq">Grupo do Whats da UFABC Code</a>
<a target="_blank" href="https://drive.google.com/drive/u/0/folders/1oBH9CC8OKZ3giTRGpmkM1gCUZsFtPNLw">Drive da GRUB</a>

