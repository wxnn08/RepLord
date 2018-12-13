//soma da linha r com coluna c. 

#include <stdio.h>
#include <stdlib.h>

void swap_row(int** A, int n, int r1, int r2) {
	int i, j;
	
	for(j = 0; j < n; j++){
		int aux = A[r1][j];
		A[r1][j] = A[r2][j];
		A[r2][j] = aux;
	}
		
} 



int main (){

	int **A;
	int m, n, r1, r2;
	
	printf("Informe as dimensoes da matriz: m x n = ");
	scanf("%d %d", &m, &n);
	
	A = (int **) malloc(m * sizeof(int*));
	
	for(int i = 0; i < m; i++){
		A[i] = (int*) malloc(n * sizeof(int));		
	}
	
	printf("Escolha uma linha (de 1 a m):	r1 = ");
	scanf("%d", &r1);
	printf("Escolha uma linha (de 1 a m):	r2 = ");
	scanf("%d", &r2);
	printf("Informe os elementos da matriz:\n");

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("A[%d][%d] = ", i+1, j+1);
			scanf("%d", &A[i][j]);
		}
	}

	swap_row(A, n, r1, r2);
	
	printf("Soma da linha %d com a coluna %d = %d\n", r, c, sum);
	
	for(int i = 0; i < m; i++){
		free(A[i]);		
	}

	free(A);
	
return 0;
}
