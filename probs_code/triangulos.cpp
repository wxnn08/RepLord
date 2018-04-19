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

bool buscaTriangulo(ll i, ll ladoTriangulo) {
	return buscaBin(soma[i] + 1*ladoTriangulo, 0, n) && buscaBin(soma[i] + 2*ladoTriangulo, 0, n);
}

int main() {	
	ll cont = 0;
	
    while (scanf("%lld", &n) != EOF) {
    	cont = 0;
	    for(ll i=1; i <= n; i++){
		cin >> val[i];
		soma[i] = soma[i-1] + val[i];
	    }
	    
	    ll ladoTriangulo = soma[n]/3;

	    if (soma[n]%3 != 0) {
		cout <<0 <<endl;
	    }
	    else {
		for(ll i = 0; soma[i] < ladoTriangulo; i++) {
		    if (buscaTriangulo(i, ladoTriangulo)) cont++;
		}

		cout << cont << endl;
	    }
    }
    return 0;
}
