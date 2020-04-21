#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int MAXN = 1e5 + 5;
const int MAXM = 9e5 + 5;

int ned, first[MAXN], work[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM], dist[MAXM];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

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

int toNode(int i, int j, int n) {
	return i*n+j+1;
}

int main() {
	ios_base::sync_with_stdio(false);

	string mat[50];

	int tc;
	cin >>tc;
	while(tc--) {
		init();

		int n, m, total = 0;
		cin >>n >>m;

		for(int i = 0; i < n; i++) {
			cin >>mat[i];
			for(int j = 0; j < m; j++) 
				if(mat[i][j] == '*') total++;
		}

		int s = 0, t = n*n*m+5;
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < m; j++) {
				if(mat[i][j] == 'o') continue;
				if((i%2+j%2)%2 == 0) {
					add(s, toNode(i, j, n), 1);
					for(int k = 0; k < 4; k++) {
						int ii = i+dx[k];
						int jj = j+dy[k];
						if(ii < 0 or jj < 0 or ii >= n or jj >= m) continue;
						if(mat[ii][jj] == 'o') continue;
						add(toNode(i, j, n), toNode(ii, jj, n), 1);
					}
				}
				else add(toNode(i, j, n), t, 1);
			}

		int ans = dinic(s, t);
		cout <<ans+(total-2*ans) <<endl;

	}
	
	return 0;
}

