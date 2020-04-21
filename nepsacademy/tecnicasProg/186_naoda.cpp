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
int dp[N][N];
vector<int> v;

 
int solve(int at, int t) {
	if(t == 0) return 1;
	if(t < 0) return 0;
	if(at >= v.size()) return 0;

	int &r = dp[at][t];
	if(r != -1) return r;

	int L = solve(at, t-v[at]);
	int R = solve(at+1, t);

	return r = max(L, R);
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;
	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		v.pb(a);
	}

	memset(dp, -1, sizeof dp);
	int ans = 0;
	for(int i = m-1; i >= 0; i--) {
		if(solve(0, i) == 0) {
			ans++;
		}
	}
	cout <<ans <<endl;
	
	return 0;
}

