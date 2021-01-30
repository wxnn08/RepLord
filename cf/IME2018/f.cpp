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
int n, m;
vector<int> g[N];
int dp[N][2];

int solve(int pai, int at, bool ant) {
	int &r = dp[at][ant];
	if(r != -1) return r;
	
	int L = 1, R = 0;
	for(int viz:g[at]) {
		if(viz == pai) continue;
		L += solve(at, viz, 1);
		R += solve(at, viz, 0);
	}
	if(ant) return r = R;
	return r = max(L, R);
}

int main() {
	//ios_base::sync_with_stdio(false);

	cin >>n >>m;
	for(int i = 0; i < m; i++) {
		int a, b; cin >>a >>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	memset(dp, -1, sizeof dp);
	cout <<solve(-1, 1, 0) <<endl;
	
	return 0;
}

