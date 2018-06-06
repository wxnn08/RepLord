#include<bits/stdc++.h>
using namespace std;

bool checa_palindromo(int i, int j, string s){
	bool ehPalindromo = true;
	while(j>i){	
		if(s[i]!=s[j]) ehPalindromo=false;	
		i++; j--;
	}

	return ehPalindromo;
}

int main(){
	//le entradas:
	int n;
	cin >>n;

	string s;
	cin >>s;	

	//percorrendo a string
	int iMax=0, jMax=0;
	for(int i=0;i<n;i++){
		for(int j=(n-1); j>i; j--){
			if(s[i]==s[j]){	//se duas letras forem iguais
				
				//chama a função para checar se 
				if(checa_palindromo(i,j,s) && (j-i)>(jMax-iMax)){ 
					iMax=i;
					jMax=j;
				}
			}
		}
	}
	
	cout <<(jMax-iMax)+1 <<endl;

	for(int i=iMax; i<=jMax; i++){
		cout <<s[i];
	}

	return 0;
}
