#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<ll> v, p1, p2;

void comb(ll at, ll fim, ll sum, bool mode) {
	if(at >= fim) return;
	
	comb(at+1, fim, sum, mode);
	comb(at+1, fim, sum+v[at], mode);
	if(!mode) p1.pb(sum+v[at]);
	else p2.pb(sum+v[at]);
	return;
}

int main() {
    ios_base::sync_with_stdio(false);
	
	ll n, a, b;
	cin >>n >>a >>b;
    for(ll i = 0; i < n; i++) { 
		ll t; cin >>t;
		v.pb(t);
	}

	p1.pb(0);
	p2.pb(0);
	comb(0, n/2, 0, false);
	comb(n/2, n, 0, true);
	
	sort(p2.begin(), p2.end());
	ll ans = 0;
	for(int i = 0; i < p1.size(); i++) {
		ll val = upper_bound(p2.begin(), p2.end(), b - p1[i]) - lower_bound(p2.begin(), p2.end(), a - p1[i]);
		ans += val;
	}
	cout <<ans <<endl;
	
    return 0;
}

