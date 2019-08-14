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
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ll pot(ll base, ll exp) {
	ll ans = 1;
	while(exp) {
		ans *= base;
		exp--;
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

	ll x, y, l, r;
	cin >>x >>y >>l >>r;
	
	ll potx = log(r)/log(x);
	ll poty = log(r)/log(y);
	
	vector<ll> v1, v2;
	for(ll i = 0; i <= potx; i++) 
		v1.pb(pot(x, i));
	for(ll i = 0; i <= poty; i++) 
		v2.pb(pot(y, i));
	
	set<ll> yrs;
	for(ll at:v1) {
		for(ll bt:v2) {
			if(at+bt <= r and at+bt >= l) yrs.insert(at+bt);
		}
	}

	if(yrs.size() == 0) {
		cout <<r-l+1 <<endl;
		return 0;
	}

	ll pri = -1, last = -1;
	ll ans = 0;
	for(auto yr:yrs) {
		if(last == -1) pri = yr;
		else ans = max(ans, yr-last-1);
		last = yr;
	}
	ans = max(ans, pri-l-1 + (int) !yrs.count(l));
	ans = max(ans, r-last-1 + (int) !yrs.count(r));
	cout <<ans <<endl;

    return 0;
}

