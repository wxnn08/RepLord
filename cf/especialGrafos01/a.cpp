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

const int N = 1e3 + 5;
vector<ii> g[N];
bool visit[N];

bool dfs(int at, int goal, int time) {
	if(at == goal) return true;
	visit[at] = true;
	bool ans = false;
	for(auto viz:g[at]) {
		if(!visit[viz.fi] and viz.se <= time)
			ans |= dfs(viz.fi, goal, time);
	}
	return ans;
}

int solve(int maxTimer, int goal) {
	int l = 0, r = maxTimer, ans = 0;
	while(l <= r) {
		int mid = (l+r)>>1;

		memset(visit, false, sizeof visit);

		if(dfs(0, goal, mid)) ans = mid, r = mid-1;
		else l = mid+1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;
	int maxTimer = 0;
	for(int i = 0; i < m; i++) {
		int u, v, t; cin >>u >>v >>t;
		g[u].eb(v, t);
		g[v].eb(u, t);
		maxTimer = max(maxTimer, t);
	}

	cout <<solve(maxTimer, n-1) <<endl;
	
	return 0;
}

