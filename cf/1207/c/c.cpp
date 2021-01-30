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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

// tamanho, custo cano, custo pilar
int n, a, b;
string s;
const int N = 2e5 + 5;
ll dp[N][4];
int vis[N][4];
int tempo = 1;

ll solve(int pos, int h) {
	if(pos == n) {
		if(h == 0) return b;
		return INF;
	}

	if(vis[pos][h] == tempo) return dp[pos][h];

	if(pos > 0 and (s[pos] == '1' or s[pos-1] == '1')
			and h == 0)
		return INF;

	// troca de altura
	ll L = solve(pos+1, 1-h) + ((1+h)*b) + (2*a);
	// mantem altura
	ll R = solve(pos+1, h) + ((1+h)*b) + a;

	vis[pos][h] = tempo;
	return dp[pos][h] = min(L, R);
}


void recovery(int pos, int h) {
	if(pos == n) {
		return;
	}

	ll L = solve(pos+1, 1-h) + ((1+h)*b) + (2*a);

	ll R = solve(pos+1, h) + ((1+h)*b) + a;

	if(L < R) {
		cout <<pos <<": troca" <<endl;
		recovery(pos+1, 1-h);
		return;
	}

	cout <<pos <<": mantem" <<endl;
	recovery(pos+1, h);

}

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin >>t;
	while(t--) {
		cin >>n >>a >>b >>s;
		cout <<solve(0, 0) <<endl;
		tempo++;
	}

	return 0;
}

