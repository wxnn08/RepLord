#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
bool comp(ii a, ii b) {
	if(a.fi != b.fi) return a.fi < b.fi;
	return a.se < b.se;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >>n;
	
	vector<ii> v;
	v.pb(mk(0, 1));
	for(ll i = 1; i < n; i++) {
		ll a; cin >>a;
		v.pb(mk(v[i-1].fi+a, i+1));
	}

	sort(v.begin(), v.end());
	
	for(int i = 1; i < v.size(); i++) {
		if(abs(v[i].fi-v[i-1].fi) > 1 or abs(v[i].fi-v[i-1].fi == 0)) {
			cout <<-1 <<endl;
			return 0;
		}
	}

	const int N = 2e5 + 5;
	int ans[N];
	int cont = 1;
	memset(ans, 0, sizeof(ans));

	for(auto at:v) {
		if(ans[at.se] == 0) {
			ans[at.se] = cont++;
		} else {
			cout <<-1 <<endl;
			return 0;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		cout <<ans[i] <<' ';
	}
	cout <<endl;
	return 0;
}
