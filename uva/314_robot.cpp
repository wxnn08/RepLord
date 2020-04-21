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

struct Node { int r, c, dir, p; };

const int N = 55;
int n, m;
bool visit[N][N][5];
bool mat[N][N];

bool possible(int r, int c) {
	if(r < 0 or c < 0 or r >= n or c >= m) return false;
	return !(mat[r][c] or mat[r+1][c] or mat[r][c+1] or mat[r+1][c+1]);
}

int solve(int r, int c, int rf, int cf, int dir) {
	
	if(!possible(r, c)) return -1;
	if(r == cf and c == cf) return 0;

	memset(visit, 0, sizeof visit);
	queue<Node> q;
	q.push({r, c, dir, 0});
	visit[r][c][dir] = true;

	while(!q.empty()) {
		Node at = q.front();
		q.pop();

		if(at.r == rf and at.c == cf) return at.p;

		for(int i = 1; i <= 3; i++) {
			int rn = at.r + ((at.dir == 2) * i) - ((at.dir == 0) * i);
			int cn = at.c + ((at.dir == 1) * i) - ((at.dir == 3) * i);
			if(!possible(rn, cn)) break;
			if(visit[rn][cn][at.dir]) continue;
			q.push({rn, cn, at.dir, at.p + 1});
			visit[rn][cn][at.dir] = true;
		}

		for(int i = 0; i < 4; i++) {
			if(visit[at.r][at.c][i]) continue;
			if(i == (at.dir+2)%4) continue;
			q.push({at.r, at.c, i, at.p + 1});
			visit[at.r][at.c][i] = true;
		}
	}
	
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	while(cin >>n >>m) {
		if(n == 0 and m == 0) return 0;
		
		memset(mat, 1, sizeof mat);
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < m; j++) 
				cin >>mat[i][j];

		int ri, ci, rf, cf;
		string s;
		map<char, int> dir;
		dir['n'] = 0;
		dir['e'] = 1;
		dir['s'] = 2;
		dir['w'] = 3;

		cin >>ri >>ci >>rf >>cf >>s;
		cout <<solve(ri-1, ci-1, rf-1, cf-1, dir[s[0]]) <<endl;
	}

	return 0;
}

