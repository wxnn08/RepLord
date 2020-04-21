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
 
const int N = 35;
int n, m;
string mat[N];
ll dp[N][N];

ll solve(int col, int last) {
	if(col == m) return 1;

	ll &r = dp[col][last];
	if(r != -1) return r;

	int L = 0;
	int R = last;

	for(int i = 0; i <= n; i++) 
		if(mat[i][col] == 'B') L = i;

	for(int i = R; i >= 0; i--) 
		if(mat[i][col] == 'R') R = i-1;

	ll ans = 0;
	for(int i = L; i <= R; i++) {
		ans += solve(col+1, i);
	}
	return r = ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >>n >>m;
	for(int i = 1; i <= n; i++) 
		cin >>mat[i];
	
	memset(dp, -1, sizeof dp);
	cout <<solve(0, n) <<endl;
	
	return 0;
}

