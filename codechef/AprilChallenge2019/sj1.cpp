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
vector<int> g[N];
bool visit[N];
ll v[N];
ll m[N];
ll ans[N];

void solve(int at, ll gcd) {
	visit[at] = true;
	for(int viz:g[at]) {
		if(!visit[viz]) {
			solve(viz, __gcd(gcd, v[at]));
		}
	}
	
	gcd = __gcd(gcd, v[at]);

	if(g[at].size() == 1 and at != 0) {
		if(gcd <= m[at]) ans[at] = m[at]-gcd;
		else {
			// Alguma coisa aqui
		}
	}

	return;
}

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;
	while(tc--) {
		int n; cin >>n;

		memset(ans, -1, sizeof ans);
		memset(visit, 0, sizeof visit);
		for(int i = 0; i < n; i++) g[i].clear();

		for(int i = 0; i < n-1; i++) {
			int a, b; cin >>a >>b;
			g[a-1].pb(b-1);
			g[b-1].pb(a-1);
		}
		for(int i = 0; i < n; i++) cin >>v[i];
		for(int i = 0; i < n; i++) cin >>m[i];
		
		solve(0, v[0]);
		for(int i = 0; i < n; i++) {
			if(ans[i] != -1) 
				cout <<ans[i] <<' ';
		}
		cout <<endl;
		
	}
    
    return 0;
}

