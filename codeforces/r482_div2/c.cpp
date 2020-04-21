#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 3e5 + 5;
vector<int> g[N];
ll n, x, y;
bool visit[N];
ll dfs(int at, int dest, ll f) {
	visit[at] = true;
	
	ll ans = 0;
	for(int k:g[at]) {
		if(visit[k]) continue;
		ans += dfs(k, dest, f+(dest==at));
	}

	return ans + f;
}

int main() {
    ios_base::sync_with_stdio(false);

	cin >>n >>x >>y;

	for(int i = 0; i < n-1; i++) {
		int a, b;
		cin >>a >>b;
		g[a].pb(b);
		g[b].pb(a);
	}
    
	memset(visit, 0, sizeof visit);
	ll no = dfs(x, y, 0)+1;
	memset(visit, 0, sizeof visit);
	ll si = dfs(y, x, 0)+1;

	ll ans = (n*(n-1));
	ans -= (si*no);
	cout <<ans <<endl;
    return 0;
}

