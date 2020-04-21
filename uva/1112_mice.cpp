/* Aí, você já parou pra pensar, por que que você vive?
 * O que é que te move?
 * Aquele momento que decodifica o segredo da sua alma
 * E de repente tudo começa a fazer sentido.
 * É um chamado legítimo que vem lá do íntimo 
 * É quando a poesia entra em sincronia com o ritmo 
 * E te faz pensar 
 * Se não fosse isso eu podia até respirar, mas vivo eu também não ia tá!
 */
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
vector<ii> g[N];
int dist[N];
bool visit[N];

void dij(int ini) {
	
	memset(dist, INF, sizeof dist);
	memset(visit, 0, sizeof visit);
	priority_queue<ii, vector<ii>, greater<ii>> pq;

	dist[ini] = 0;
	pq.emplace(dist[ini], ini);

	while(!pq.empty()) {
		int at = pq.top().se;
		int w = pq.top().fi;
		pq.pop();
		if(visit[at]) continue;
		visit[at] = true;
		
		for(auto viz:g[at]) {
			if(dist[viz.fi] > dist[at]+viz.se) {
				dist[viz.fi] = dist[at]+viz.se;
				pq.emplace(dist[viz.fi], viz.fi);
			}
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;
	while(tc--) {
		int n, e, t, m;
		cin >>n >>e >>t >>m;

		for(int i = 1; i <= n; i++) 
			g[i].clear();

		for(int i = 0; i < m; i++) {
			int a, b, w;
			cin >>a >>b >>w;
			g[b].eb(a, w);
		}
		
		dij(e);
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			if(dist[i] <= t) ans++;
		}
		cout <<ans <<endl;
		if(tc) cout <<endl;
	}
	
	return 0;
}

