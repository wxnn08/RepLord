#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int contaMoedas(int n){
    int moedas[6] = {100,50,25,10,5,1};
    int cont=0;
    for(int i=0; i<6; i++){
	if(n>=moedas[i]){	
	    cont += n/moedas[i];
	    n = n%moedas[i];
	}
    }
    return cont;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n;

    int cont = contaMoedas(n);
    cout <<cont <<endl;
    
    return 0;
}

