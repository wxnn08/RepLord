#include<bits/stdc++.h>
using namespace std;

int soma_matriz(int mat[55][55], int i, int j, int l, int c){
	
	int soma=0;

	for(int a=i;a<i+l;a++){
		for(int b=j;b<j+c;b++){
			soma += mat[a][b];
		}
	}
	
	return soma;
}

int main(){

	int mat[55][55]={0};
	int n, m, l, c;

	cin >>n >>m >>l >>c;

	//le matriz
	for(int i=0;i<n;i++){
		for(int j=0; j<m; j++){
			cin >>mat[i][j];
		}
	}

	int sMax=0, soma=0;
	n = n-l;
	m = m-c;

	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			soma = soma_matriz(mat, i, j, l, c);
			if(soma>sMax){
				sMax=soma;
			}			
		}
	}
	cout <<sMax <<endl;
	return 0;
}
