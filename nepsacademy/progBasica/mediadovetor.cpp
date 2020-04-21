#include<bits/stdc++.h>
using namespace std;

double media_vetor(int n, int v[]){
	long double soma = 0;
	for (int i=0; i<n; i++){
		soma += v[i];
	}
	double media = soma/n;

	return media;
}

int main (){

	int n, v[100100];
	cin >>n;

	for (int i=0; i<n; i++){
		cin >>v[i];
	}

	cout <<setprecision(2) <<fixed;

	cout <<media_vetor(n, v) <<endl;

	return 0;
}
