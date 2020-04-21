#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<ll> p;
int n;
ll x, a, y, b, k;

bool check(int pos) {
	vector<ii> v;
	ll qtdA = (pos)/a;
	ll qtdB = (pos)/b;
	ll c = (a*b)/__gcd(a,b);
	ll qtdC = (pos)/c;
	qtdA -= qtdC;
	qtdB -= qtdC;
	v.eb(x, qtdA);
	v.eb(y, qtdB);
	v.eb((x+y), qtdC);
	sort(v.begin(), v.end(), greater<pair<ll,ll>>());
	
	int at = 0;
	ll ans = 0;
	for(int i = 0; i < pos; i++) {
		while(at < (int)v.size() and v[at].se == 0) at++;
		if(at >= (int)v.size()) break;
		ans += (v[at].fi*(p[i]/100));
		v[at].se--;
	}
	return ans >= k;
}

int solve() {
	int ini = 1, fim = n;
	int ans = -1;
	while(ini <= fim) {
		int mid = (ini+fim)>>1;
		if(check(mid)) ans = mid, fim = mid-1;
		else ini = mid+1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;
	while(tc--) {
		p.clear();
		cin >>n;
		for(int i = 0; i < n; i++) {
			ll price; cin >>price;
			p.pb(price);
		}
		sort(p.begin(), p.end(), greater<ll>());

		cin >>x >>a >>y >>b >>k;
		cout <<solve() <<endl;
	}
	
	return 0;
}

