#include <bits/stdc++.h>
using namespace std;

bool ordena_impares(int a, int b){
	
	return a>b;
}

int main(){
	
	int par[100005], impar[100005], n;
	cin >>n;
	
	int aux;
	int cPar=0, cImpar=0;

	for(int i=0; i<n; i++){
		cin >>aux;
		if(!(aux%2)){
			par[cPar]=aux;
			cPar++;
		} else{
			impar[cImpar]=aux;
			cImpar++;
		}
	}
	
	sort(par, par+cPar);
	sort(impar, impar+cImpar, ordena_impares);

	for(int i=0; i<cPar; i++) cout <<par[i] <<(i!=cPar-1?" ":"\n");
	
	for(int i=0; i<cImpar; i++) cout <<impar[i] <<(i!=cImpar-1?" ":"\n");

	return 0;
}
