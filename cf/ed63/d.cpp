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

const int N = 3e5 + 5;
int n;
ll x, v[N];
ll dp[N][5];

ll solve(int at, int mod) {
	if(at >= n) return 0;
	
	ll &r = dp[at][mod];
	if(r != -1) return r;

	ll ans = 0;
	if(mod == 0) ans = max({solve(at+1, 0), v[at]+solve(at+1, 1), v[at]*x+solve(at+1, 2)});
	if(mod == 1) ans = max({v[at]+solve(at+1, 1), v[at]*x+solve(at+1, 2), 0LL});
	if(mod == 2) ans = max({v[at]*x+solve(at+1, 2), v[at]+solve(at+1, 3), 0LL});
	if(mod == 3) ans = max(v[at]+solve(at+1, 3), 0LL);

	return r = ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >>n >>x;
	for(int i = 0; i < n; i++) {
		cin >>v[i];
	}
	
	memset(dp, -1LL, sizeof dp);
	cout <<solve(0, 0) <<endl;

    return 0;
}

