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

int main() {
	ios_base::sync_with_stdio(false);

	ll l, r, x, y;
	cin >>l >>r >>x >>y;
	const int N = 31;
	
	while(x < N) {
		ll n = x*y;
		ll ans = 0;
		cout <<x <<',' <<y <<" = ";
		for(ll i = l; i < n; i++) {
			if(n%i == 0 and __gcd(i, n/i) == x and n/__gcd(i, n/i) == y)
				cout <<i <<' ' <<n/i <<", ";
		}
		cout <<endl;
		y++;
		if(y == N) x++, y = x;
	}
	return 0;
}

