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

const int N = 12;
const ll MOD = 1e9+7;

struct no {
	int a;
	int b; 
	int c;
};

struct mat {
	ll m[N][N];
	
	mat(){
		memset(m, 0, sizeof m);
	}
	
	void id() {
		for(int i = 0; i < N; i++)
			m[i][i] = 1LL;
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
		return;
	}
};

no t[N];
mat g;

bool isValid(no a, no b) {
	if(a.a == b.a or a.b == b.b or a.c == b.c)
		return 0;
	if(a.a == a.b or a.b == a.c)
		return 0;
	if(b.a == b.b or b.b == b.c)
		return 0;
	return 1;
}

void gen() {
	int cont = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				if(i == j or j == k) continue;
				t[cont].a = i;
				t[cont].b = j;
				t[cont].c = k;
				cont++;
			}
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(isValid(t[i], t[j])) {
				g.m[i][j] = 1LL;
			}
		}
	}

	return;
}

mat fastexp(ll n) {
	mat r;
	r.id();
	mat base = g;
	while(n > 0) {
		if(n & 1LL)
			r = r * base;
		base = base * base;
		n >>= 1LL;
	}
	return r;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	gen();

	ll n;
	cin >>n;

	mat h = fastexp(n-1);
	ll ans = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			ans = (ans + h.m[i][j])%MOD;
		}
	}
	cout <<ans <<endl;
    return 0;
}

