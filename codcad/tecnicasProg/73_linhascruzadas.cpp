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

int mergesort(vector<int> &v) {
	if(v.size() == 1) return 0;
	
	vector<int> l (v.begin(), v.begin() + v.size()/2);
	vector<int> r (v.begin() + v.size()/2, v.end());
	
	int contInv = 0;
	contInv += mergesort(l);
	contInv += mergesort(r);

	l.pb(INF);
	r.pb(INF);
	
	int rCont = 0, lCont = 0;

	for(int i=0; i<v.size(); i++){
		if(l[lCont] <= r[rCont]) {
			v[i] = l[lCont];
			lCont++;
		}
		else {
			v[i] = r[rCont];
			rCont++;
			
			contInv += l.size()-lCont-1;
		}
	}

	return contInv;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	vector<int> v;

	fori(i,0,n){
		int aux;
		cin >>aux;
		v.pb(aux);
	}
    
	cout <<mergesort(v) <<endl;

    return 0;
}

