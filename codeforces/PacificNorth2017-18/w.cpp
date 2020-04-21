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

const int N = 30 + 5;
int n, m;
char mat[N][N];
int maxB[N];
ll dp[N][N];

ll solve(int col, int last) {
	if(col == m+1) return 1;
	ll &r = dp[col][last];
	if(r != -1) return r;

	ll ans = (maxB[col] == 0);
	for(int i = max(1,maxB[col]); i <= n; i++) {
		if(last >= i and (mat[i][col] == '.' or mat[i][col] == 'B')) 
			ans += solve(col+1, i);
	}
	return r = ans; 
} 

void saida(int n) {
	cout <<n <<endl;
	exit(0);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >>n >>m;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >>mat[i][j];
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(i > 1) {
				if(mat[i][j] == 'B' and mat[i-1][j] == 'R') saida(0);
				if(mat[i][j] == '.' and mat[i-1][j] == 'R') mat[i][j] = 'R';
			}
			if(j > 1) {
				if(mat[i][j] == 'B' and mat[i][j-1] == 'R') saida(0);
				if(mat[i][j] == '.' and mat[i][j-1] == 'R') mat[i][j] = 'R';
			}
		}
	}

	for(int i = n; i >= 1; i--) {
		for(int j = m; j >= 1; j--) {
			if(i < n) {
				if(mat[i][j] == 'R' and mat[i+1][j] == 'B') saida(0);
				if(mat[i][j] == '.' and mat[i+1][j] == 'B') mat[i][j] = 'B';
			}
			if(j < m) {
				if(mat[i][j] == 'R' and mat[i][j+1] == 'B') saida(0);
				if(mat[i][j] == '.' and mat[i][j+1] == 'B') mat[i][j] = 'B';
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(mat[i][j] == 'B') maxB[j] = i;
		}
	}
	
	memset(dp, -1, sizeof dp);
	cout <<solve(1, n) <<endl;

	return 0;
}

