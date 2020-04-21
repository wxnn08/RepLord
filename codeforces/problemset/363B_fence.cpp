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
 
int main(){
    ios_base::sync_with_stdio(false);

    int n, k;
	cin >>n >>k;
	vector<int> v;
	fori(i, 0, n){
		int u; cin >>u;
		v.pb(u);
	}

	ll soma = 0;
	for(int i=0; i<k; i++) soma+=v[i];

	ll menor = soma;
	int id = 0;
	for(int i=k; i<n; i++){
		soma = soma+(v[i]-v[i-k]);
		if(menor>soma){
			id = i-k+1;
			menor = soma;
		}
	}
	cout <<id+1 <<endl;
    
    return 0;
}

