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

const int N = 30;
int v[N];
vector<int> g[N];

int calc(int ini) {
	
	int dist[N];
	memset(dist, -INF, sizeof dist);
	dist[ini] = 0;

	for(int i = 0; i < N-1; i++) {
		for(int u = 0; u < N; u++) {
			for(auto at:g[u])
				dist[at] = max(dist[at], dist[u] + v[at]);
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++) 
		ans = max(ans, dist[i]);
	return ans;
}

int main() {
	int tc;
	cin >>tc;
	getchar();
	getchar();
	while(tc--) {
		for(int i  = 0; i < N; i++) g[i].clear();
		memset(v, 0, sizeof v);

		string in;
		while(true) {
			getline(cin, in);
			if(in == "") break;
			char c = in[0];
			int k = 2;
			for(k = 2; in[k] >= '0' and in[k] <= '9'; k++) {
				v[c-'A'+1] *= 10;
				v[c-'A'+1] += (in[k]-'0');
			}
			bool has = false;
			while(++k < in.size()) {
				has = true;
				g[in[k]-'A'+1].pb(c-'A'+1);
			}
			if(!has) {
				g[0].pb(c-'A'+1);
			}
		}

		cout <<calc(0) <<endl;
		if(tc) cout <<endl;
	}
	
	return 0;
}

