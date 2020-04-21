#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e5 + 5;
int n;
ll x;
vector<int> g[N];
bool visit[N];
ll v[N];

ll dfs(int at) {
	visit[at] = true;
	ll ans = v[at];
	for(int viz:g[at]) {
		if(!visit[viz]) 
			ans += max(-x, dfs(viz));
	}
	return max(-x, ans);
}

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;

	while(tc--) {
		cin >>n >>x;
		for(int i = 0; i < n; i++) {
			cin >>v[i];
			visit[i] = false;
			g[i].clear();
		}

		for(int i = 0; i < n-1; i++) {
			int a, b;
			cin >>a >>b;
			g[a-1].pb(b-1);
			g[b-1].pb(a-1);
		}

		cout <<dfs(0) <<endl;

	}
    
    return 0;
}

