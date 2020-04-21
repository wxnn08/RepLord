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
 
const int N = 1e3 + 5;
vector<ii> g[N];

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;
	while(tc--) {
		int n, m;
		cin >>n >>m;
		for(int i = 0; i < n; i++) 
			g[i].clear();
		for(int i = 0; i < m; i++) {
			int a, b, w;
			cin >>a >>b >>w;
			g[a].eb(b,w);
		}
		
		int dist[N];
		memset(dist, INF, sizeof dist);
		dist[0] = 0;
		for(int i = 0; i < n; i++) 
			for(int u = 0; u < n; u++) 
				for(auto at:g[u]) 
					dist[at.fi] = min(dist[at.fi], dist[u]+at.se);

		bool possible = false;
		for(int u = 0; u < n; u++) 
			for(auto at:g[u]) 
				possible |= dist[at.fi] > dist[u]+at.se;
		
		cout <<(possible?"possible":"not possible") <<endl;

	}
	
	return 0;
}

