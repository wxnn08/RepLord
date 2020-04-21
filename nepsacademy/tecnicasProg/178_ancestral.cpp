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
int n, m;
int dp[N][N];
int vn[N], vm[N];

int solve(int cn, int cm) {
	if(cn == n or cm == m) return 0;

	int &r = dp[cn][cm];
	if(r != -1) return r;

	int L = -INF;
	if(vn[cn] == vm[cm]) L = solve(cn+1, cm+1) + 1;
	int R = max(solve(cn+1, cm), solve(cn, cm+1));

	return r = max(L, R);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >>n >>m;
	for(int i = 0; i < n; i++) cin >>vn[i];
	for(int i = 0; i < m; i++) cin >>vm[i];

	memset(dp, -1, sizeof dp);
	int maior = solve(0, 0);
	cout <<n-maior <<' ' <<m-maior <<endl;
	
	return 0;
}

