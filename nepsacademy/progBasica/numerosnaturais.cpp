#include <bits/stdc++.h>
using namespace std;

int soma_naturais(int n){
	if(n==0)return 0;
	else return n+soma_naturais(n-1);
}

int main (){

	int n;
	cin >>n;

	cout <<soma_naturais(n);

	return 0;
}
