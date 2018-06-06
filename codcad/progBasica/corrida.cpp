#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int main (){
	
	int n, m;
	cin >>n >>m;
	int colocacao[3][2];

	colocacao[0][0] = colocacao[1][0] = colocacao[2][0] = INF;
	
	int soma[110], aux;
	for (int i=0; i<n; i++){
		soma[i]=0;
		for (int j=0; j<m; j++){
			cin >> aux;
			soma[i]+=aux;
		}

		if(soma[i]<colocacao[0][0]){
			colocacao[2][0] = colocacao[1][0];
			colocacao[2][1] = colocacao[1][1];
			colocacao[1][0] = colocacao[0][0];
			colocacao[1][1] = colocacao[0][1];
			colocacao[0][0] = soma[i];
			colocacao[0][1] = i;
		}
		
		else if(soma[i]colocacao[1][0]){
			colocacao[2][0] = colocacao[1][0];
			colocacao[2][1] = colocacao[1][1];
			colocacao[1][0] = soma[i];
			colocacao[1][1] = i;
		}
		
		else if(soma[i]<colocacao[2][0]){
			colocacao[2][0] = soma[i];
			colocacao[2][1] = i;
		}
	}
	
	cout <<colocacao[0][1]+1 << endl <<colocacao[1][1]+1 << endl <<colocacao[2][1]+1 <<endl;

	return 0;
}
