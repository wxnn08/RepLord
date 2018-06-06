#include <bits/stdc++.h>
using namespace std;

int indiceMelhorColonia(int n){
	
	long double maiorPop, pop, d, c;
	int idMaiorPop;	
	
	/*
	se d1^c1 > d2^c2 => log(d1^c1)>log(d2^c2)
	=> c1*log(d1)>c2*log(d2)	 
	*/
	
	cin >>d >>c;
	maiorPop = c*log(d);
	idMaiorPop = 0;

	for (int i=1; i<n; i++){
		cin >>d >>c;		
		pop = c*log(d);
		if(pop>maiorPop){
			idMaiorPop = i;
			maiorPop = pop;
		}
	}

	return idMaiorPop;
}

int main(){

	int n;
	cin >> n;
	
	int imc = indiceMelhorColonia(n);
	cout << imc;

	return 0;
}
