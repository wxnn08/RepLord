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
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int H = 1e4 + 5;
const int N = 1e3 + 5;
ll dp[N][H];
vector<ii> sp;

ll solve(int pos, ll h) {
	if(h <= 0) return 0;
	if(pos >= sp.size()) return INF;

	ll &r = dp[pos][h];
	if(r != -1) return r;

	return r = min(solve(pos+1, h), solve(pos, h-sp[pos].fi) + sp[pos].se);
}

int main() {
    ios_base::sync_with_stdio(false);

	ll h, n;
	cin >>h >>n;
	for(int i = 0; i < n; i++) {
		int a, b; cin >>a >>b;
		sp.eb(a, b);
	}

	memset(dp, -1LL, sizeof dp);
	cout <<solve(0, h) <<endl;

    return 0;
}

