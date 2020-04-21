#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
const int N = 505;
map<int, int> id;
int idade[N];
vector<int> g[N];

int dfs(int n) {
	int at = id[n];
	int menor = idade[at];
	for(int i = 0; i < g[at].size(); i++) {
		menor = min(menor, dfs(id[g[at][i]]));
	}
	return menor;
}

int main(){
    ios_base::sync_with_stdio(false);

	int n, m, op;
	cin >>n >>m >>op;
	
	for(int i = 0; i < n; i++) {
		id[i] = i;
		cin >>idade[i];
	}

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >>u >>v;
		g[v].pb(u);
	}

	while(op--) {
		char c; cin >>c;
		int u; cin >>u;
		if(c == 'T') {
			int v; cin >>v;
			int aux = id[u];
			id[u] = id[v];
			id[v] = aux;
			continue;
		}
		if(g[id[u]].size() == 0) {
			cout <<'*' <<endl;
			continue;
		}
		int menor = 999;
		for(int i = 0; i < g[id[u]].size(); i++) {
			menor = min(menor, dfs(id[u]));
		}
		cout <<menor <<endl;
	}
    
    return 0;
}

