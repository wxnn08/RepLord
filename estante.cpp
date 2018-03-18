#include <bits/stdc++.h>
using namespace std;
string mat[305][305];

//variável global:
int cont;

void organizaEstante(int n, int m, int l, int c, int k){

	if(mat[l][c] != ".") return;
	if(cont==0) return;

	cont--;
	mat[l][c]=to_string(k-cont);

	if(l-1>=0) organizaEstante(n, m, l-1, c, k);
	if(c+1<=m) organizaEstante(n, m, l, c+1, k);
	if(l+1<=n) organizaEstante(n, m, l+1, c, k); 
	if(c-1>=0) organizaEstante(n, m, l, c-1, k);
	
	return;
}

int leMatriz(int n, int m, int k){

	int contaPontos = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >>mat[i][j];
			if(mat[i][j]==".") contaPontos++;
		}
	}
	
	if(k>contaPontos) k=contaPontos;
	return k;	
}

void printMatriz(int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout <<mat[i][j] << " ";
		}
		cout <<endl;
	}
}

int main(){
	int n, m, l, c, k;
	cin >>n >>m >>l >>c >>k;

	k = leMatriz(n, m, k);
	cont = k;
	organizaEstante(n, m, l, c, k);
	
	printMatriz(n,m);

	return 0;
}
