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

struct Edge { int a, b, w; };

const int N = 505;
const int M = 1e4 + 5;
vector<int> g[N];
vector<Edge> edges;
bool hab[M];
int dist[N];
vector<int> parent[N];
 
int dij(int ini, int fim) {
	bool visit[N];
	memset(visit, false, sizeof visit);
	memset(dist, INF, sizeof dist);
	dist[ini] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.emplace(dist[ini], ini);

	while(!pq.empty()) {
		int at = pq.top().se;
		int wat = pq.top().fi;
		pq.pop();
		if(visit[at]) continue;
		visit[at] = true;
		for(auto e:g[at]) {
			if(!hab[e]) continue;
			int a = edges[e].a;
			int b = edges[e].b;
			int w = edges[e].w;

			if(dist[b] == wat + w) 
				parent[b].pb(e);

			if(dist[b] > wat + w) {
				dist[b] = wat + w;
				parent[b].clear();
				parent[b].pb(e);
				pq.emplace(dist[b], b);
			}
		}
	}
	return dist[fim];
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	while(cin >>n >>m) {
		if(n == 0 and m == 0) break;
		int s, t;
		cin >>s >>t;

		edges.clear();
		for(int i = 0; i < n; i++) g[i].clear(), parent[i].clear();

		for(int i = 0; i < m; i++) {
			int a, b, w;
			cin >>a >>b >>w;
			hab[i] = true;
			edges.pb({a, b, w});
			g[a].pb(i);
		}
		
		dij(s,t);

		// Remove todas as arestas que pertencem ao caminho mínimo:
		queue<int> q;
		q.push(t);
		while(!q.empty()) {
			int at = q.front();
			q.pop();
			for(auto e:parent[at]) {
				hab[e] = false;
				q.push(edges[e].a);
			}
		}
		// -------------------------------------------------------

		int menor = dij(s, t);
		cout <<(menor >= INF? -1 : menor) <<endl;
	}
	
	return 0;
}

