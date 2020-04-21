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

const int N = 1e4 + 5;
vector<ii> g[N];
int n, m;

int dijkstra(int ori, int dest){
	ii dist[N];
	for(int i=1; i <= n; i++) dist[i] = mk(INF, INF);
	dist[1] = mk(0,INF);
	
	priority_queue <ii, vector<ii>, greater<ii> > pq;
	pq.emplace(0, 1);

	while(!pq.empty()){
		int at = pq.top().sec;
		int d = pq.top().fi;
		pq.pop();
	
		if(d > dist[at].fi and d > dist[at].sec) continue;

		for(int i = 0; i < g[at].size(); i++) {
			int viz = g[at][i].fi;
			int p = g[at][i].sec;

			if(dist[at].fi + p < dist[viz].sec) {
				dist[viz].sec = dist[at].fi + p;
				pq.emplace(dist[viz].sec, viz);
			}

			if(dist[at].sec + p < dist[viz].fi) {
				dist[viz].fi = dist[at].sec + p;
				pq.emplace(dist[viz].fi, viz);
			}
		}
	}
	
	if(dist[dest].fi == INF) return -1;
	return dist[dest].fi;
}

int main(){
    ios_base::sync_with_stdio(false);

	cin >>n >>m;

	fori(i,0,m) {
		int u, v, p;
		cin >>u >>v >>p;
		g[u].eb(v,p);
		g[v].eb(u,p);
	}

	cout <<dijkstra(1, n) <<endl;
    
    return 0;
}

