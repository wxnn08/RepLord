#include <bits/stdc++h>
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

class ZHash {
	int n;
	ll *id;
public:
	ZHash(int n) : n(n) {
		id = new ll[n];
		init_zobrist();
	}

	void init_zobrist() {
		mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
		for(int i = 0; i < n; i++) 
			id[i] = rng();
	}

	ll hash(int i) {
		return id[i];
	}
};

ll nC2(ll n) {
	if(n == 1LL) return 0LL;
	return (n*(n-1))/2LL;
}
 
int main() {
    ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;

	vector<int> g[n + 5];
	for(int i = 0; i < m; i++) {
		int u, v; cin >>u >>v;
		g[u].pb(v);
		g[v].pb(u);
	}

	ll ans = 0;
	ll zf = 0;
	ZHash h1(n + 5);

	map<ll, ll> qt;
	for(int i = 1; i <= n; i++) {
		ll h = h1.hash(i);
		for(auto curr:g[i]) 
			h = (h ^ h1.hash(curr));
		if(g[i].size() == 0) zf++;
		else qt[h]++;
	}
	for(auto curr:qt) 
		ans += nC2(curr.se);

	qt.clear();
	for(int i = 1; i <= n; i++) {
		ll h = 0LL;
		for(auto curr:g[i]) 
			h = (h ^ h1.hash(curr));
		if(g[i].size() != 0)
			qt[h]++;
	}
	for(auto curr:qt) 
		ans += nC2(curr.se);

	ans += nC2(zf);

	cout <<ans <<endl;
    return 0;
}

