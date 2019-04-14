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

const int N = 105;
int n, m;
int color[N];
bool visit[N];
vector<int> g[N];
vector<int> ans;

void solve(int at) {
	if(at == n) {
		int cont = 0;
		for(int i = 0; i < n; i++) {
			if(color[i] == 1) cont++;
		}
		if(cont > ans.size()) {
			ans.clear();
			for(int i = 0; i < n; i++) {
				if(color[i] == 1) ans.pb(i);
			}
		}
		return;
	}
	
	bool canBlack = true;
	for(int viz:g[at]) {
		if(color[viz] == 1) canBlack = false;
	}

	if(canBlack) {
		color[at] = 1;
		solve(at+1);
	}

	color[at] = 0;
	solve(at+1);
	
	return;
}

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;

	while(tc--) {
		cin >>n >>m;

		ans.clear();
		for(int i = 0; i < n; i++) {
			color[i] = 0;
			visit[i] = 0;
			g[i].clear();
		}

		for(int i = 0; i < m; i++) {
			int a, b; cin >>a >>b;
			g[a-1].pb(b-1);
			g[b-1].pb(a-1);
		}
		
		solve(0);
		
		cout <<ans.size() <<endl;
		for(int at:ans) {
			cout <<at+1 <<' ';
		}
		cout <<endl;
	}
    
    return 0;
}

