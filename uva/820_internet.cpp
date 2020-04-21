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

const int MAXN = 1e5 + 5;
const int MAXM = 9e5 + 5;
int ned, first[MAXN], work[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM], dist[MAXN];

void init() {
	memset(first, -1, sizeof first);
	ned = 0;
}

void add(int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs(int u, int f, int s, int t) {
	if(u == t) return f;
	int v, df;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		v = to[e];
		if(dist[v] == dist[u] + 1 and cap[e] > 0) {
			df = dfs(v, min(f, cap[e]), s, t);
			if(df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t) {
	int u, v;
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	queue<int> q; q.push(s);
	while(!q.empty()) {
		u = q.front(); q.pop();
		for(int e = first[u]; e != -1; e = nxt[e]) {
			v = to[e];
			if(dist[v] < 0 and cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return dist[t] >= 0;
}

int dinic(int s, int t) {
	int result = 0, f;
	while(bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while(f = dfs(s, INF, s, t)) result += f;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	int cont = 1;
	while(cin >>n) {
		if(n == 0) break;
		init();
		int s, t, c;
		cin >>s >>t >>c;

		for(int i = 0; i < c; i++) {
			int u, v, w;
			cin >>u >>v >>w;
			add(u, v, w);
			add(v, u, w);
		}

		cout <<"Network " <<cont++ <<endl;
		cout <<"The bandwidth is " <<dinic(s, t) <<"." <<endl <<endl;
	}
	
	return 0;
}

