#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int MOD = 1e9 + 7;
const int M = 55;

struct mat {
	ll m[M][M];
	
	mat() {
		memset(m, 0, sizeof m);
	}
	
	void id() {
		for(int i = 0; i < M; i++) {
			m[i][i] = 1LL;
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

	void read(int tam) {
		for(int i = 0; i < tam; i++) {
			for(int j = 0; j < tam; j++) {
				cin >>m[i][j];
			}
		}
	}

	void print(int tam) {
		for(int i = 0; i < tam; i++) {
			for(int j = 0; j < tam; j++) {
				cout <<m[i][j] <<' ';
			}
			cout <<endl;
		}
	}
};

mat exp(mat m, ll e) {
	mat ans;
	ans.id();

	mat base = m;

	while(e > 0) {
		if(e & 1LL)
			ans = ans * base;
		base = base*base;
		e /= 2;
	}
	
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;
	
	while(tc--) {
		int n;
		ll e;
		cin >>n >>e;

		mat m;
		m.read(n);
		m = exp(m, e);
		m.print(n);
	}
    
    return 0;
}

