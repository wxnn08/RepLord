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

const int N = 3e5 + 5;
ll va[N];
ll p[N];
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;
	
	for(int i = 0; i < n; i++) cin >>va[i];
	for(int i = 0; i < m; i++) cin >>p[i];

	for(int i = 1; i < n; i++) {
		v.pb(va[i]-va[i-1]);
	}

	ll ans = v[0];
	for(ll at:v) {
		ans = __gcd(ans, at);
	}
	
	for(int i = 0; i < m; i++) {
		if(ans%p[i] == 0) {
			cout <<"YES" <<endl;
			cout <<va[0] <<' ' <<i+1 <<endl;
			return 0;
		}
	}

	cout <<"NO" <<endl;

	return 0;
}
