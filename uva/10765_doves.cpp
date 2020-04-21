/* Aí, você já parou pra pensar, por que que você vive?
 * O que é que te move?
 * Aquele momento que decodifica o segredo da sua alma
 * E de repente tudo começa a fazer sentido.
 * É um chamado legítimo que vem lá do íntimo 
 * É quando a poesia entra em sincronia com o ritmo 
 * E te faz pensar 
 * Se não fosse isso eu podia até respirar, mas vivo eu também não ia tá!
 */
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
vector<int> g[N];
set<int> artv;
int tin[N], low[N], comps[N];
bool visit[N];
int tempo;

void dfs(int u, int p) {
	visit[u] = true;
	tin[u] = low[u] = tempo++;

	int children = 0;
	comps[u] = 1;
	for(int v:g[u]) {
		if(v == p) continue; 
		if(visit[v]) 
			low[u] = min(low[u], tin[v]);
		else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= tin[u] && p != -1)
				comps[u]++;

			++children;
		}
	}
	if(p == -1 and children > 1) 
		comps[u] = children;
}

void findArticulationPoints() {
	memset(tin, -1, sizeof tin);
	memset(low, -1, sizeof low);
	memset(visit, 0, sizeof visit);
	memset(comps, 0, sizeof comps);
	tempo = 0;
	dfs(0, -1);
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	while(cin >>n >>m) {
		if(n == 0 and m == 0) return 0;
		for(int i = 0; i < n; i++) g[i].clear();

		int a, b;
		while(cin >>a >>b) {
			if(a == -1 and b == -1) break;
			g[a].pb(b);
			g[b].pb(a);
		}

		findArticulationPoints();
		vector<ii> ans;
		for(int u = 0; u < n; u++) ans.eb(comps[u], u);

		sort(ans.begin(), ans.end(), [] (ii &a, ii &b) {
					return (a.fi != b.fi? a.fi > b.fi : a.se < b.se);
				});

		for(int i = 0; i < m; i++) 
			cout <<ans[i].se <<' ' <<ans[i].fi <<endl;
		cout <<endl;
	}
	
	return 0;
}

