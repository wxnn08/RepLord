#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 20;
const int M = 1e6;
ll bonus[N][N];
ll v[N];
ll dp[N][M];
int n, m, k;

ll solve(int at, int mask, int cont) {
	if(cont == m) 
		return 0;

	ll &r = dp[at][mask];
	if(r != -1) return r;
	
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		if(mask&(1<<i)) continue;
		ans = max(ans, solve(i, mask|(1<<i), cont+1) + v[i] + bonus[at][i]);
	}

	return r = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
	
	cin >>n >>m >>k;
	for(int i = 1; i <= n; i++) {
		cin >>v[i];
	}

	for(int i = 0; i < k; i++) {
		int a, b;
		ll c;
		cin >>a >>b >>c;
		bonus[a][b] = max(bonus[a][b], c);
	}
	
	memset(dp, -1, sizeof(dp));
	cout <<solve(0, 0, 0) <<endl;

    return 0;
}

