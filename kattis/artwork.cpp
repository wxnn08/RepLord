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

struct node {
	int d;
	bool color;
};

struct query {
	int a, b, c, d;
};

const int N = 1e3 + 5;
int n, m, q;
node mat[N][N];
stack<query> s;
int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};
bool visit[N*N];
int dad[N*N];
stack<int> s_ans;
int qtdG = 0;

void coloring(int a, int b, int c, int d) {
	if(a == c) {
		for(int i = b; i <= d; i++) {
			if(mat[i][a].color == 0) {
				mat[i][a].color = 1;
				mat[i][a].d = 1;
			} else {
				mat[i][a].d++;
			}
		}
	} else {
		for(int i = a; i <= c; i++) {
			if(mat[b][i].color == 0) {
				mat[b][i].color = 1;
				mat[b][i].d = 1;
			} else {
				mat[b][i].d++;
			}
		}
	}
	return;
}

void dfs(int i, int j, int d) {
	if(i < 0 or i >= n or j < 0 or j >= m) return;
	if(mat[i][j].color == 1 or visit[mat[i][j].d]) return;
	visit[mat[i][j].d] = true;
	dad[mat[i][j].d] = d;
	for(int k = 0; k < 4; k++) {
		dfs(i+mov[k][0], j+mov[k][1], d);
	}
	return;
}

bool valid(int i, int j) {
	if(i < 0 or i >= n or j < 0 or j >= m or mat[i][j].color == 1) return false;
	return true;
}

int find(int x) {
	if(x == dad[x]) return x;
	return dad[x] = find(dad[x]);
}

int join(int i, int j) {
	int ans = -1;
	vector<int> viz;
	for(int k = 0; k < 4; k++) {
		if(valid(i+mov[k][0], j+mov[k][1])) {
			if(find(mat[i][j].d) != find(mat[i+mov[k][0]][j+mov[k][1]].d)) {
				ans++;
				dad[find(mat[i][j].d)] = dad[find(mat[i+mov[k][0]][j+mov[k][1]].d)];
			}
		}
	}
	return ans;
}

void calc(query q) {
	int a = q.a, b = q.b, c = q.c, d = q.d;
	if(a == c) {
		for(int i = b; i <= d; i++) {
			if(mat[i][a].d == 1) {
				mat[i][a].color = 0;
				mat[i][a].d = i*m+a+1;
				int val = join(i, a);
				qtdG -= val;
			} else {
				mat[i][a].d--;
			}
		}
	} else {
		for(int i = a; i <= c; i++) {
			if(mat[b][i].d == 1) {
				mat[b][i].color = 0;
				mat[b][i].d = b*m+i+1;
				int val = join(b, i);
				qtdG -= val;
			} else {
				mat[b][i].d--;
			}
		}
	}
	return;
}

void print(int k) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(k == 0) cout <<(mat[i][j].color?'b':'w') <<' ';
			if(k == 1) cout <<dad[mat[i][j].d] <<' ';
			if(k == 2) cout <<mat[i][j].d <<' ';
		}
		cout <<endl;
	}
}

int main() {
	cin >>m >>n >>q;
	int cont = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			mat[i][j].color = 0;
			mat[i][j].d = cont++;
			dad[mat[i][j].d] = mat[i][j].d;
		}
	}

	while(q--) {
		int a, b, c, d;
		cin >>a >>b >>c >>d;
		s.push(query({a-1, b-1, c-1, d-1}));
		coloring(a-1, b-1, c-1, d-1);
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(mat[i][j].color == 0 and !visit[mat[i][j].d]) {
				dfs(i, j, mat[i][j].d);
				qtdG++;
			}
		}
	}
	
	s_ans.push(qtdG);
	while(!s.empty()) {
		query q = s.top();
		s.pop();
		calc(q);
		s_ans.push(qtdG);
	}
	
	bool first = true;
	while(!s_ans.empty()) {
		if(!first) {
			cout <<s_ans.top() <<endl;
		}
		first = false;
		s_ans.pop();
	}
	return 0;
}

