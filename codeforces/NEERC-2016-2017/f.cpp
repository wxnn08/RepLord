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
#define each(x, xs) for (auto& x : xs)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
struct graph {
	int size;
	vi ent, sai;
	vector<list<int>> adj;
	vector<list<int>> eq;
	graph(int n) : size(n) {
		adj.resize(n);
		eq.resize(n);
		ent.resize(n, 0);
		sai.resize(n, 0);
	}
	void addEdge(int a, int b, char c) {
		if (c == '=') eq[a].pb(b), eq[b].pb(a);
		if (c == '<') swap(a, b);
		adj[a].pb(b);
		ent[b]++;
		sai[a]++;
	}
};

void dfs(graph& g, int i, char c, string& s) {
	s[i] = c;
	each(x, g.eq[i]) {
		if (s[x] == '?') {
			dfs(g, x, c, s);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	#ifndef STEVE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;
	graph g(n);
	int a, b;
	string in;
	for (int i = 0;i < m;i++) {
		cin >> in;
		int x = min({in.find('<'), in.find('='), in.find('>')});
		int l = in.length();
		a = stoi(in.substr(0, l - x));
		b = stoi(in.substr(x + 1));
		g.addEdge(a - 1, b - 1, in[x]);
	}
	string s(n, '?');
	for (int i = 0;i < n;i++) if (g.ent[i] && g.sai[i]) s[i] = 'R';
	for (int i = 0;i < n;i++) {
		if (s[i] == 'R') {
			dfs(g, i, 'R', s);
		}
	}
	for (int i = 0;i < n;i++) {
		if (s[i] == 'R') each(x, g.adj[i]) s[x] = 'B';
		else each(x, g.adj[i]) if (s[x] == 'R') {s[i] = 'W';continue;}
	}
	for (int i = 0;i < n;i++) if (s[i] == 'W' or s[i] == 'B') dfs(g, i, s[i], s);
	cout << s << endl;
	return 0;
}

