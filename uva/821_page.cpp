#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 105;
int dist[N][N];

int main() {
	int tc = 1;
	int u, v;
	while(scanf("%d %d", &u, &v)) {
		if(u == 0 and v == 0) break;

		vector<int> vs;
		memset(dist, INF, sizeof dist);

		do {
			if(v == 0 and u == 0) break;
			vs.pb(u);
			vs.pb(v);
			dist[u][v] = 1;
			dist[u][u] = 0;
			dist[v][v] = 0;
		} while(scanf("%d %d", &u, &v));
		
		sort(vs.begin(), vs.end());
		vs.resize(unique(vs.begin(), vs.end()) - vs.begin());

		for(auto k:vs) 
			for(auto i:vs) 
				for(auto j:vs) 
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		double ans = 0;
		for(auto i:vs) 
			for(auto j:vs) {
				ans += dist[i][j];
			}
				

		int n = vs.size();
		ans = (ans/(n*(n-1)));
		printf("Case %d: average length between pages = %.3lf clicks\n", tc++, ans);
	}
	
	return 0;
}

