#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 3e5 + 5;
bool rvisit[N];
bool visit[N];
bool cor[N];
vector<int> g[N];
int n, m;

int bfs(int pri, int colo) {
	memset(visit, 0, sizeof(bool) * (n+1));
	memset(cor, 0, sizeof(bool) * (n+1));

	queue<int> q;
	q.push(pri);
	visit[pri] = true;
	rvisit[pri] = true;
	cor[pri] = colo;

	int ans = colo;
	while(!q.empty()) {
		int at = q.front();
		q.pop();
		colo = 1-cor[at];
		for(int i = 0; i < g[at].size(); i++) {
			int viz = g[at][i];
			if(visit[viz]) {
				if(colo != cor[viz])
					return -1;
			}
			else {
				rvisit[viz] = true;
				visit[viz] = true;
				cor[viz] = colo;
				q.push(viz);
				ans += colo;
			}
		}
	}

	return ans;
}

const int MOD = 998244353;
	
ll fastexp(ll n, ll m) {
	if(m == 0) 
		return 1;
	ll ans = fastexp(n, m/2);
	ans = (ans * ans) % MOD;

	if(m%2 == 1)
		ans *= n;

	return ans%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int tc;
	cin >>tc;

	while(tc--) {

		cin >>n >>m;
		memset(rvisit, 0, sizeof(bool)*n+1);

		for(int i = 0; i < n+1; i++) {
			g[i].clear();
		}

		for(int i = 0; i < m; i++) {
			int a, b;
			cin >>a >>b;
			g[a].pb(b);
			g[b].pb(a);
		}

		vector<pair<int, int>> val;
		vector<int> pos;
		for(int i = 1; i <= n; i++){ 
			if(!rvisit[i]) {
				pos.pb(i);
				ll t1, t2;
				t1 = bfs(i, 0);
				t2 = bfs(i, 1);
				val.eb(t1, t2);
			}
		}

		ll ansf = 1;
		for(int i = 0; i < val.size(); i++) {
			ll ans = 0;
			ll v1 = val[i].fi;
			ll v2 = val[i].sec;
			if(v1 == -1 and v2 == -1) {
				ansf = 0;
				break;
			}
			if(v1 > 0) ans += fastexp(2LL, v1);
			if(v1 == 0 and g[pos[i]].size() == 0) ans += 1;
			if(v2 > 0) ans += fastexp(2LL, v2);
			ans %= MOD;
			ansf = ansf*ans;
			ansf %= MOD;
		}
		cout <<ansf%MOD <<endl;
	}

    
    return 0;
}

