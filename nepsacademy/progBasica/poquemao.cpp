#include <bits/stdc++.h>
using namespace std;

int conta_poquemaos(int doces[4]){
	
	sort(doces+1, doces+4);

	int soma = 0, cont = 0;
	for(int i=1; i<4; i++){
		if(soma+doces[i] <= doces[0]){
			soma += doces[i];
			cont++;
		}

	}
	return cont;
}

int main(){

	int doces[4];
	for(int i=0; i<4; i++){
		cin >> doces[i];
	}
	
	int num = conta_poquemaos(doces);
	cout << num <<endl;

	return 0;
}	
