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

const int N = 1e4 + 5;
const int MOD = 1e9 + 7;
ll dp[N];
ll solve(int n) {
	if(n == 0) return 1;
	ll &r = dp[n];
	if(r != -1) return r;
	ll ans = 0;
	if(n > 2) ans = (ans + ((solve(n-3) * 2) % MOD)) % MOD;
	if(n > 1) ans = (ans + ((solve(n-2) * 4) % MOD)) % MOD;
	if(n > 0) ans = (ans + ((solve(n-1) * 1) % MOD)) % MOD;
	return r = ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	memset(dp, -1, sizeof dp);
	cout <<solve(n) <<endl;
	
	return 0;
}
