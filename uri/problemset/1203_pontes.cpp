#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 105;
const int M = 5e3;
int n;
int g[N], dp[N][M];

int solve(int at, int qtd) {
	if(qtd == 0) return 1;
	if(at >= n or qtd < 0) return 0;

	int &r = dp[at][qtd];
	if(~r) return r;

	int L = solve(at+1, qtd-g[at]);
	int R = solve(at+1, qtd);
	return r = max(L,R);
}

int main() {
	ios_base::sync_with_stdio(false);

	int m;
	while(cin >>n >>m) {
		memset(g, 0, sizeof g);
		memset(dp, -1, sizeof dp);
		for(int i = 0; i < m; i++) {
			int u, v; cin >>u >>v;
			g[u]++;
			g[v]++;
		}
		cout <<(solve(0, m)?'S':'N') <<endl;
	}
	
	return 0;
}

