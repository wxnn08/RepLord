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
 
int n, m;
vector<int> faixa, pontuacao;

int busca(int x, int ini, int fim){
	int meio = (ini+fim)/2;
	if(ini>=fim) return meio;
	if(faixa[meio]<x) return busca(x, meio+1, fim);
	if(faixa[meio]>x) return busca(x, ini, meio-1);

	return meio;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >>n >>m;
	faixa.pb(0);
	fori(i, 0, n-1){
		int p; cin >>p;
		faixa.pb(p);
	}

	fori(i, 0, n){
		int f; cin >>f;
		pontuacao.pb(f);
	}
	
	fori(i, 0, m){
		int x; cin >>x;
		cout <<pontuacao[busca(x, 0, (int)faixa.size()-1)] <<' ';
	}
	cout <<endl;
    return 0;
}

