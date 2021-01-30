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

const int N = 2e5 + 5;

int main() {
	ios_base::sync_with_stdio(false);

	vector<int> ai, bi;
	int dp[N][2];
	int n, c;
	cin >>n >>c;
	for(int i = 0; i < n-1; i++) {
		int a; cin >>a;
		ai.pb(a);
	}

	for(int i = 0; i < n-1; i++) {
		int b; cin >>b;
		bi.pb(b);
	}

	dp[0][0] = 0;
	dp[0][1] = c;

	for(int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + ai[i-1];
		dp[i][1] = min(dp[i-1][0]+c, dp[i-1][1]) + bi[i-1];
	}

	for(int i = 0; i < n; i++) 
		cout <<min(dp[i][0], dp[i][1]) <<' ';
	cout <<endl;
	
	return 0;
}

