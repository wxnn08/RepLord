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

const int N = 1e5 + 5;
vector<int> g[N], gin[N], ts;
bool visit[N];
int comp[N], parent, numSCC;

void init(int n) {
	parent = 0;
	ts.clear();
	for(int i = 0; i < n; i++) g[i].clear(), gin[i].clear();
}

void revdfs(int u) {
	visit[u] = true;
	for(auto v:gin[u]) 
		if(!visit[v]) revdfs(v);
	ts.pb(u);
}

void dfs(int u) {
	visit[u] = true;
	comp[u] = parent;
	for(auto v:g[u])
		if(!visit[v]) dfs(v);
}

void kosajaru(int n) {
	memset(&visit, 0, sizeof visit);
	for(int i = 0; i < n; i++) 
		if(!visit[i]) revdfs(i);

	memset(&visit, 0, sizeof visit);
	numSCC = 0;
	for(int i = n-1; i >= 0; i--) {
		if(!visit[ts[i]]) {
			parent = ts[i];
			dfs(ts[i]);
			numSCC++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	int tempo = 1;
	cin >>tc;

	while(tc--) {
		int n, m;
		cin >>n >>m;
		init(n);
		for(int i = 0; i < m; i++) {
			int u, v; cin >>u >>v;
			gin[u-1].pb(v-1);
		}
		
		kosajaru(n);
		cc(numSCC);
		for(int i = 0; i < n; i++) {
			cout <<i <<" - ";
			for(auto v:g[i]) cout <<v <<' ';
			cout <<endl;
		}
		
	}
	
	return 0;
}

