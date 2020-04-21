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
int n, c;
int v[N];
int dp[N][2];

int solve(int pos, int seq) {
	if(pos >= n) return 0;
	int &r = dp[pos][seq];
	if(~r) return r;
	int L = solve(pos+1, 1) + v[pos] - c;
	int R = (seq == 1? 0 : solve(pos+1, 0));
	return r = max(L,R);
}

int main() {
	ios_base::sync_with_stdio(false);
	
	while(cin >>n >>c) {
		for(int i = 0; i < n; i++) cin >>v[i];
		memset(dp, -1, sizeof dp);
		cout <<solve(0, 0) <<endl;
	}

	return 0;
}

