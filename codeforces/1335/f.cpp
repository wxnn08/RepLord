#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n, m;
vector<vector<int>> colors, cycles, visit;
vector<vector<ii>> dirs;

int findCycleSize(int l, int c, int v) {
	visit[l][c]++;
	if(visit[l][c] == 2) cycles[l][c] = v;

	int nl = l+dirs[l][c].fi;
	int nc = c+dirs[l][c].se;
	if(visit[nl][nc] == 0) return findCycleSize(nl, nc, 0);
	if(visit[nl][nc] == 1) return findCycleSize(nl, nc, v+1);
	if(visit[l][c] == 2 and visit[nl][nc] == 2) return cycles[l][c] - cycles[nl][nc] + 1;
	else return 0;
}
 
int main() {
    ios_base::sync_with_stdio(false);

	int tc; cin >>tc;
	while(tc--) {
		cin >>n >>m;

		for(int i = 0; i < colors.size(); i++) {
			colors[i].clear();
			cycles[i].clear();
			visit[i].clear();
			dirs[i].clear();
		}
		colors.clear();
		cycles.clear();
		visit.clear();
		dirs.clear();

		colors.resize(n, vector<int>(m));
		cycles.resize(n, vector<int>(m));
		visit.resize(n, vector<int>(m));
		dirs.resize(n, vector<ii>(m));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				char c; cin >>c;
				colors[i][j] = (c-'0');
			}
		}

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				char d; cin >>d;
				if(d == 'R') dirs[i][j] = mk(0, +1);
				if(d == 'L') dirs[i][j] = mk(0, -1);
				if(d == 'U') dirs[i][j] = mk(-1, 0);
				if(d == 'D') dirs[i][j] = mk(+1, 0);
			}
		}
		
		int ans1 = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(visit[i][j] == 0) ans1 += findCycleSize(i, j, 0);
			}
		}

		// Nesse ponto os nós dos ciclos estão marcados com números
		

	}

    return 0;
}

