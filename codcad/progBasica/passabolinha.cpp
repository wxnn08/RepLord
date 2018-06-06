#include <bits/stdc++.h>
using namespace std;

int m[110][110], contBandeira=0;

void leEntrada(int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> m[i][j];
		}
	}
}

void passaBolinha(int i, int j, int n){
	if(m[i][j]<0) return;
	contBandeira++;
	m[i][j]*=-1;
	if(j<(n-1) && abs(m[i][j])<=abs(m[i][j+1])) passaBolinha(i, j+1, n);
	if(i<(n-1) && abs(m[i][j])<=abs(m[i+1][j])) passaBolinha(i+1, j, n);
	if(j>0 &&  abs(m[i][j])<=abs(m[i][j-1])) passaBolinha(i, j-1, n);
	if(i>0 &&  abs(m[i][j])<=abs(m[i-1][j])) passaBolinha(i-1, j, n);

	return;
}

void printMatriz(int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout <<m[i][j] <<" ";
		}
		cout <<endl;
	}
}

int main(){
	
	int n, i0, j0;

	cin >>n >>i0 >>j0;

	leEntrada(n);
	
	passaBolinha(i0-1, j0-1, n);
	cout<< contBandeira <<endl;
	
	return 0;
}
