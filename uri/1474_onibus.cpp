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

const int N = 2;
const ll MOD = 1e6;
ll n, k, l;

struct mat {
	ll m[N][N];
	
	mat() {
		memset(m, 0LL, sizeof m);
	}

	void id() {
		for(int i = 0; i < N; i++)
			m[i][i] = 1LL;
	}

	void trans() {
		m[0][0] = k;
		m[0][1] = l;
		m[1][0] = 1LL;
		m[1][1] = 0LL;
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

	void print() {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				cout <<m[i][j] <<' ';
			}
			cout <<endl;
		}

	}
};

mat fastexp(ll e) {
	mat base, r;
	r.id();
	base.trans();
	while(e > 0LL) {
		if(e & 1LL)
			r = r * base;
		base = base * base;
		e >>= 1LL;
	}
	return r;
}

int main(){

    while(cin >>n) {
		cin >>k >>l;
		k %= MOD;
		l %= MOD;
		n /= 5;
		mat ans;
		ll v;
		if(n == 1)
			v = k;
		else {
			ans = fastexp(n-2);
			ll a = k;
			ll b = (((k*k)%MOD) + l%MOD)%MOD;
			v = ((b*ans.m[0][0])%MOD + (a*ans.m[0][1])%MOD)%MOD;
		}
		printf("%06lld\n", v);
	}
    return 0;
}

