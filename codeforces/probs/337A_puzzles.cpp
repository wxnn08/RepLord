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

    int n, m;
	cin >>n >>m;

	vector <int> v;
	fori(i,0,m) {
		int u; cin >>u;
		v.pb(u);
	}
	sort(v.begin(), v.end());

	int menor = v[n-1]-v[0];
	fori(i,0,m-n+1){
		menor = min(menor, v[i+n-1]-v[i]);
	}

	cout <<menor <<endl;

    return 0;
}

