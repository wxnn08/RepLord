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

const int N = 27;
const int M = 1e6 + 5;
int n, tempo = 0;
int v[N];
int dp[N][M];

int main() {
	ios_base::sync_with_stdio(false);

	int tc; cin >>tc;
	while(tc--) {
		int m;
		cin >>n >>m;
		for(int i = 0; i < n; i++) cin >>v[i];

		memset(dp, INF, sizeof dp);
		for(int i = 0; i < n; i++) dp[i][0] = 0;

		for(int i = 1; i <= m; i++) {
			for(int j = 0; j < n; j++) {
				if(i - v[j] < 0) continue;
				dp[i][j] = min({dp[i][j], 1+dp[i-v[j]][j]
			}
		}
	}
	
	return 0;
}

