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
 
const int MOD = 1e9 + 9;
const int M = 3;

struct mat {
	
	ll m[M][M];
	
	mat() {
		memset(m, 0, sizeof m);
	}

	void trans() {
		m[0][0] = 1LL;
		m[0][1] = 1LL;
		m[0][2] = 1LL;
		m[1][0] = 1LL;
		m[1][1] = 0LL;
		m[1][2] = 0LL;
		m[2][0] = 0LL;
		m[2][1] = 1LL;
		m[2][2] = 0LL;
	}
	
	void id() {
		for(int i = 0; i < M; i++) {
			m[i][i] = 1;
		}
	}

	mat operator * (const mat &B) const {
		mat r;
		for(int i = 0; i < M; i++) {
			for(int j = 0; j < M; j++) {
				for(int k = 0; k < M; k++) {
					r.m[i][j] += (m[i][k] * B.m[k][j]) % MOD;
					r.m[i][j] %= MOD;
				}
			}
		}
		return r;
	}

	void print() {
		for(int i = 0; i < M; i++) {
			for(int j = 0; j < M; j++) {
				cout <<m[i][j] <<' ';
			}
			cout <<endl;
		}
	}
};

/*
 * Tribonacci 
 * 
 * 
 *
 * | f(i) |   |1 1 1| |f(i-1)|
 * |f(i-1)| = |1 0 0| |f(i-2)|
 * |f(i-2)|   |0 1 0| |f(i-3)|
 *
 */

mat exp(ll n) {
	mat ans, t;
	ans.id();
	t.trans();

	while(n > 0) {
		if(n & 1LL)
			ans = ans*t;
		t = t*t;
		n /= 2;
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	ll n;
    cin >>n;
    while(n > 0) {
		ll ans;
		if(n > 2) {
			mat r;
			r = exp(n-3);
			ans = (2*r.m[0][0] + r.m[0][1])%MOD;
		}
		else ans = n-1;
		cout <<ans <<endl;
		cin >>n;
	}

    return 0;
}

