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
typedef pair<ll,ll> ii;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

const int N = 2e3 + 5;
ll dp[N][N];
vector<ii> v;

ll solve(int at, ll p) {
	if(p < 0) return -INF;
	if(at == v.size()) return 0;
	
	ll &r = dp[at][p];
	if(r != -1) return r;

	ll L = solve(at+1, p-v[at].fi) + v[at].se;
	ll R = solve(at+1, p);

	return r = max(L, R);
}
 
int main() {
	ios_base::sync_with_stdio(false);

	int p, n;
	cin >>p >>n;

	for(int i = 0; i < n; i++) {
		int peso, valor;
		cin >>peso >>valor;
		v.eb(peso,valor);
	}

	memset(dp, -1, sizeof dp);
	cout <<solve(0, p) <<endl;
	
	return 0;
}

