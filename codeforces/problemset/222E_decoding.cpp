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

const int N = 60;
const ll MOD = 1e9 + 7;
int TAM = 0;

struct mat {
	ll m[N][N];
	
	void allZero() {
		memset(m, 0, sizeof m);
	}

	void allOne() {
		for(int i = 0; i < TAM; i++) {
			for(int j = 0; j < TAM; j++) {
				m[i][j] = 1LL;
			}
		}
	}

	void id() {
		for(int i = 0; i < TAM; i++) {
			m[i][i] = 1LL;
		}
	}

	mat operator * (const mat &t) const {
		mat r;
		r.allZero();
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

int convert(char c) {
	if(c >= 'a' and c <= 'z') return c-'a';
	else return ('z'-'a'+1)+(c-'A');
}

ll fast_exp(mat base, ll e) {
	mat mans;
	mans.id();
	ll ans = 0;
	
	while(e > 0) {
		if(e&1) mans = mans*base;
		e >>= 1;
		base = base * base;
	}
	
	for(int i = 0; i < TAM; i++) {
		for(int j = 0; j < TAM; j++) {
			ans += mans.m[i][j];
			ans %= MOD;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	ll n, m;
	int k;
	cin >>n >>m >>k;
	TAM = m;

	mat t;
	t.allOne();
	for(int i = 0; i < k; i++) {
		string seq;
		cin >>seq;
		t.m[convert(seq[0])][convert(seq[1])] = 0LL;
	}
	
	cout <<fast_exp(t, n-1);

	return 0;
}

