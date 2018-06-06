#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector <int> numeros;

int aux;
void swap(int idA, int idB){
    aux = numeros[idA];
    numeros[idA]=numeros[idB];
    numeros[idB]=aux;
}

void imprime(){
    for(int i=numeros.size()-1; i>=0; i--)
	cout <<numeros[i];
    cout <<endl;
}

void backTrack (int posFinal){
    imprime();
    int contSwap=0;
    for(int i=0; i<posFinal-1; i++){
	if(numeros[i]==1 && numeros[i+1]==0){
	    swap(i, i+1);
	    contSwap++;
	    backTrack(i+1);
	}
    }

    swap(posFinal-1-contSwap, posFinal-1);
}

int main(){
    int n;
    string get;
    cin >>n;

    while(n--){
	int maxDig, qtdUm;
	getline(cin, get);
	cin >>maxDig >>qtdUm;
	
	numeros.clear();
	fori(i, 0, maxDig){
	    if(i<qtdUm) numeros.pb(1);
	    else numeros.pb(0);
	}
	backTrack(maxDig);
	if(n!=0)cout <<endl;
    }
    return 0;
}

