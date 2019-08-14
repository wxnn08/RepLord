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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

vector<ii> calcPrimes(ll x) {
	vector<ii> primes_b;
	ll i = 2;
	while(i*i <= x) {
		if(x%i == 0) primes_b.pb(ii(i, 0));
		int last = primes_b.size()-1;
		while(x%i == 0) {
			x /= i;
			primes_b[last].se++;
		}
		i++;
	}
	if(x > 1) primes_b.pb(ii(x, 1));
	return primes_b;
}

ll legendre(ll n, ll p) {
	ll ans = 0;
	while(n) {
		n /= p;
		ans += n;
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
	
	ll n, b;
	cin >>n >>b;

	vector<ii> primes_b;
	primes_b = calcPrimes(b);

	ll ans = INF;
	for(ii at:primes_b) {
		ans = min(ans, legendre(n, at.fi)/at.se);
	}

	cout <<ans <<endl;

    return 0;
}

