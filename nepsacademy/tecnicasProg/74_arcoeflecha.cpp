#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const ll INF = 9999999999999;
const double PI = acos(-1.0);

ll solve(vector<ll> &v){
	
	if(v.size() == 1) return 0;
	
	vector<ll> l (v.begin(), v.begin() + v.size()/2);
	vector<ll> r (v.begin() + v.size()/2, v.end());
	
	ll contDardos = 0;
	contDardos += solve(l);
	contDardos += solve(r);
	
	l.pb(-INF);
	r.pb(-INF);

	int lCont = 0, rCont = 0;
	for(int i=0; i < v.size(); i++){
		if(l[lCont] > r[rCont]) {
			v[i] = l[lCont];
			lCont++;
		}
		else {
			v[i] = r[rCont];
			rCont++;
			contDardos += l.size()-lCont-1;
		}
	}
	
	return contDardos;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	
	vector<ll> v; 

	fori(i, 0, n){
		int x, y;
		cin >> x >>y;
		ll raio = pow(x,2)+pow(y,2);
		v.pb(raio);
	}
	
	cout <<solve(v) <<endl;

    return 0;
}

