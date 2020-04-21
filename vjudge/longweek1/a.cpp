#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 5e3 + 5;
int fat[N];
int visit[N];
vector<int> g[N];

int dfs(int curr, int tempo) {
	visit[curr] = tempo;
	int ans = 0;
	for(int viz:g[curr]) {
		if(viz != tempo) ans = max(ans, dfs(viz, tempo));
	}
	return 1 + ans;
}


int main() {
    ios_base::sync_with_stdio(false);

	while(true) {
		map<string, int> id;
		int c, r; cin >>c >>r;
		if(c == 0 and r == 0) break;
		for(int i = 0; i < c; i++) {
			string animal; 
			cin >>animal;
			id[animal] = i;
		}

		for(int i = 0; i < r; i++) {
			string s, t; cin >>s >>t;
			g[id[t]].pb(id[s]);
			fat[id[s]]++;
		}

		int ans = 0;
		memset(visit, -1, sizeof visit);
		for(int i = 0; i < c; i++) {
			if(!fat[i]) ans = max(ans, dfs(i, i));
		}

		for(int i = 0; i < c; i++) {
			if(visit[i] == -1) ans = max(ans, dfs(i, i));
		}

		cout <<ans <<endl;

	}
    return 0;
}

