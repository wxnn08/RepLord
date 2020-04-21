/* O nosso maior medo não é sermos inadequados.
O nosso maior medo é sermos infinitamente poderosos.
É a nossa própria luz, não a nossa escuridão, que nos amedronta.
Sermos pequenos não engrandece o mundo.
Não há nada de transcendente em sermos pequenos,
pois assim os outros não se sentirão inseguros ao nosso lado.
Todos estamos destinados a brilhar, como as crianças.
Não apenas alguns de nós, mas todos.
E, enquanto irradiamos a nossa admirável luz interior,
inconscientemente estamos a permitir aos outros fazer o mesmo.
E, quando nos libertarmos dos nossos próprios medos,
a nossa presença automaticamente libertará os medos dos outros.  */

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

const int N = 2505;
ll MOD = 1e9+7;
ll fat[N];

void init() {
	fat[0] = 1;
	for(int i = 1; i < N; i++) {
		fat[i] = i*fat[i-1];
		fat[i] %= MOD;
	}
}

ll fexp(ll b, ll e) {
	ll ans = 1;
	ll base = b % MOD;
	while(e > 0) {
		if(e&1) ans = (ans * base) % MOD;
		base = (base * base) % MOD;
		e >>= 1LL;
	}
	return ans;
}

ll nCr(ll n, ll r) {
	return (fat[n] * fexp(fat[r] * fat[n-r], MOD-2)) % MOD;
}

ll solve(ll k, ll cont, ll n) {
	if(cont == k) return 0;
	ll t1 = (nCr(k, k-cont) * (k-cont)) % MOD;
	ll t2 = (t1 * fexp(k-cont-1, n-1)) % MOD;
	return  (MOD+(t2 - solve(k, cont+1, n))) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	init();
	ll n, k;
	cin >>n >>k;
	
	cout <<solve(k, 0LL, n) <<endl;
	
	return 0;
}

