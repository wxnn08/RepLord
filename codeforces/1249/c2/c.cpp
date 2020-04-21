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

int main() {
	ios_base::sync_with_stdio(false);

	int tc; cin >>tc;
	while(tc--) {
		ll base = 1LL;
		ll ans = 0;
		ll n; cin >>n;
		while(ans < n) ans += base, base *= 3LL;
		base /= 3LL;
		while(base > 0LL) {
			if(ans - base >= n) ans -= base;
			base /= 3LL;
		}
		cout <<ans <<endl;
	}
	
	return 0;
}

