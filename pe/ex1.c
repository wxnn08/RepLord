//Alocar string s dinamicamente na funçao main, com tamanho maximo de 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

void strflip (char *p) {
	
	int tam = strlen(p);
	
	for (int i = 0; i <= tam/2; i++) {
		char aux = p[i];
		p[i] = p[tam-1-i];
		p[tam-1-i] = aux;
	}
	
	printf("Frase invertida:\n");
	for (int i = 0; i < tam; i++) {
		printf("%c", p[i]);
	}
	
	printf("\n");
	
}


int main (){
	
	char *s = malloc(MAX*sizeof(char));

	printf("Entre uma palavra ou frase:\n");
	fgets(s, MAX, stdin); //le string
	
	strflip(s);
	
	free(s);
	
	return 0;
	
}

