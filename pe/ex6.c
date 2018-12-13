//soma da linha r com coluna c. 

#include <stdio.h>
#include <stdlib.h>

int magic_square(int** A, int n) {
	int i, j;
	int soma_linha = 0;
	int soma_coluna;
	int soma_diagonal1 = 0;
	int soma_diagonal2 = 0;
	int aux = 0;
	//Soma linha

	for(j = 0; j < n; j++){			
		aux = A[0][j] + aux;
	} 

	for(i = 0; i < n; i++){
		soma_linha = 0;
		for(j = 0; j < n; j++){
			soma_linha = A[i][j] + soma_linha;
		}		
		if(soma_linha != aux) {
			printf("OK1"); 
			return 0;
		}
	}

	for(j = 0; j < n; j++){
		soma_coluna = 0;
		for(i = 0; i < n; i++){
			soma_coluna = A[i][j] + soma_coluna;
		} 
		if(soma_coluna != aux) {
			printf("OK2");
			return 0;
		}
	}

	for(i = 0; i < n; i++){
		soma_diagonal1 = A[i][i] + soma_diagonal1;
		soma_diagonal2 = A[i][n-1-i] + soma_diagonal2;
	}
	if(soma_diagonal1 != aux || soma_diagonal2 != aux){
		printf("OK3");		
		return 0;
	}

	return 1;

} 



int main (){

	int **A;
	int n, x;
	
	printf("Informe a dimensao da matriz: n = ");
	scanf("%d", &n);
	
	A = (int **) malloc(n * sizeof(int*));
	
	for(int i = 0; i < n; i++){
		A[i] = (int*) malloc(n * sizeof(int));		
	}
	
	printf("Informe os elementos da matriz:\n");

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("A[%d][%d] = ", i+1, j+1);
			scanf("%d", &A[i][j]);
		}
	}

	x = magic_square(A, n);
	
	printf("%d\n", x);
	
	for(int i = 0; i < n; i++){
		free(A[i]);		
	}

	free(A);
	
return 0;
}
