#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 205;
int memo[N][N];
 
ll poss(int maxH, int n) {
	if(n == 0) return 1;
	if(maxH == 0) return 0;
	
	int &r = memo[maxH][n];
	if(r != -1) return r;

	ll ans = 0;
	for(int i = 1; i <= memoH and i <= n; i++) {
		ans += poss(i-1, n-i);
	}

}

int main() {
    ios_base::sync_with_stdio(false);

	memset(memo, -1, sizeof memo);
	

    return 0;
}

