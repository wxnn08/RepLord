//sortear n numeros pares entre 2 e 1000. armazenar em vetor de inteiros alocado dinamicamente. ordenar com selection sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int *v, int n){




}

int main (){
	int n, par;
	
	printf("Tamanho do vetor: n = ");
	scanf("%d", &n);
	
	int *v = malloc(n*sizeof(int));

	srand(time(NULL));
		
	for(int i = 0; i < n; i++) {
		int rand_number = 2 + rand() % 998;
			if (rand_number % 2 == 0) {
				v[i]= rand_number;
				par = 1;	
			} else {
				par = 0;
				i--;
			}				
	}
	
	printf("Vetor sorteado:\n");
	
	for(int i = 0; i < n; i++){
		printf("%d ", *(v+i));
	}

	selection_sort(v, n);

	printf("\nSoma dos elementos = %d\n", sum);	
		
	free(v);
	
	return 0;
	
}
