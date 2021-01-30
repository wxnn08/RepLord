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

const int N = 9;
vector<int> g[N];
int v[N];
int n, m;
int used[N][N];
bool f;

int calc() {
	int ans = 0;
	memset(used, 0, sizeof used);
	for(int i = 1; i <= 7; i++) {
		for(auto viz:g[i]) {
			if(used[v[i]][v[viz]]) continue;
			used[v[i]][v[viz]] = 1;
			used[v[viz]][v[i]] = 1;
			ans++;
		}
	}
	return ans;
}

int solve(int at) {
	if(at > 7) return calc();
	int ans = 0;
	for(int i = 1; i <= 6; i++) {
		v[at] = i;
		ans = max(ans, solve(at+1));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >>n >>m;
	for(int i = 0; i < m; i++) {
		int u, v; cin >>u >>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	cout <<solve(1) <<endl;
	
	return 0;
}

