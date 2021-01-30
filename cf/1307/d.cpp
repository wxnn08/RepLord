#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 2e5 + 5;

unordered_set<int> spec;
int value[N];
vector<int> g[N];
vector<int> rot[N];
vector<int> rott;

// Verifica quais nos realmente podem ser um caminho para dest 
int visit[N];
int dfs(int at, int ant, int dest) {
	visit[at] = 1;
	if(at == dest) return value[at] = 1;
	
	int ans = 0;
	for(auto viz:g[at]) {
		if(at == ant) continue;
		if(!visit[viz]) dfs(viz, at, dest);
		ans |= value[viz];
	}
	value[at] = ans;
}

// Calcula distancia dos nos e armazena em rot[dist]
// Marca que existe aquela distancia em rott
int bfs_rot(int ini) {

	int vis[N], dist[N];

	memset(vis, 0, sizeof vis);
	memset(dist, INF, sizeof dist);
	queue<int> q;
	q.push(ini);
	dist[ini] = 0;
	if(spec.count(ini)){
		rot[dist[ini]].pb(ini);
		rott.pb(dist[ini]);
	}

	while(q.size()) {
		int at = q.front();
		q.pop();
		if(vis[at]) continue;
		vis[at] = true;

		for(auto viz:g[at]) {
			if(vis[viz]) continue;
			if(dist[viz] > dist[at] + 1) {
				dist[viz] = dist[at] + 1;
				if(spec.count(viz)){
					rot[dist[viz]].pb(viz);
					rott.pb(dist[viz]);
				}
				q.push(viz);
			}
		}
	}
}

// calcula menor distancia de ini ate dest
int bfs_distance(int ini, int dest) {

	int vis[N], dist[N];
	memset(vis, 0, sizeof vis);
	memset(dist, INF, sizeof dist);
	queue<int> q;
	q.push(ini);
	dist[ini] = 0;

	while(q.size()) {
		int at = q.front();
		q.pop();
		if(at == dest) return dist[at];
		if(vis[at]) continue;
		vis[at] = true;

		for(auto viz:g[at]) {
			if(vis[viz]) continue;
			if(dist[viz] > dist[at] + 1) {
				dist[viz] = dist[at] + 1;
				q.push(viz);
			}
		}
	}
	return INF;
}

int main() {
    ios_base::sync_with_stdio(false);

	int n, m, k; cin >>n >>m >>k;
	for(int i = 0; i < k; i++) {
		int a; cin >>a; spec.insert(a);
	}
	for(int i = 0; i < m; i++) {
		int u, v; cin >>u >>v;
		g[u].pb(v);
		g[v].pb(u);
	}

	int ans = bfs_distance(1, n);

	dfs(1, -1, n);
	int cont = 0;
	for(int i = 1; i <= n; i++) {
		if(!value[i] and spec.count(i)) cont++;
		if(cont > 1) {
			cout <<ans <<endl;
			return 0;
		}
	}

	bfs_rot(1);
	for(int i = 0; i < N; i++) {
		if(rot[i].size() > 1) {
			cout <<ans <<endl;
			return 0;
		}
	}

	sort(rott.begin(), rott.end());
	rott.resize(unique(rott.begin(), rott.end()) - rott.begin());

	int idi, idj, dd = INT_MAX;
	for(int i = 1; i < rott.size(); i++) {
		if(rott[i]-rott[i-1] < dd) {
			idi = rott[i];
			idj = rott[i-1];
			dd = rott[i]-rott[i-1];
		}
	}
	
	idi = rot[idi][0];
	idj = rot[idj][0];
	g[idi].pb(idj);
	g[idj].pb(idi);
	cout <<bfs_distance(1, n) <<endl;

    return 0;
}

