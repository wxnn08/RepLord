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

const int N = 3;
const ll MOD = 1e9 + 7;

struct mat {
	ll m[N][N];

	mat() { 
		memset(m, 0, sizeof m); 
	}

	void create() {
		m[0][0] = 1LL;
		m[0][1] = 1LL;
		m[0][2] = 1LL;

		m[1][0] = 0LL;
		m[1][1] = 1LL;
		m[1][2] = 1LL;

		m[2][0] = 0LL;
		m[2][1] = 1LL;
		m[2][2] = 0LL;
	}

	void id() {
		for(int i = 0; i < N; i++)
			m[i][i] = 1LL;
	}

	mat operator * (const mat &t) const {
		mat r;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				for(int k = 0; k < N; k++) {
					r.m[i][j] += (m[i][k]*t.m[k][j]);
					r.m[i][j] %= MOD;
				}
			}
		}
		return r;
	}
};

ll fast_exp(ll e) {
	e--;
	if(e < 0) return 0;
	
	mat r, base;
	r.id();
	base.create();
	while(e > 0) {
		if(e&1LL) 
			r = r*base;
		base = base*base;
		e >>= 1LL;
	}
	return r.m[0][0] + r.m[0][1];
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;

	while(tc--) {
		ll a, b; cin >>a >>b;
		cout <<((fast_exp(b)+MOD)-fast_exp(a-1))%MOD <<endl;
	}

	return 0;
}

