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
 
int secondShorterPath(int ini, int dest) {
	
	vector<int> dist[N];
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.emplace(0, ini);

	while(!pq.empty()) {
		int at = pq.top().se;
		int w = pq.top().fi;
		pq.pop();

		if(dist[at].size() >= 2) continue;

		if(dist[at].size() == 0) dist[at].pb(w);
		else if(dist[at].back() != w) dist[at].pb(w);

		for(auto viz:g[at]) {
			if(dist[viz.fi].size() >= 2) continue;
			pq.emplace(w + viz.se, viz.fi);
		}
	}
	if(dist[dest].size() < 2) return -1;
	return dist[dest][1];
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, r;
	int tc = 1;
	while(cin >>n >>r) {
		
		for(int i = 0; i < n; i++) g[i].clear();
		for(int i = 0; i < r; i++) {
			int a, b, w;
			cin >>a >>b >>w;
			g[a].eb(b,w);
			g[b].eb(a,w);
		}
		int q; cin >>q;
		cout <<"Set #" <<tc++ <<endl;
		while(q--) {
			int a, b;
			cin >>a >>b;
			int path = secondShorterPath(a, b);
			if(path < 0) cout <<"?" <<endl;
			else cout <<path <<endl;
		}
	}
	
	return 0;
}

