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

ll b;

struct mat {
	ll v[3][3];
	mat() {
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				v[i][j] = 0LL;
	}
	void id() {
		for(int i = 0; i < 3; i++) 
			v[i][i] = 1LL;
	}
	void base() {
		v[0][0] = 1LL;
		v[0][1] = 1LL;
		v[0][2] = 1LL;
		v[1][0] = 1LL;
		v[2][2] = 1LL;
	}

	mat operator * (const mat &t) {
		mat ans;
		for(int i = 0; i < 3; i++) 
			for(int j = 0; j < 3; j++) 
				for(int k = 0; k < 3; k++) {
					ans.v[i][j] += (v[i][k] * t.v[k][j]);
					ans.v[i][j] %= b;
				}
		return ans;
	}
};

ll solve(ll e) {
	mat ans, base;
	ans.id();
	base.base();
	while(e > 0LL) {
		if(e&1LL) ans = ans * base;
		base = base * base;
		e >>= 1LL;
	}
	return (ans.v[0][0] + ans.v[0][1] + ans.v[0][2])%b;
}

int main() {

	ll n;
	int tc = 1;
	while(cin >>n >>b and (n or b)) 
		printf("Case %d: %lld %lld %lld\n", tc++, n, b, solve(n-1));
	
	return 0;
}

