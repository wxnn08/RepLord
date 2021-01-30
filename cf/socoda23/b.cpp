#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const ll MOD = 1e9 + 9;

ll fast_exp(ll a, ll b) {
	a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll sumTwoPowersUntil(ll x) {
	if(x == 0) return 0LL;
	return (fast_exp(2, x+1)+MOD-2LL)%MOD;
}
 
int main() {
    ios_base::sync_with_stdio(false);

	ll n, m, k; cin >>n >>m >>k;
	ll full = n/k;
	ll r = n%k;
	ll tot = full*(k-1LL) + r;
	ll comp = max(0LL, m-tot);
	ll pot = 0;
	pot = sumTwoPowersUntil(comp);
	cout <<((pot*k%MOD)+(m+MOD-(k*comp%MOD))+MOD)%MOD <<endl;

    return 0;
}

