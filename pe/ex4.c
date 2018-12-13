//soma da linha r com coluna c. 

#include <stdio.h>
#include <stdlib.h>

int sum_rowcol(int **A, int m, int n, int r, int c) {
	int sum_col = 0;
	int sum_lin = 0;
	int sum;
	int i, j;
	
	//Le cada elemento da linha
	for(j = 0; j < n; j++){
		sum_col = A[r][j] + sum_col;
	}
	//Le cada elemento da coluna
	for(i = 0; i < m; i++){
		sum_lin = A[i][c] + sum_lin;
	}
	
	sum = sum_col + sum_lin - A[r][c];
	
	return sum;
} 



int main (){

	int **A;
	int m, n, r, c, sum;
	
	printf("Informe as dimensoes da matriz: m x n = ");
	scanf("%d %d", &m, &n);
	
	A = (int **) malloc(m * sizeof(int*));
	
	for(int i = 0; i < m; i++){
		A[i] = (int*) malloc(n * sizeof(int));		
	}
	
	printf("Escolha uma linha (de 1 a m):	r = ");
	scanf("%d", &r);
	printf("Escolha uma coluna (de 1 a n):	c = ");
	scanf("%d", &c);
	printf("Informe os elementos da matriz: ");

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("A[%d][%d] = ", i+1, j+1);
			scanf("%d", &A[i][j]);
		}
	}

	sum = sum_rowcol(A, m, n, r-1, c-1);
	
	printf("Soma da linha %d com a coluna %d = %d\n", r, c, sum);
	
	for(int i = 0; i < m; i++){
		free(A[i]);		
	}

	free(A);
	
return 0;
}
