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

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e2+5;
vector<int> g[N];

int par[N];

void solve(int at, int t){
	
}

void dfs(int at){
	
	for(int i=0; i<g[at].size(); i++){
		int next = g[at][i];
		if(next == par[at]) continue;
		par[next] = at;
		dfs(next);
	}
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;

	fori(i,0,n-1){
		int u, v;
		cin >>u >>v;
		g[u].pb(v);
		g[v].pb(u);
	}
    
	for(int i=0; i<n; i++){
		if(g[i].size() == 1) solve(i, 0);
	}

	for(int i=1; i<n; i++) cout <<ans[i] <<' ';
	cout <<endl;

    return 0;
}

