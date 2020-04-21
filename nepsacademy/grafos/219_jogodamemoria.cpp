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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e5 + 5;
const int LOGN = 20;
vector<int> g[N];
int ancestral[N][LOGN];
int nivel[N];

void dfs(int at) {
	for(auto viz:g[at]) {
		if(nivel[viz] == -1) {
			ancestral[viz][0] = at;
			nivel[viz] = nivel[at] + 1;
			dfs(viz);
		}
	}
}

void init(int n, int raiz) {
	memset(ancestral, -1, sizeof ancestral);
	memset(nivel, -1, sizeof nivel);
	nivel[raiz] = 0;
	dfs(raiz);

	for(int j = 1; j < LOGN; j++) 
		for(int i = 1; i <= n; i++) 
			if(ancestral[i][j-1] != -1)
				ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
}

int LCA(int u, int v) {
	if(nivel[u] < nivel[v]) swap(u, v);

	for(int i = LOGN-1; i >= 0; i--) 
		if(nivel[u] - (1<<i) >= nivel[v]) 
			u = ancestral[u][i];
			
	if(u == v) return u;

	for(int i = LOGN-1; i >= 0; i--) 
		if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]) {
			u = ancestral[u][i];
			v = ancestral[v][i];
		}

	return ancestral[u][0];
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	vii par;
	for(int i = 1; i <= n; i++) {
		int a; cin >>a;
		par.eb(a, i);
	}
	sort(par.begin(), par.end());

	for(int i = 0; i < n-1; i++) {
		int a, b;
		cin >>a >>b;
		g[a].pb(b);
		g[b].pb(a);
	}

	init(n, 1);
	int ans = 0;
	for(int i = 0; i < n-1; i+=2) {
		int u = par[i].se;
		int v = par[i+1].se;
		ans += (nivel[u]+nivel[v]-2*nivel[LCA(u,v)]);
	}

	cout <<ans <<endl;

	return 0;
}
