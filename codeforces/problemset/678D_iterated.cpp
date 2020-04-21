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

const ll MOD = 1e9+7;

ll fast_exp(ll base, ll e) {
	ll ans = 1;
	while(e > 0) {
		if(e&1) {
			ans *= base;
			ans %= MOD;
		}
		e >>= 1;
		base *= base;
		base %= MOD;
	}
	return ans%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);

	ll a, b, n, x;
	cin >>a >>b >>n >>x;
	
	ll an = fast_exp(a, n);
	ll ans = (an*x)%MOD;
	if(a == 1LL) {
		ans += ((b * (n%MOD))%MOD);
	} else {
		ans += ((b * ((((an-1LL+MOD)%MOD) * fast_exp(a-1LL, MOD-2LL))%MOD))%MOD);
	}
	
	cout <<ans%MOD <<endl;
    return 0;
}

