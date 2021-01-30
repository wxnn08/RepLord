#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define cc(x) cout <<#x <<" = " <<x <<endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> tiii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e5 + 5;
const int LOGN = log2(N) + 2;
vector<ii> g[N];
int anc[N][LOGN];
int maxEd[N][LOGN];
int nivel[N];
int pai[N];
int qtd[N];

int find(int x) {
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y) {
	int a = find(x);
	int b = find(y);

	if(a == b) return;
	if(qtd[a] > qtd[b]) swap(a, b);
	pai[a] = b;
	qtd[b] += qtd[a];
}

void dfs(int at) {
	for(auto viz:g[at]) {
		if(nivel[viz.fi] == -1) {
			anc[viz.fi][0] = at;
			maxEd[viz.fi][0] = viz.se;
			nivel[viz.fi] = nivel[at] + 1;
			dfs(viz.fi);
		}
	}
}

void init(int n, int raiz) {
	memset(anc, -1, sizeof anc);
	memset(nivel, -1, sizeof nivel);
	nivel[raiz] = 0;
	dfs(raiz);

	for(int j = 1; j < LOGN; j++) 
		for(int i = 1; i <= n; i++) {
			if(anc[i][j-1] != -1) {
				anc[i][j] = anc[anc[i][j-1]][j-1];
				maxEd[i][j] = max({maxEd[i][j], maxEd[anc[i][j-1]][j-1], maxEd[i][j-1]}); // pq o 3 elemento?
			}
		}
}

int LCA(int u, int v) {
	if(nivel[u] < nivel[v]) swap(u, v);

	int ans = 0;
	for(int i = LOGN-1; i >= 0; i--) 
		if(nivel[u] - (1<<i) >= nivel[v]) {
			ans = max(ans, maxEd[u][i]);
			u = anc[u][i];
		}

	if(u == v) return ans;
			
	for(int i = LOGN-1; i >= 0; i--) 
		if(anc[u][i] != -1 and anc[u][i] != anc[v][i]) {
			ans = max({ans, maxEd[u][i], maxEd[v][i]});
			u = anc[u][i];
			v = anc[v][i];
		}
	ans = max({ans, maxEd[u][0], maxEd[v][0]});
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;
	vector<tiii> edges;
	map<ii, int> peso;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >>u >>v >>w;
		edges.eb(w, u, v);
		peso[ii(u,v)] = w;
		peso[ii(v,u)] = w;
	}

	sort(edges.begin(), edges.end());

	set<ii> mst;
	for(int i = 1; i <= n; i++) pai[i] = i, qtd[i] = 1;
	int sum = 0;
	for(auto ed:edges) {
		int w, u, v;
		tie(w, u, v) = ed;
		if(find(u) != find(v)) {
			sum += w;
			join(u, v);
			mst.insert(ii(u, v));
			mst.insert(ii(v, u));
			g[u].eb(v, w);
			g[v].eb(u, w);
		}
	}

	init(n, 1);
	int q;
	cin >>q;
	while(q--) {
		int u, v;
		cin >>u >>v;
		if(mst.count(ii(u,v))) cout <<sum <<endl;
		else cout <<sum+peso[ii(u,v)]-LCA(u,v) <<endl;
	}

	return 0;
}
