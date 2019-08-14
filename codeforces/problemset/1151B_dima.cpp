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

const int N = 505;
const int M = 1030;
int mat[N][N];
int dp[M][N];
vector<int> ans;
int n, m;
bool f = false;

int solve(int l, int v) {
	int &r = dp[l][v];
	if(l >= n) return r = v;

	if(r != -1) return r;
	
	int ans = 0;
	for(int i = 0; i < m; i++) {
		ans = max(ans, solve(l+1, v^mat[l][i]));
	}

	return r = ans;
}

void build(int l, int v) {
	if(l >= n) return;

	int ans = 0;
	for(int i = 0; i < m; i++) {
		ans = max(ans, solve(l+1, v^mat[l][i]));
	}
	for(int i = 0; i < m; i++) {
		if(solve(l+1, v^mat[l][i]) == ans) {
			cout <<i+1 <<' ';
			build(l+1, v^mat[l][i]);
			return;
		}
	}
}


int main() {
    ios_base::sync_with_stdio(false);

	cin >>n >>m;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >>mat[i][j];
		}
	}
	memset(dp, -1, sizeof dp);

	int ans = solve(0, 0);
	if(ans == 0) {
		cout <<"NIE" <<endl;
		return 0;
	}
	
	cout <<"TAK" <<endl;
	build(0, 0);

    return 0;
}

