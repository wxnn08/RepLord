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

	ll vant1 = 0, vant2 = 0, ans = 0;
	vector<ii> v;

	int n;
	cin >>n;

	vector<ii> dans;
	for(int i = 0; i < n; i++) {
		ll a, t; cin >>a >>t;
		v.pb(ii(a, t));
		dans.pb(ii(a, t));
	}
	
	sort(v.begin(), v.end(), [](const ii &a, const ii &b) {
		if(a.fi * a.se * b.se != b.fi * b.se * a.se) 
			return a.fi*a.se*b.se > b.fi*b.se*a.se;
		else return a.fi > b.fi;
	});

	for(int i = 0; i < n-1; i++) {
		vant1 += (v[i].fi*v[i].se);
		vant2 += (dans[i].fi*dans[i].se);

		ans += (vant1*v[i+1].se - vant2*dans[i+1].se);
	}

	cout <<ans <<".0" <<endl;

	return 0;
}

