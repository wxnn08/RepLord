#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e2 + 5;
vector<int> g[N];
int color[N];

/*
	Cores:
	-1 -> nao colorido
	 1 -> preto
	 0 -> branco
*/

int n, m;
vector<int> ans, step;
void colo(int lastColo, int at) {
	if(ans.size() == n/2) return;
	int atColo = 1;
	for(int i = 0; i < g[at].size() and atColo == 1; i++) {
		if(color[g[at][i]] == 1) 
			atColo = 0;
	}

	for(int i = 0; i < g[at].size(); i++) {
		int viz = g[at][i];
		if(color[viz] == -1) {
			if(atColo == 1) {
				step.pb(at);
				color[at] = 1;
				colo(color[at], viz);
				step.pop_back();
				color[at] = -1;
			}
			color[at] = 0;
			colo(color[at], viz);
			color[at] = -1;
		}
	}
	if(step.size() > ans.size())
		ans = step;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc;
	cin >>tc;
	memset(color, -1, sizeof color);
	while(tc--) {
		cin >>n >>m;
		for(int i = 0; i < m; i++) {
			int u, v;
			cin >>u >>v;
			g[u-1].pb(v-1);
			g[v-1].pb(u-1);
		}
		colo(0, 0);
		sort(ans.begin(), ans.end());
		cout <<ans.size() <<endl;
		for(int i : ans) cout <<i+1 <<' ';
		cout <<endl;
		for(int i = 0; i < N; i++) {
			g[i].clear();
		}
	}
    
    return 0;
}

