#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<ll> a, b;
ll f(ll n) {
	ll ans = 0;
	for(ll at:a) 
		ans += (at < n? abs(at-n):0);
	for(ll at:b) 
		ans += (at > n? abs(at-n): 0);
	return ans;
}

ll search(ll l, ll r) {
	while(r-l > 1) {
		ll mid = (r+l)>>1;
		if(f(mid) < f(mid+1)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	return f(l+1);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m; 
	cin >> n >>m;
	for(int i = 0; i < n; i++) {
		ll t; cin >>t;
		a.pb(t);
	}
	for(int i = 0; i < m; i++) {
		ll t; cin >>t;
		b.pb(t);
	}
    
	cout <<search(-1, 1e9) <<endl;

    return 0;
}

