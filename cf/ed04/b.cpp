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
 
int main() {
    ios_base::sync_with_stdio(false);
	
	int n;
	cin >>n;
	vector<ii> v;
	for(ll i = 0; i < n; i++) { 
		ll a; cin >>a;
		v.pb(mk(a, i));
	}
	sort(v.begin(), v.end());
	
	ll ans = 0;
	for(int i = 1; i < n; i++) {
		ans += abs(v[i].se-v[i-1].se);
	}

	cout <<ans <<endl;

    return 0;
}

