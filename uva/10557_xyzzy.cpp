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
typedef pair<int,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
const int N = 105;
ll dist[N];
vector<ii> g[N];
bool visit[N];

bool dfs(int at, int dest) {
	if(at == dest) return true;
	if(visit[at]) return false;
	visit[at] = true;
	for(auto viz:g[at]) 
		if(dfs(viz.fi, dest)) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	while(cin >>n) {
		if(n == -1) return 0;

		for(int i = 1; i <= n; i++) g[i].clear();
		memset(visit, 0, sizeof visit);
		int v[N];

		for(int i = 1; i <= n; i++) {
			int w, qtd;
			cin >>v[i] >>qtd;
			for(int j = 0; j < qtd; j++) {
				int u; cin >>u;
				g[i].eb(u, 0);
			}
		}
		for(int i = 1; i <= n; i++) 
			for(auto &at:g[i]) 
				at.se = v[at.fi];

		memset(dist, -INF, sizeof dist);
		dist[1] = 100;
		for(int i = 1; i <= n-1; i++) {
			for(int u = 1; u <= n; u++) {
				if(dist[u] <= 0) continue;
				for(auto at:g[u]) 
					dist[at.fi] = max(dist[at.fi], dist[u]+at.se);
			}
		}

		bool ciclo = false;
		for(int u = 1; u <= n; u++) {
			if(dist[u] <= 0) continue;
			for(auto at:g[u]) {
				if((dist[at.fi] < dist[u] + at.se) and dfs(u, n))
					ciclo = true;
			}
		}
		cout <<(ciclo or dist[n] > 0?"winnable":"hopeless") <<endl;
	}
	
	return 0;
}

