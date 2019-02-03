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

const ll MINVAL = -1e12;
const int N = 1e5+5;
vector<int> g[N];
bool visit[N];
ll w[N];
ll dp[N][2];

ll solve(int at, bool pai) {
	
	int n = g[at].size();
	int t;
	for(int i = 0; i < n; i++) {
		int viz = g[at][i];
		if(w[at] >= 0) 
			t = max(
	}
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >>u >>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}

	for(int i = 0; i < n; i++) 
		cin >>w[i];
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < 2; j++) {
			dp[i][j] = MINVAL;
		}
	}

	cout <<solve(0, false) <<endl;
    
    return 0;
}
