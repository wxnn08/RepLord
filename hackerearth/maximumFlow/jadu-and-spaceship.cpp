/* O nosso maior medo não é sermos inadequados.
O nosso maior medo é sermos infinitamente poderosos.
É a nossa própria luz, não a nossa escuridão, que nos amedronta.
Sermos pequenos não engrandece o mundo.
Não há nada de transcendente em sermos pequenos,
pois assim os outros não se sentirão inseguros ao nosso lado.
Todos estamos destinados a brilhar, como as crianças.
Não apenas alguns de nós, mas todos.
E, enquanto irradiamos a nossa admirável luz interior,
inconscientemente estamos a permitir aos outros fazer o mesmo.
E, quando nos libertarmos dos nossos próprios medos,
a nossa presença automaticamente libertará os medos dos outros.  */

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
 
// -- DINIC init
const int MAXN = 1e6 + 5;
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
		if(dist[v] == dist[u]+1 and cap[e] > 0) {
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
		while(f = dfs(s, INF, s, t))
			result += f;
	}
	return result;
}
// -- DINIC end

const int M = 1e5+5;
const int N = 1e3 + 5;
vector<int> primes;
bool visit[M];

void sieve(int m) {
	for(int i = 2; i <= m; i++) {
		if(visit[i]) continue;
		primes.pb(i);
		for(int j = i+i; j <= m; j += i) 
			visit[j]  = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;
	init();
	sieve(m);

	int v[N];
	vector<int> fats[N];
	map<int, int> id;
	int cont = n+1;
	for(int i = 1; i <= n; i++) {
		cin >>v[i];
		add(0, i, 1);

		int at = v[i];
		for(auto prime:primes) {
			if(at%prime == 0) {
				fats[i].pb(prime); 
				if(!id.count(prime)) id[prime] = cont++;
			}
			while(at%prime == 0) at /= prime;
		}
	}

	set<int> alreadyAdd;
	for(int i = 1; i <= n; i++) {
		for(auto fat:fats[i]) {
			add(i, id[fat], 1);
			if(!alreadyAdd.count(id[fat])) {
				add(id[fat], cont, 1);
				alreadyAdd.insert(id[fat]);
			}
		}
	}
	
	cout <<dinic(0, cont) <<endl;

	return 0;
}

