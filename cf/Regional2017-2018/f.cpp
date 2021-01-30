#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define endl '\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef tuple<ll,ll,ll> tl;
typedef vector<tl> vtl;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

set<ii> old;
vtl bag;
int n;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 0; i < n; i++) {
		ll a,b,c; cin >> a >> b >> c;
		bag.emplace_back(a,b,c);
	}

	sort(bag.begin(), bag.end());
	int i = 0;
	ll ans = 0;

	while(i < n) {
		int j = i;
		ll ok = 0;
		set<ii> novo;	
		while(j < n and get<0>(bag[i]) == get<0>(bag[j])) {
			auto low = old.lower_bound(ii(get<1>(bag[j]),0));

			ll b;
			if(low == old.begin()) b = 0;	
			else low--, b = low->se;

			auto ok = novo.lower_bound(ii(get<1>(bag[j]),0));

			if(ok->fi == get<1>(bag[j])) {
				ll x = max(ok->se, b + get<2>(bag[j]));
				novo.erase(ok);
				novo.emplace(ok->fi,x);
			}
			else novo.emplace(get<1>(bag[j]), b + get<2>(bag[j]));
			j++;
		}

		for(ii x : novo) {
			auto ok = old.lower_bound(x);
			if(ok->fi == x.fi) {
				ll y = max(ok->se,x.se);
				old.erase(ok);
				old.emplace(ok->fi,y);
			}
			else old.insert(x);
		}
		i = j;
	}

	for(auto x : old) ans = max(x.se,ans);
	cout << ans << endl;

	
	return 0;
}

