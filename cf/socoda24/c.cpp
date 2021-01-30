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

int solve(ll s, ll x) {

	x = (s-x)/2LL;
	s /= 2LL;
	ll ans = 1LL;
	while(s > 0) {
		int b = x%2LL;
		if(!b) ans *= 2LL;
		x /= 2LL;
		s /= 2LL;
	}
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);

	ll s, x; cin >>s >>x;
	if(s-x < 0 or ((s-x)&1)) {
		cout <<0 <<endl;
		return 0;
	}

	if(x == 0) {
		cout <<1 <<endl;
		return 0;
	}

	cout <<solve(s, x) <<endl;

    return 0;
}

