#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 3;
const ll MOD = 1e9+7;
struct mat {
	ll m[N][N];
	
	mat() {
		memset(m, 0, sizeof(m));
	}

	void id(int v) {
		for(int i = 0; i < v; i++) {
			m[i][i] = 1LL;
		}
	}

	void t() {
		m[0][0] = 1;
		m[0][1] = 1;
		m[0][2] = 1;
		m[1][1] = 1;
		m[1][2] = 1;
		m[2][1] = 1;
	}

	mat operator * (const mat &B) const {
		mat r;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				for(int k = 0; k < N; k++) {
					r.m[i][j] += (m[i][k] * B.m[k][j])%MOD;
					r.m[i][j] %= MOD;
				}
			}
		}
		return r;
	}
};

ll solve(ll n) {
	if(n == 1) return 1;
	if(n <= 0) return 0;
	mat r, base;
	base.t();
	r.id(N);
	n--;
	while(n > 0) {
		if(n & 1LL)
			r = r*base;
		base = base*base;
		n >>= 1LL;
	}

	return (r.m[0][1] + r.m[0][0])%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	ll n, m, tc;
	cin >>tc;

	while(tc--) {
		cin >>n >>m;
		ll v1 = solve(n-1);
		ll v2 = solve(m);
		cout <<abs(v2- v1)%MOD <<endl;
	}

    return 0;
}

