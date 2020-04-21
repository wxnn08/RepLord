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
 
void mergesort(vector<int> &v){
	if(v.size() == 1) return;
	
	vector<int> r (&v[0], &v[v.size()/2]);
	vector<int> l (&v[v.size()/2], &v[v.size()]);

	mergesort(r);
	mergesort(l);

	r.pb(-INF);
	l.pb(-INF);

	int rCont=0, lCont=0;
	for(int i=0; i<v.size(); i++){
		if(r[rCont]>l[lCont]){
			v[i] = r[rCont];
			rCont++;
		}
		else {
			v[i] = l[lCont];
			lCont++;
		}
	}

	return;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	
	vector<int> v;
	fori(i, 0, n){
		int u;
		cin >>u;
		v.pb(u);
	}

	mergesort(v);
    
	for(int i: v) cout <<i <<' ';
	cout <<endl;

    return 0;
}

