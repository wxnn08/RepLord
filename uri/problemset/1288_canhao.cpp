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

const int N = 55;
const int M = 105;
int n;
int dp[N][M];
ii v[N];

int solve(int at, int cap) {
	if(cap < 0) return -INF;
	if(at >= n) return 0;

	int &r = dp[at][cap];
	if(~r) return r;

	int L = solve(at+1, cap-v[at].se) + v[at].fi;
	int R = solve(at+1, cap);
	return r = max(L, R);
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc; cin >>tc;
	while(tc--) {
		cin >>n;
		for(int i = 0; i < n; i++)
			cin >>v[i].fi >>v[i].se;

		int k, r;
		cin >>k >>r;
		memset(dp, -1, sizeof dp);
		int ans = solve(0, k);
		if(ans >= r) cout <<"Missao completada com sucesso" <<endl;
		else cout <<"Falha na missao" <<endl;
	}

	return 0;
}

