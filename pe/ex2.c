//sortear n numeros impares entre 1 e 999. armazenar em vetor de inteiros alocado dinamicamente. receber vetor e devolver a soma

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum_vector(int *v, int n) {
	int sum = 0;

	for(int i = 0; i < n; i++){
		sum = *(v+i) + sum; 
	
	}
	
	return sum;
}

int main (){
	int n, par;
	
	printf("Tamanho do vetor: n = ");
	scanf("%d", &n);
	
	int *v = malloc(n*sizeof(int));

	srand(time(NULL));
		
	for(int i = 0; i < n; i++) {
		int rand_number = 1 + rand() % 998;
			if (rand_number % 2 == 0) {
				par = 1;
				i--;	
			} else {
				v[i]= rand_number;
				par = 0;
			}				
	}
	
	printf("Vetor sorteado:\n");
	
	for(int i = 0; i < n; i++){
		printf("%d ", *(v+i));
	}

	int sum = sum_vector(v, n);

	printf("\nSoma dos elementos = %d\n", sum);	
		
	free(v);
	
	return 0;
	
}
