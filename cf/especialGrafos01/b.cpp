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
ll cost[N];
bool visit[N];
vector<int> g[N];

ll dfs(int at) {
	visit[at] = true;
	ll ans = cost[at];
	for(auto viz:g[at]) {
		if(visit[viz]) continue;
		ans = min({ans, cost[viz], dfs(viz)});
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >>n >>m;

	for(int i = 1; i <= n; i++) {
		cin >>cost[i];
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >>u >>v;
		g[u].pb(v);
		g[v].pb(u);
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		if(!visit[i]) ans += dfs(i);
	}

	cout <<ans <<endl;
	return 0;
}

