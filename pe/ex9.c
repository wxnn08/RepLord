#include<stdio.h>
#include<stdlib.h>
#define MAX_CODIGO 50
#define MAX_NOME 50

typedef struct {
	size_t ra;
	char *nome;
	float media;
} aluno_t;

typedef struct {
	char* codigo;
	int nr_alunos;
	aluno_t* alunos;
} turma_t;


// Preciso declarar todas as funções para poder utiliza-las fora de ordem
turma_t* cria_turma(int nr_alunos);
void cadastra_alunos(turma_t *turma);
void lista_turma(turma_t *turma);
void exclui_turma(turma_t *turma);

// Funcao cria turmas
turma_t* cria_turma(int nr_alunos) {
	// Crio a turma
	turma_t *turma = malloc(sizeof(turma_t));
	
	// Aloco espaço para adicionar o codigo
	turma->codigo = malloc(MAX_CODIGO * sizeof(char));

	// Aloco espaço para os alunos
	turma->nr_alunos = nr_alunos;
	turma->alunos = malloc(nr_alunos*sizeof(aluno_t));

	// Para cada aluno reservo espaço para seu nome
	int i;
	for(i = 0; i < nr_alunos; i++) {
		turma->alunos[i].nome = malloc(MAX_NOME * sizeof(char));
	}
	
	return turma;
}

void cadastra_alunos(turma_t *turma) {
	printf("-------------------------------------------\n");
	printf("Cadastro de Alunos\n");
	printf("-------------------------------------------\n");
	
	// Leitura das informaçoes dos alunos
	int i;
	for(i = 0; i < turma->nr_alunos; i++) {
		printf("Aluno #%d\n", i+1);
		printf("    RA: ");
		scanf(" %ld", &(turma->alunos[i]).ra);
		printf("  Nome: ");
		scanf(" %s", (turma->alunos[i]).nome);
		printf(" Media: ");
		scanf(" %f", &((turma->alunos[i]).media));
	}
	return;
}

void lista_turma(turma_t *turma) {
	printf("-------------------------------------------\n");
	printf("Listagem da turma ABC\n");
	printf("-------------------------------------------\n");
	
	// Listagem de alunos (nao esta formatado bonitinho)
	int i;
	for(i = 0; i < turma->nr_alunos; i++) {
		printf("%d  %ld  %s  %f\n", i, turma->alunos[i].ra, turma->alunos[i].nome, turma->alunos[i].media);
	}
}

void exclui_turma(turma_t *turma) {
	// Eh necessario dar um free de tras pra frente quando comparado com a alocaçao

	// Primeiro nos nomes dos alunos
	int i;
	for(i = 0; i < turma->nr_alunos; i++) 
		free(turma->alunos[i].nome);
	
	// Depois nos alunos e codigo da turma
	free(turma->alunos);
	free(turma->codigo);

	// Por ultimo na turma
	free(turma);
}

int main() {
	
	int n;
	printf("Nr de alunos: "); 
	scanf(" %d", &n);

	turma_t *turma = cria_turma(n);

	printf("Cod. da turma: ");
	scanf(" %s", turma->codigo);
	
	cadastra_alunos(turma);

	char c;
	printf("\nListar alunos[y/n]? ");
	scanf(" %c", &c);

	if(c == 'y') lista_turma(turma);
	exclui_turma(turma);

	return 0;
}

