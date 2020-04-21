#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int TAM = 2e3+5;
int vis[TAM];
vector<int> g[TAM];

void dfs(int at){
	vis[at]=true;

	for(int i=0; i<(int)g[at].size(); i++){
		if(!vis[g[at][i]])
			dfs(g[at][i]);
	}
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
	while(cin >>n, n){
		cin >>m;
		for(int i=0; i<TAM; i++)
			g[i].clear();

		for(int i=0; i<m; i++){
			int u, v, p;
			cin >>u >> v >>p;
			g[u].pb(v);
			if(p==2) g[v].pb(u);	
		}

		bool res=true;
		for(int i=1; i<=n; i++){
			memset(vis, 0, sizeof(vis));
			dfs(i);
			for(int j=1; j<=n; j++){
				if(vis[j]==0) res=false;
			}
		}
		if(res) cout <<1;
		else cout <<0;
		cout <<endl;
	}
    return 0;
}

