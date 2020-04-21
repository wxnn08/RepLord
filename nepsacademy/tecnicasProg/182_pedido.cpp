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
 
const int N = 1e3 + 5;
int dp[55][N];
vector<ii> v;

int solve(int at, int c) {
	if(c < 0) return -INF;
	if(at == v.size()) return 0;

	int &r = dp[at][c];
	if(r != -1) return r;

	int L = solve(at+1, c - v[at].fi) + v[at].se;
	int R = solve(at+1, c);

	return r = max(L, R);
}


int main() {
	ios_base::sync_with_stdio(false);

	int c, f, cont = 1;
	while(cin >>c >>f) {
		memset(dp, -1, sizeof dp);
		v.clear();

		if(c == 0 and f == 0) return 0;
		for(int i = 0; i < f; i++) {
			int comp, num;
			cin >>comp >>num;
			v.eb(comp, num);
		}

		cout <<"Teste " <<cont++ <<endl <<solve(0, c) <<endl <<endl;
	}
	
	return 0;
}

