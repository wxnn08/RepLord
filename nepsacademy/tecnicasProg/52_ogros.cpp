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
vector <pair <int, int> > faixa;

int busca(int x, int ini, int fim){
	int meio = (ini+fim)/2;
	if(faixa[meio].fi == x) return faixa[meio].sec;
	if(ini>=fim){
		if(x<faixa[meio].fi) return faixa[meio-1].sec;
		else return faixa[meio].sec;
	}
	if(faixa[meio].fi < x) return busca(x, meio+1, fim);
	if(faixa[meio].fi > x) return busca(x, ini, meio-1);
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >>n >>m;
	pair <int,int> aux;
	aux = mk(0,0);
	faixa.pb(aux);

	fori(i, 1, n){
		int p; cin >>p;
		aux = mk(p,0);
		faixa.pb(aux);
	}
	
	fori(i, 0, n){
		int f; cin >>f;
		faixa[i].sec = f;
	}
	
	fori(i, 0, m){
		int x; cin >>x;
		cout <<busca(x, 0, (int)faixa.size()-1) <<' ';
	}
	cout <<endl;
    return 0;
}

