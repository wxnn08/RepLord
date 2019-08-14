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

const int N = 105;
const ll MOD = 1e9 + 7;
int TAM;
struct mat {
	ll m[N][N];
	
	mat() {
		allZero();
	}

	void allZero() {
		memset(m, 0LL, sizeof m);
	}

	void id() {
		for(int i = 0; i < N; i++) {
			m[i][i] = 1LL;
		}
	}
	
	mat operator * (const mat &t) const {
		mat r;
		for(int i = 0; i < TAM; i++) {
			for(int j = 0; j < TAM; j++) {
				for(int k = 0; k < TAM; k++) {
					r.m[i][j] += (m[i][k]*t.m[k][j]);
					r.m[i][j] %= MOD;
				}
			}
		}
		return r;
	}

	void print() {
		for(int i = 0; i < TAM; i++) {
			for(int j = 0; j < TAM; j++) {
				cout <<m[i][j] <<' ';
			}
			cout <<endl;
		}
	}
};

map<ll, int> mx;

ll digSum(ll a) {
	ll ans = 0;
	while(a) a -= (a ^ (a&(a-1LL))), ans++;
	return ans;
}

bool isValid(ll a, ll b) {
	return digSum(a^b)%3 == 0;
}

ll fast_exp(mat base, ll e) {
	mat ans;
	ans.id();
	while(e) {
		if(e&1) 
			ans = ans * base;
		base = base*base;
		e >>= 1LL;
	}
	
	ll vans = 0;
	for(int i = 0; i < TAM; i++) {
		for(int j = 0; j < TAM; j++) {
			vans += ans.m[i][j];
			vans %= MOD;
		}
	}

	return vans;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n; 
	ll k;
	cin >>n >>k;
	
	vector<ll> xs;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		xs.pb(a);
	}
	
	TAM = n;
	mat base;
	base.allZero();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			ll xi = xs[i], xj = xs[j];
			if(isValid(xi, xj)) base.m[i][j]++;
		}
	}

	//base.print();
	cout <<fast_exp(base, k-1) <<endl;

	return 0;
}

