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

const int N = 4e2 + 5;
int n, m;
int g[N][N];
bool vis[N];

int djk(int k) {

	int dist[N];
	memset(dist, INF, sizeof dist);
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	dist[1] = 0;
	pq.push(ii(dist[1], 1));
	
	while(!pq.empty()) {
		int at = pq.top().sec;
		pq.pop();
		if(vis[at]) continue;
		vis[at] = true;
		
		if(at == n) return dist[at];

		for(int i = 1; i <= n; i++) {
			if(g[at][i] == k and dist[i] > dist[at] + 1) {
				dist[i] = dist[at] + 1;
				pq.push(ii(dist[i],i));
			}
		}
	}

	return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int k = 1;
	cin >>n >>m;
	fori(i,0,m) {
		int v, u;
		cin >>v >>u;
		g[v][u] = 1;
		g[u][v] = 1;
		if((v == 1 and u == n) or (u == 1 and v == n)) k = 0;
	}
    
	cout <<djk(k) <<endl;
    return 0;
}

