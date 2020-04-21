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

struct node {
	ll v;
	char dir;
};

int n, m;
node mat[N][N];
int vis[N][N];
bool cic[N][N];

ll setaCiclo(int l, int c, int cont) {
	if(cic[l][c]) return cont;
	cic[l][c] = true;

	ll ans;
	node &e = mat[l][c];
	if(e.dir == 'N') ans = setaCiclo(l-1, c, cont+1);
	if(e.dir == 'S') ans = setaCiclo(l+1, c, cont+1);
	if(e.dir == 'E') ans = setaCiclo(l, c+1, cont+1);
	if(e.dir == 'W') ans = setaCiclo(l, c-1, cont+1);
	
	return e.v = ans;
}

ll dfs(int l, int c, int tempo, int cont) {
	if(l < 0 or c < 0 or l >= n or c >= m) return 0;

	if(vis[l][c] == tempo) {
		return setaCiclo(l, c, 0);
	}
	vis[l][c] = tempo;

	ll ans;
	node &e = mat[l][c];
	if(e.v != 0) return mat[l][c].v;
	if(e.dir == 'N') ans = dfs(l-1, c, tempo, cont+1);
	if(e.dir == 'S') ans = dfs(l+1, c, tempo, cont+1);
	if(e.dir == 'E') ans = dfs(l, c+1, tempo, cont+1);
	if(e.dir == 'W') ans = dfs(l, c-1, tempo, cont+1);
	
	return (e.v == 0? e.v = ans+1: e.v);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >>n >>m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >>mat[i][j].dir;
		}
	}
	
	int tempo = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(vis[i][j] == 0) {
				dfs(i, j, tempo++, 0);
			}
		}
	}

	ll sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			//cout <<mat[i][j].v <<' ';
			sum += mat[i][j].v;
		}
		//cout <<endl;
	}
    
	cout <<sum <<endl;
    return 0;
}

