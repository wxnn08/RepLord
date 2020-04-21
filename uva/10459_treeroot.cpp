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

const int N = 5e3 + 5;
vector<int> g[N];
int dist[N];
int visit[N];
int d[N];
int in[N];
int timer;
vector<int> path;

int dfs(int u, int nv) {
	visit[u] = timer;
	in[u] = nv;
	int ans = 0;
	for(int v:g[u]) {
		if(visit[v] == timer) continue;
		ans = max(ans, dfs(v, nv+1) + 1);
	}
	return d[u] = ans;
}

void recovery(int u) {
	if(u == -1) return;
	visit[u] = timer;
	path.pb(u);
	int ans = -1;
	int nxt = -1;
	for(int v:g[u]) {
		if(visit[v] == timer) continue;
		if(d[v] > ans) ans = d[v], nxt = v;
	}
	recovery(nxt);
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int n;
	while(cin >>n) {
		timer = 1;
		path.clear();
		for(int u = 1; u <= n; u++) {
			g[u].clear();
			visit[u] = 0;
			int m; cin >>m;
			while(m--) {
				int v; cin >>v;
				g[u].pb(v);
			}
		}

		int d = dfs(1, 0);
		timer++;
		int diametro;
		for(int u = 1; u <= n; u++) {
			if(in[u] == d) {
				diametro = dfs(u, 0);
				timer++;
				recovery(u);
				timer++;
				break;
			}
		}

		set<int> worst, best;

		for(int i = 0; i < path.size(); i++) {
			if(i == diametro/2 or i == (diametro/2) + (diametro%2)) {
				best.insert(path[i]);

				int w = dfs(path[i], 0);
				timer++;
				for(int u = 1; u <= n; u++)
					if(in[u] == w) worst.insert(u);
			}
		}

		cout <<"Best Roots  :";
		for(auto u:best) cout <<' ' <<u;
		cout <<endl;

		cout <<"Worst Roots :";
		for(auto u:worst) cout <<' ' <<u;
		cout <<endl;

	}
	return 0;
}

