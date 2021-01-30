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

const int N = 4;
const ll MOD = 1e9+7;

struct mat {
	ll m[N][N];
	
	mat() {
		memset(m, 0LL, sizeof m);
	}

	void base() {
		for(int i = 0; i < N; i++) 
			for(int j = 0; j < N; j++) 
				m[i][j] = (i == j? 0LL:1LL);
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

	void print() {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++)
				cout <<m[i][j] <<' ';
			cout <<endl;
		}
	}
};

mat fast_exp(ll e) {
	mat ans, base;
	ans.id();
	base.base();

	while(e > 0) {
		if(e&1LL) ans = ans * base;
		base = base * base;
		e >>= 1LL;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	ll n;
	cin >>n;
	mat r = fast_exp(n);
	cout <<r.m[3][3] <<endl;;

	return 0;
}

