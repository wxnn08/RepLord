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
int n;
int dp[N][N];
int v[N];

int solve(int at, int last) {
	if(at == n) return 0;
	
	int &r = dp[at][last];
	if(r != -1) return r;

	int L = -INF;
	if(v[at] >= last) L = solve(at+1, v[at]) + 1;
	int R = solve(at+1, last);

	return r = max(L, R);
}
 
int main() {
	ios_base::sync_with_stdio(false);

	cin >>n;
	vector<int> ve;
	for(int i = 0; i < n; i++) cin >>v[i], ve.pb(v[i]);

	sort(ve.begin(), ve.end());
	ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
	map<int, int> id;
	for(int i = 1; i <= ve.size(); i++) id[ve[i-1]] = i;
	for(int i = 0; i < n; i++) v[i] = id[v[i]];
	
	memset(dp, -1, sizeof dp);
	cout <<solve(0, 0) <<endl;
	
	return 0;
}

