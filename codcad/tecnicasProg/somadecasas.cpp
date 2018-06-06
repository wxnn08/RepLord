#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int casas[100005];
bool buscaBinaria(int x, int n){
    int ini=0, fim = n, meio, menorResp;
    
    while(ini<=fim){
	meio = (ini+fim)/2;

	if(x<=casas[meio]) {
	    fim = meio-1;
	    menorResp = meio;
	}

	if(x>casas[meio]) ini=meio+1;
    }
    return menorResp==x;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n;
    
    for(int i=1; i<=n; i++){
	cin >>casas[i];
    }

    int k;
    cin >>k;
    
    bool achou=0; //verifica se o num foi encontrado
    int num, numProc; 
    for(int i=1; i<=n && !achou; i++){
	num=casas[i];
	numProc = k-num;
	achou = buscaBinaria(numProc, k);
    }
    cout <<num <<" " <<numProc;
    return 0;
}

