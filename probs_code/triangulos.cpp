#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const ll INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const ll MAXS = 1e5+5;

ll soma[MAXS];
ll val[MAXS];
ll n;

bool buscaBin(ll i, ll ini, ll fim){
    ll mid = (ini+fim)/2;

    if(ini > fim) return false;

    if(i == soma[mid]) 
	return true;
	
    if(i<soma[mid]) 
	return buscaBin(i, ini, mid-1);
	
    else 
    	return buscaBin(i, mid+1, fim);
}

bool buscaTriangulo(ll i, ll maxx) {
	return buscaBin(soma[i] + 1*maxx, 0, n) && buscaBin(soma[i] + 2*maxx, 0, n);
}

int main() {	
	ll cont = 0;
	
    while (scanf("%lld", &n) != EOF) {
    	cont = 0;
	    for(ll i=1; i <= n; i++){
		cin >> val[i];
		soma[i] = soma[i-1] + val[i];
	    }
	    
	    ll maxx = soma[n]/3;

	    if (soma[n]%3 != 0) {
		cout <<0 <<endl;
	    }
	    else {
		for(ll i = 0; soma[i] < maxx; i++) {
		    if (buscaTriangulo(i, maxx)) cont++;
		}

		cout << cont << endl;
	    }
    }
    return 0;
}
