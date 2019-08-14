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

const int N = 21;
const int M = 262145;

struct node {
	bool mat[N][N];
	int qtd;
};

int n, a, goal;
vector<node> v;
vector<ii> g[N];
set<ii> reset;

int choose(int x, int y) {
	int ac = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(v[x].mat[i][j] != v[y].mat[i][j]) ac++;
		}
	}

	if(ac > a+v[y].qtd) {
		reset.insert(ii(x, y));
		return a+v[y].qtd;
	}
	return ac;
}

int dp[N][M];
int solve(int at, int mask) {
	if(mask == goal) return 0;

	int &r = dp[at][mask];
	if(r != -1) return r;
	
	int l = INF;
	for(auto viz:g[at]) {
		if((mask & (1<<viz.fi)) > 0) continue;
		l = min(l, viz.se + solve(viz.fi, mask|(1<<viz.fi)));
	}

	return r = l;
}

void recovery(int at, int mask) {
	cout <<at+1 <<endl;
	if(mask == goal) return;

	int l = INF;
	int nxt = -1;
	for(auto viz:g[at]) {
		if((mask & (1<<viz.fi)) > 0) continue;
		int ll = viz.se + solve(viz.fi, mask|(1<<viz.fi));
		if(l > ll) {
			l = ll;
			nxt = viz.fi;
		}
	}

	if(reset.count(ii(at, nxt))) cout <<'*' <<endl;
	recovery(nxt, mask|(1<<nxt));

	return;
}

void go() {
	int ans = INF;
	int id = 0;
	
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < n; i++) {
		int mask = 0;
		int x = v[i].qtd + solve(i, mask|(1<<i));
		if(ans > x) {
			ans = x;
			id = i;
		}
	}
	
	cout <<ans <<endl;
	int mask = 0;
	recovery(id, mask|(1<<id));
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >>n >>a;

	for(int k = 0; k < n; k++) {
		node t;
		t.qtd = 0;
		for(int i = 0; i < N; i++) {
			string s; cin >>s;
			for(int j = 0; j < N; j++) {
				int at = s[j]-'0';
				if(at == 1) t.qtd++;
				t.mat[i][j] = at;
			}
		}
		v.pb(t);
	}
	
	for(int i = 0; i < n; i++) {
		goal |= (1<<i);
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			g[i].eb(j, choose(i, j));
			g[j].eb(i, choose(j, i));
		}
	}

	go();

	return 0;
}

