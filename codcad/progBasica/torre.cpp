#include <bits/stdc++.h>
using namespace std;

int m[1010][1010], somY[1010], somX[1010];

void leEntradas(int n){

	for (int i=0; i<n; i++){
		for(int j=0; j<n;j++){
			cin >> m[i][j];
			somX[i] = somX[i]+m[i][j];
			somY[j] = somY[j]+m[i][j];
		}
	
	} 
}

int pesoMax (int n){
	
	int pesoMax = -1, pesoLocal = 0;
	int x, y;

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){

			pesoLocal = (somX[i]+somY[j]) - 2*m[i][j]; //soma duas vezes o local
			
			if(pesoLocal>pesoMax){
				pesoMax=pesoLocal;
			}
		}
	}
	
	return pesoMax;
}

int main(){
	
	int n;
	cin >>n;

	leEntradas(n);

	cout << pesoMax(n);;

	return 0;
}
