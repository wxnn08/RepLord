#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const double INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int solve(vector<double> &v){
	
	if(v.size() == 1) return 0;
	
	vector<double> l (v.begin(), v.begin() + v.size()/2);
	vector<double> r (v.begin() + v.size()/2, v.end());
	
	int contDardos = 0;
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
	
	vector<double> v; 
	fori(i, 0, n){
		int x, y;
		cin >> x >>y;
		double raio = (double)sqrt(pow(x,2)+pow(y,2));
		v.pb(raio);
	}
	
	cout <<solve(v) <<endl;

    return 0;
}

