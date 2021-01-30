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

struct edge {
	int a, b, cost;
};

int n;
int pai[N];
int qtd[N];
vector<edge> v;
vector<int> g[N];
int tracker[N];
bool visit[N];

int find(int x) {
	if(x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y) {
	int a = find(x);
	int b = find(y);
	if(qtd[a] > qtd[b]) swap(a,b);
	qtd[b] += qtd[a];
	pai[a] = pai[b];
}

int mst() {
	sort(v.begin(), v.end(), [](const edge &a, const edge &b) {return a.cost > b.cost;});

	for(int i = 1; i <= n; i++) {
		pai[i] = i;
		qtd[i] = 1;
	}
	
	int ans = 0;
	for(auto at:v) {
		if(find(at.a) != find(at.b)) {
			g[at.a].pb(at.b);
			g[at.b].pb(at.a);
			join(at.a, at.b);
			ans += at.cost;
		}
	}

	return ans;
}

void dfs(int at, int dad) {
	tracker[at] = dad;
	visit[at] = true;
	for(int viz:g[at]) {
		if(!visit[viz]) dfs(viz, at);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >>n;
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			int aux; cin >>aux;
			v.pb(edge({i, j, aux}));
		}
	}

	cout <<mst() <<endl;
	dfs(1, -1);
	
	for(int i = 2; i <= n; i++) {
		cout <<tracker[i] <<endl;
	}

	return 0;
}

