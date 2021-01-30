#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >>n;

	vector<ii> v;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		v.eb(a, 0LL);
	}
	for(int i = 0; i < n; i++) {
		ll b; cin >>b;
		v[i].se = b;
	}

	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ll cont = 0;
		cc(i);
		for(int j = 0; j < n; j++) {
			if((v[i].fi | v[j].fi) == v[i].fi) {
				cc(j);
				cont += v[j].se;
			}
		}
		if(cont != v[i].se)
			ans = max(ans, cont);
	}
	cout <<ans <<endl;
	
	return 0;
}

